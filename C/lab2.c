/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~EMPLOYEE DATABASE SYSTEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~This is Sp-Lab-2 submission for CS402 by Kayenat Patil at 11/18/2021 at Illinois Tech~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~In this code various meaningful fucntions are written to execute the code and understand it.~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"

void new(char *filename)
{
//Brings file into structure of Araay, makes it easier to use and manipulate data and retain the original txt file.
    records = 0;
    fptr = fopen(filename,"r");
    while (fscanf(fptr, "%d %s %s %d", &emparr[records].id, emparr[records].first_name, emparr[records].last_name, &emparr[records].salary) != EOF) //fscanf function fetches the data from the file
    {                                                                                                                                                                                                                                           //and stores it in a structure untill the End of file is reached(EOF)
       records++;
   }
   close_file(fptr);
}
void menu(char *filename)
{
//Displays menu with new functions added
	while (num !=5)
	{
		printf("--------------------------------------\n");
		printf("Employee Database:\n");
		printf("--------------------------------------\n");
		printf("   (1) Print the Database\n   (2) Lookup by ID\n   (3) Lookup by Last Name\n   (4) Add an Employee\n   (5) Quit\n   (6) Remove an Employee\n   (7) Update Employee's Information\n   (8) Print the M employees with the highest salaries\n   (9) Find all employees with matching last name\n");
		printf("--------------------------------------\n");
		printf("Enter your choice:");
		scanf("%d",&num);
		printf("--------------------------------------\n");


		switch (num) 
		{
			case 1: 
			{
				display_database(filename);
				break;
			}

			case 2:
			{
				printf("Enter Employee ID: ");
				scanf("%d", &emp_id);
				if ((emp.id < 100000) || (emp.id > 999999))
				{
					printf("Invalid Id, please try again\n");
					break;
				}

				id_finder(filename, emp_id); 
				break;
			}

			case 3:
			{
				printf("Enter Lastname of Employee: ");
				scanf("%s", emplname);
				lastname_finder(filename,emplname);
				break;
			}

			case 4:
			{
				add_employee(filename);
				break;
			}

			case 5:
			{
				printf("Thank you & Have a good day!\n");
				break;
				exit(0);
			}

            case 6:
            //NEW
            //Prompts user to enter ID to delete and calls the function to delete the record.
            //I have used array as a structure, so that all changes are done in array and not the file.
            //If the program is reinitialized, all lost data is regained and all the newly added data is lost.
            {
                printf("Enter the employee Id: ");
                scanf("%d", &emp_id);
                remove_employee(emp_id);
                break;
            }

            case 7:
            //Prompts user to enter ID for updating employee and then calls the update function.
            {
                printf("Enter the employee Id: ");
                scanf("%d", &emp_id);
                update_employee(emp_id);
                break;
            }

            case 8:
            //Calls the function to get M highest salaries.
            {
                Msalary(filename);
                break;
            }

            case 9:
            {
                //Calls function to return multiple names of same last name
                matching_name(filename);
                break;
            }


			default:
			{
                //If any number but 1-9 is entered, this error message is displayed.
				printf("ERROR! Please try again!\n");
				break;
			}
		} 
	}
}

void id_finder(char *filename, int emp_id)
{
//This function takes the user input from menu and finds if the given id exists in the database
  fptr = fopen(filename, "r");
  //fptr = open_file(filename, "r");
  while(fscanf(fptr, "%d %s %s %d", &emp.id, emp.first_name, emp.last_name, &emp.salary) != EOF)
  {

    if (emp_id == emp.id)
     {
      	printf("-------------------------------------------------------------------------\n");
        printf("Name\t\t\t\tSalary\t\t ID\n");
        printf("--------------------------------------------------------------------------\n");
        printf("%-10s \t %-10s \t %d \t\t %d\n", emp.first_name, emp.last_name, emp.salary, emp.id);
        printf("--------------------------------------------------------------------------\n");
		found_id = 1;
        break;
      }
  }

	if (found_id == 0)
	{
		printf("Employee not in database \n");
	}
   close_file(fptr);
}

void display_database(char *filename)
{
//This function displays the latest database that has been saved in the text file 
	fptr = fopen(filename, "r");
    printf("----------------------------------------------------------------------------\n");
	printf("Name\t\t\t\tSalary\t\t  ID\n");
	printf("----------------------------------------------------------------------------\n");
   for (int i = 0; i < records; i++)
   {
      printf("%-10s %-10s\t\t%d\t\t%d\n", emparr[i].first_name, emparr[i].last_name, emparr[i].salary, emparr[i].id);
   }
   printf("\n---------------------------------------------------------------------------\n");
   printf("\nNumber of Employees (%d) \n", records);
   close_file(fptr);
}

