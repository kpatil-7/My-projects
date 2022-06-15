/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~EMPLOYEE DATABASE SYSTEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~This is Sp-Lab-1 submission for CS402 by Kayenat Patil at 11/4/2021 at Illinois Tech~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In this code various meaningful fucntions are written to execute the code and understand it.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.c"


void count_employees(char *filename)
{
	//This function counts the total number of employees and prints it once called.
	//fptr = open_file(filename, "r");
  fptr = fopen(filename, "r");
  int ch, records = 0;
  do 
  {
    ch = fgetc(fptr);
    if(ch == '\n')
      records++;
  }
  while(ch!=EOF);
  if(ch != '\n' && records!= 0)
  {
  	records++;
  }
  close_file(fptr);
  printf("Number of Employees: (%d) \n", records);
}

void menu(char *filename)
{
	// This function displays a menu to the user to choose what needs to be done
	while (num !=5)
	{
		printf("--------------------------------------\n");
		printf("Employee Database:\n");
		printf("--------------------------------------\n");
		printf("   (1) Print the Database\n   (2) Lookup by ID\n   (3) Lookup by Last Name\n   (4) Add an Employee\n   (5) Quit\n");
		printf("--------------------------------------\n");
		printf("Enter your choice:");
		scanf("%d",&num);
		printf("--------------------------------------\n");


		switch (num) 
		{
			case 1: 
			{
				display_database(filename);
				count_employees(filename);
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


			default:
			{
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
	//fptr = open_file(filename, "r");
	fptr = fopen(filename, "r");
	printf("----------------------------------------------------------------------------\n");
	printf("Name\t\t\t\tSalary\t\t  ID\n");
	printf("----------------------------------------------------------------------------\n");

	while(fscanf(fptr, "%d%s%s%d", &emp.id, emp.first_name, emp.last_name, &emp.salary) != EOF)
	{
		printf("%-10s %-10s\t\t%d\t\t%d\n", emp.first_name, emp.last_name, emp.salary, emp.id);
	}
	printf("----------------------------------------------------------------------------\n");
	close_file(fptr);
}

void lastname_finder(char *filename, char *emplname)
{
	//This function takes in the last name from the user and finds the record that has the same last name
	//fptr = open_file(filename, "r");
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
	//This function adds employee data and dynamicly assigns the largest value as Id to the new entry 
	char *maxptr = filename; 
	//fptr = open_file(filename, "r+"); 

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
	//this function is used to find the largest value of id and return it
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

int main(int argc, char *argv[])
{
	//this is main, it simply calls menu and sets the program in motion
	filename = argv[2];
	menu(filename);
}