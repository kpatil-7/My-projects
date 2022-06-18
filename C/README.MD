# Building a Database Management system
![DBMS](https://user-images.githubusercontent.com/89879994/174415082-777c7375-4c2f-4e7a-a9e2-fdd01193f16f.png)

While this project initially started off as an assignment, I had taken quite the liking in finishing this and implementing a few of my own features and really putting my own special spin on it. I had some experience with a DBMS, but never creating one from scratch and manging products and/or customers on it. The assignmetn started off by giving me a list of ten items to manage them. Here is what was asked of me.

### Conditions:
1) Have a Menu that lists all the options available to manage the DB 
2) Case statements to jump to the option selected and only carry out that perticular option
3) Create a function that counts the number of employees
4) Display all the information in the DB
5) Find customer by a given ID and return all the stats of the customer
6) Find Employee by searching for their last name
7) Add new employees 
8) Have an exit function with an exit message 
9) Have an Error message to display if something goes wrong
10) Keep the entire system on a loop, ie. the user can only exit if he cooses to exit, until then the program continues running and displaying the menu after each operation.

### Instructions to build executible
-> Open Linux terminal. I used 18.04 LTS
-> Change directory to where the file is stored.
-> Run the following command

#### gcc lab.c

-> This builds the output file
-> Then run the following command

#### ./a.out lab1.c small.txt

-> The program should run and display the Menu

### The Next Step

1) Deletion:
The next thing that I decided to do with this DB was to give the user prinledges to delete a user based on the ID. I figured that if I can give the option to create the user, I can give the option to delete the user as well.

2) Updation:
In here, the user could put in the employee ID and alter the salary of any cliet in the DB. While I had put in the option of updating the name, I soon took it out. I figured that if I think about his realistically, having the option to update someone's name would be a highly unlikely scenario.

3) Getting M highest Salary:
Here the user would type a random positive integer M for which the code should dispay that M highest salary. For this, I created a seperate function for sorting the users in descending order before calling the fuction to diplay the salary.

4) Multiple Lastnames
Its a very real possibility that multiple people could have the same last name. So I create a function that would ask for a last name and return all the employees wit hthe same last number. 

### Conlcusion
Space and memory were a real issue for me while working on this code. while I did face some minor errors that were caused beacause of pointers and using a filing system, they were pretty easy to solve.

Overall, a pretty easy project once you have your logic in place.