void lastname_finder(char *filename, char *emplname)
{
//This function takes in the last name from the user and finds the record that has the same last name

	fptr = fopen(filename, "r");
	found_ln=0; 

	while(fscanf(fptr, "%d %s %s %d", &emp.id, emp.first_name, emp.last_name, &emp.salary) != EOF)
	{
		if (strcasecmp(emp.last_name,emplname) == 0)
		{
      	printf("-------------------------------------------------------------------------\n");
        printf("Name\t\t\t\t\tSalary\t\t\tID\n");
        printf("--------------------------------------------------------------------------\n");
        printf("%-10s\t%-10s\t\t%d\t\t\t%d \n", emp.first_name, emp.last_name, emp.salary, emp.id);
        printf("--------------------------------------------------------------------------\n");
		found_ln = 1;
        break;
		}
	}

		if (found_ln == 0)
		{
			printf("Employee not is Database\n");
		}
	
	close_file(fptr);
}

void add_employee(char *filename)
{
//Adds employee data and dynamicly assigns the largest value as Id to the new entry 
	char *maxptr = filename; 
	fptr = fopen(filename, "r+");
	printf("Enter Firstname: ");
	scanf("%s",emp.first_name);
	printf("Enter Lastname: ");
	scanf("%s",emp.last_name);
	printf("Enter Salary: ");
	scanf("%d", &emp.salary);

	if ((emp.salary<30000) || (emp.salary>150000))
	{
		printf("Invalid Salary, Try again\n");
		printf("-------------------------------------------------------------------------\n");
		add_employee(filename);
	}
	printf("-------------------------------------------------------------------------\n");

	printf("Please check the record: \n");
	printf("%s %s %d", emp.first_name, emp.last_name, emp.salary);
	printf("\nDo you want to proceed?\nPress 1 for YES\nPress 0 for NO\nYour choice: ");
	scanf("%d",&num);
	printf("%d", emp.id);
	if(num == 1)
	{
		emp.id = largest_id(maxptr)+1;
		fseek(fptr, 0, SEEK_END);
		//printf("c1");
		fprintf(fptr, "\n");
		fprintf(fptr, "%d %s %s %d", emp.id, emp.first_name, emp.last_name, emp.salary);
		//printf("c2");
		printf("-------------------------------------------------------------------------\n");
		printf("Record added Successfully\n");
		fclose(fptr);
		//close_file(fptr);
		
	}
	else
	{
		printf("-------------------------------------------------------------------------\n");
		printf("No change was made\n");
	}
	//close_file(fptr);
}

int largest_id(char *maxptr)
{
//finds the largest value of id and return it
	FILE *fp;
	int max=0;
	fp= fopen(maxptr, "r");
	while(fscanf(fp, "%d %s %s %d", &emp1.id, emp1.first_name, emp1.last_name, &emp1.salary) != EOF)
    {
            if (emp1.id > max)
                max = emp1.id;
    }
	//close_file(fp);
	return max;
}
//NEW
void remove_employee(int emp_id)
{

//Removing an employee is implemented here   
int i=0, t=0, j;
   for(j=0; j<records; j++)
   {
      if (emp_id == emparr[j].id) // checks for employee in DB
      {
         t = j;// stores the location of the record in t, so as to avoid travering the same data multiple times.
      }
   }
   if (t>0)//If record is found, it displys a confirmation message to verify that this employee will be delete
   {
      	printf("--------------------------------------------------------------------------\n");
        printf("Name\t\t\t\t\tSalary\t\t\tID\n");
        printf("--------------------------------------------------------------------------\n");
        printf("%-10s\t%-10s\t\t%d\t\t\t%d \n", emparr[t].first_name, emparr[t].last_name, emparr[t].salary, emparr[t].id);
        printf("--------------------------------------------------------------------------\n");//Displays name, salary and Id of the employee
        printf("Delete Employee: \nPress 1 for YES \nPress 0 for NO \nYour Choice :");// Asks for confirmation
        scanf("%d", &choice);
      if (choice== 1)
      {
         for (i = t; i < records - 1; i++)
         {
            emparr[i] = emparr[i+1];// changes pointer and makes it jump from the employee, hence deleted it. 
         }
         records--;
         printf("--------------------------------------------------------------------------\n");
         printf("Record Deleted\n");// confirms action
         printf("--------------------------------------------------------------------------\n");
      }
      else
      {
        printf("--------------------------------------------------------------------------\n");
        printf("No changes were made\n");// confirms action
      }
   }
   else
   {
      printf("Employee not found\n");//If record is not found, displays message
   }
}

void update_employee(int emp_id)
{
//Employee record is updated here
    int j, k=0;
    num=1;
   for (j=0; j<records; j++)
   {
      if (emp_id == emparr[j].id)
      {
         while (num!=0)
         {
            printf("--------------------------------------\n");
            printf("Update Employee: %d\n",emp_id);
            printf("--------------------------------------\n");
            printf("(1) Update Firstname\n(2) Update Lastname\n(3) Update Salary\n"); // displays menu for user to select updation action
            printf("--------------------------------------\n");
            printf("Your choice: ");
            scanf("%d", &choice);
            switch (choice)// switch case used to put it infinite loop until 0 is encountered
            {
            case 1:
            printf("--------------------------------------\n");
            printf("Enter new Firstname: ");//change firstname
            scanf("%s", newfname);
            strcpy(emparr[j].first_name, newfname);
            printf("--------------------------------------\n");
            break;
 
            case 2:
            printf("--------------------------------------\n");
            printf("Enter new Lastname: ");//change lastname
            scanf("%s", newlname);
            strcpy(emparr[j].last_name, newlname);
            printf("--------------------------------------\n");
            break;
 
            case 3:
            printf("--------------------------------------\n");
            printf("Enter the Salary: ");//change salary
            scanf("%d", &newsalary);
            emparr[j].salary = newsalary;
            printf("--------------------------------------\n");
            break;
 
            default:
            printf("Incorrect choice, try again\n");//error message
            break;
            }

            printf("Continue changes: \nPress 1 for YES\nPress 0 for NO\nYour Choice: ");
            scanf("%d", &num);
            printf("--------------------------------------\n");
            if (num == 1)
            {
               continue;
            }
            else
            {
               num = 0;// this causes the loop to end
            }
         }
      }
   }
}

void Msalary(char *filename)
{
//Displays M highest users
int i, j, k;
    for (i=0; i<records-1; i++) 
    {
        if (emparr[i].salary < emparr[i + 1].salary)
        {
            struct employee sort_temp;
            for (i=0; i<records-1; i++)
            {
                for (int j = i + 1; j < records; j++)
                {
                    if (emparr[i].salary < emparr[j].salary)
                    {
                        sort_temp = emparr[i];// sorting according to salary done here in desecending order
                        emparr[i] = emparr[j];
                        emparr[j] = sort_temp;
                    }
                }
            }
            break;
        }
    }
    printf("Enter M for number of Employees: "); 
    scanf("%d", &num);// asks user for M vlalue

    printf("--------------------------------------------------------------------------\n");
    printf("\nName\t\t\t\tSalary\t\tID\n");
    printf("--------------------------------------------------------------------------\n");

    for(i=0;i<num; i++)
    { 
        printf("%-10s %-10s\t\t%d\t\t%d\n", emparr[i].first_name, emparr[i].last_name, emparr[i].salary, emparr[i].id);//displyas M highest salary
    }
    printf("--------------------------------------------------------------------------\n");  
}

void matching_name(char *filename)
{
//Displays all employees with same last name.
    char matchlastname[MAXNAME];
    printf("\nEnter last name of Employee:\n");
    scanf("%s", matchlastname);
    fptr = fopen(filename, "r+");
	while(fscanf(fptr, "%d %s %s %d", &emp.id, emp.first_name, emp.last_name, &emp.salary) != EOF)
	{
		if (strcasecmp(emp.last_name, matchlastname) == 0)//compare last name of all employes in DB
		{
      	printf("-------------------------------------------------------------------------\n");
        printf("Name\t\t\t\tSalary\t\t  ID\n");
        printf("--------------------------------------------------------------------------\n");
        printf("%s\t\t%s\t\t%d\t\t%d\n", emp.first_name, emp.last_name, emp.salary, emp.id);// prints all the matching names of user input
        printf("--------------------------------------------------------------------------\n");
		found_ln++;
		}
    }
		if (found_ln == 0)
		{
			printf("Employee not in Database\n");// if name not found
		}    
        
        else
         {
        printf("%d Records found\n",found_ln);//Displays how many users of same last name found
        }
}

int main(int argc, char *argv[])
{
//This is main, it simply calls menu and sets the program in motion
	filename = argv[2];
    new(filename);
	menu(filename);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~