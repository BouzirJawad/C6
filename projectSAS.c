#include <stdio.h>
#include <stdbool.h>
#define max_tasks 100 /// set max tasks to 100

typedef struct // struct to store the date
{
    int day;
    int month;
    int year;
}taskDate;
       
typedef struct //struct to store all information
{
    char title[100];
    char description[100];
    taskDate date;
    int priority;
    int status;
}task;

task tasksListe[max_tasks];//aray to store 100 task
int tasksCounter = 0;//tracking total tasks

bool validDate(int day, int month, int year)//to check is the date is valid 
{                                           //and forces user to put a valid one
    if (year<0) return false; //no negative year
    if (month<0 || month>12) return false; //month between 1 and 12
    //set days of months
    int monthDays [] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2)
    {                       //leap year is div by 4 and not 100 / or by 400 only
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            monthDays[2] = 29;//leap year
        }
    }
    return (day > 0 && day <= monthDays[month]);//validating date
}

void addTask()//to add a task
{   
    int x;//number for how many tasks to create

    printf("How many tasks would you like to add ?\n");
    printf("0. To go back\n");
    scanf("%d", &x);
    printf("--------------------------------------------\n");

    if (tasksCounter+x > max_tasks)//making sure there is space for new tasks
    {
        printf("The list can store 100 task only. Impossible to add more! \n");
    }
    else
    {
        for (int i = tasksCounter; i < tasksCounter+x; i++)//loop for making new tasks
        {
            printf("Task %d :\n", i+1);
            printf("Title : ");
            scanf(" %[^\n]s", tasksListe[i].title);

            printf("Description :");
            scanf(" %[^\n]s", tasksListe[i].description);

            printf("Date (dd/mm/yy) :");
            scanf("%d/%d/%d", &tasksListe[i].date.day, &tasksListe[i].date.month, &tasksListe[i].date.year);

            //making sure the date is valid
            while (!validDate(tasksListe[i].date.day, tasksListe[i].date.month, tasksListe[i].date.year))
            {
                printf("--------------------------------------------\n");
                printf("Invalid date. Please enter a valid date (dd/mm/yyyy): \nDate :");
                scanf("%d/%d/%d", &tasksListe[i].date.day, &tasksListe[i].date.month, &tasksListe[i].date.year);
            }
            

            do //dowhile loop force the user to take a valid priority
            {
                printf("Priority :\n 1. Low\n 2. Medium\n 3. High\n 4. Very High\n ");
                scanf("%d", &tasksListe[i].priority);

                if (tasksListe[i].priority < 1 || tasksListe[i].priority > 4) 
                {
                    printf("--------------------------------------------\n");
                    printf("Invalid priority. Please enter a number between 1 and 4.\n");
                    printf("--------------------------------------------\n");
                }
            } while (tasksListe[i].priority < 1 || tasksListe[i].priority > 4);

            //1. inpomplete / 2.complete
            tasksListe[i].status = 1;

            printf("--------------------------------------------\n");
            printf("task number %d has been created successfully.\n", i+1);//confirming creation
            printf("--------------------------------------------\n");
        }
        tasksCounter = tasksCounter + x;//updating total of tasks
    }
}

void display(task t)//to display one task only
{
    printf("Title : %s\n", t.title);
    printf("Description : %s\n", t.description);
    printf("Date : %02d/%02d/%02d\n", t.date.day, t.date.month, t.date.year);

    switch (t.priority) 
    {
        case 1:
            printf("Priority : Low\n");
            break;
        case 2:
            printf("Priority : Medium\n");
            break;
        case 3:
            printf("Priority : High\n");
            break;
        case 4:
            printf("Priority : Very high\n");
            break;
        
        default:
            printf("Priority : No priority\n");
        break;
    }
    if (t.status == 1)
    {
        printf("Status : Incomplete.\n");
    }
    else
    {
        printf("Status : Complete.\n");
    }
    printf("--------------------------------------------\n");
}

void modifyTask()//to modify a task
{   
    int modifyChoice;// number to choose which task to modify
    int modifyindex;// number to choose what to modify in the task

    if (tasksCounter == 0)//making sure there is tasks to modify
    {
        printf("There is no task to modify\n");
        printf("--------------------------------------------\n");
    }
    else//if so start the modification code
    {
        do//dowhile loop to keep displaying tasks for modification
        {
            for (int i = 0; i < tasksCounter; i++)//displaying tasks titles to modify
            {
                printf("task %d\n", i+1);
                printf("Title : %s\n", tasksListe[i].title);
                printf("--------------------------------------------\n");
            }
            
            printf("Which task you want to modify ? ... (1 to %d)\n", tasksCounter);
            printf("0. To go back\n");
            scanf("%d", &modifyChoice);//taking the number of task to modify

            if (modifyChoice == 0)
            {
                continue;//skips the rst of code and close dowhile
            }
            
            if (modifyChoice<0 || modifyChoice>tasksCounter)//making sure user picks a valid choice
            {
                printf("--------------------------------------------\n");
                printf("Invalid choice. Please select a valid option.\n");
                printf("--------------------------------------------\n");
            }
            else
            {   
                do//dowhile loop to keep displaying modification options
                {
                    display(tasksListe[modifyChoice-1]);
                    printf("What do you want to modify ?\n");
                    printf("1. Title.\n");
                    printf("2. Description.\n");
                    printf("3. Date.\n");
                    printf("4. Priority.\n");
                    printf("5. Status.\n");
                    printf("0. To go back.\n");
                    scanf("%d", &modifyindex);
                    printf("--------------------------------------------\n");

                    switch (modifyindex)
                    {
                        case 0 ://skips the rest of the code and closes dowhile
                        continue;

                        case 1://updating title
                            printf("Previous title : %s\n", tasksListe[modifyChoice-1].title);
                            printf("Enter the new title ?\n");
                            scanf(" %[^\n]s", tasksListe[modifyChoice-1].title);
                        break;

                        case 2://updating description
                            printf("Previous description : %s\n", tasksListe[modifyChoice-1].description);
                            printf("Enter the new description ?\n");
                            scanf(" %[^\n]s", tasksListe[modifyChoice-1].description);
                        break;

                        case 3://updating date
                            printf("Previous date : %d/%d/%d\n", tasksListe[modifyChoice-1].date.day, 
                                                                tasksListe[modifyChoice-1].date.month,
                                                                tasksListe[modifyChoice-1].date.year);
                            printf("Enter the new date ?\n");
                            scanf("%d/%d/%d", &tasksListe[modifyChoice-1].date.day, 
                                            &tasksListe[modifyChoice-1].date.month,
                                            &tasksListe[modifyChoice-1].date.year);

                            //making sure the new date is valid
                            while (!validDate(tasksListe[modifyChoice-1].date.day, 
                                            tasksListe[modifyChoice-1].date.month,
                                            tasksListe[modifyChoice-1].date.year))
                            {
                                printf("--------------------------------------------\n");
                                printf("Invalid date. Please enter a valid date (dd/mm/yyyy): \n");
                                printf("Enter the new date :");
                                scanf("%d/%d/%d", &tasksListe[modifyChoice-1].date.day, 
                                                &tasksListe[modifyChoice-1].date.month,
                                                &tasksListe[modifyChoice-1].date.year);
                            }
                            
                        break;

                        case 4://updating priority
                            printf("Previous priority : ");//displaying previous priority
                            switch (tasksListe[modifyChoice-1].priority)
                            {
                                case 1 : printf("Low\n"); break;
                                case 2 : printf("Medium\n"); break;
                                case 3 : printf("High\n"); break;
                                case 4 : printf("Very high\n"); break;
                                default : printf("No priority\n");break;
                            }
                            do//dowhile loop to keep displaying priority options / forces the user to take valid option 
                            {
                                printf("Enter the new priority ?\n");
                                printf(" 1. Low\n 2. Medium\n 3. High\n 4. Very High\n ");
                                scanf("%d", &tasksListe[modifyChoice-1].priority);
                                if (tasksListe[modifyChoice-1].priority < 0 
                                    || tasksListe[modifyChoice-1].priority > 4)
                                {
                                    printf("--------------------------------------------\n");
                                    printf("Invalid priority. Please enter a number between 1 and 4.\n");
                                    printf("--------------------------------------------\n");
                                }
                            } while (tasksListe[modifyChoice-1].priority < 0 
                                || tasksListe[modifyChoice-1].priority > 4);
                        break;

                        case 5 :
                            //add status here later 

                        break;

                        default://error msg if user takes invalid choice
                            printf("--------------------------------------------\n");
                            printf("Invalid choice. Please select a valid option.\n");
                            printf("--------------------------------------------\n");
                        break;

                        printf("--------------------------------------------\n");
                    }
                } while (modifyindex);
            }
        } while (modifyChoice);
    }
}

void deleteTask()//to delete a task
{
    int deleteChoice;//number to choose who to delete

    if (tasksCounter == 0)//validating that there is members to delete
    {
        printf("There is no task to delete. \n");
        printf("--------------------------------------------\n");
    }
    else//if so start deleting code
    {
        do
        {
            for (int i = 0; i < tasksCounter; i++)//displaying tasks titles only for delete 
            {
                printf("task %d :\n", i+1);
                printf("Title : %s\n", tasksListe[i].title);
                printf("--------------------------------------------\n");
            }

            printf("Enter a task number to delete ... (1 to %d)\n", tasksCounter);
            printf("0. To go back\n");
            scanf("%d", &deleteChoice);

            if (deleteChoice == 0)
            {
                continue;//if user takes 0, skip the rest of code and close dowhile
            }

            if (deleteChoice<0 || deleteChoice>tasksCounter)
            { //error message if user choose invalid task number
                printf("Invalid choice. Please select a valid option.\n");
                printf("--------------------------------------------\n");
            }

            else//moving all remaining tasks to the left
            {
                for (int i = deleteChoice-1; i < tasksCounter-1; i++)
                {
                    tasksListe[i] = tasksListe[i+1];
                }
                tasksCounter --;

                printf("task number %d deleted successfully.\n", deleteChoice);
                printf("--------------------------------------------\n");
            }
        } while (deleteChoice);
    }
}

void displayAll()//to display all tasks
{
    if (tasksCounter == 0)//validating that there is tasks to display
    {
        printf("There is no tasks to display\n");
        printf("--------------------------------------------\n");
    }
    else
    {
        for (int i = 0; i < tasksCounter; i++)//running a loop to display all tasks
        {
            printf("task %d :\n", i+1);
            display(tasksListe[i]);
        }
    }
}

void priorityFilter()//to filter tasks based on priority
{
    int periorityChoice;//number to choose which priority to filter with
    if(tasksCounter == 0)//making sure is tasks to filter
    {
        printf("There is no task to filter. \n");
        printf("--------------------------------------------\n");
    }
    else//if so starting filtering
    {
        do //dowhile loop to keep displaying filter option till the user take 0 (0 is an option to go back)
        { 
            printf("Enter the priority you want to filter with ?\n");
            printf(" 1. Low\n 2. Medium\n 3. High \n 4. Very High\n 0. To go back\n");
            scanf("%d", &periorityChoice);//taking the choice of filtering
            switch (periorityChoice)//display msg showing to show what we filtering
            {
                case 1 : printf("Tasks with priority : Low\n"); break;
                case 2 : printf("Tasks with priority : Medium\n"); break;
                case 3 : printf("Tasks with priority : High\n"); break;
                case 4 : printf("Tasks with priority : Very high\n"); break;
                case 0 : continue;//skipping the rest of code and closing dowhile
                default :
                    printf("--------------------------------------------\n");
                    printf("Invalid choice. Please select a valid option.\n");
                    printf("--------------------------------------------\n");
                continue;//skipping the code but starting dowhile over
            }

            int found = 0;//to track if any tasks match the chosen priority

            for (int i = 0; i < tasksCounter; i++)
            {
                if (tasksListe[i].priority == periorityChoice)//filtering tasks with the chosen priority
                {
                    display(tasksListe[i]);
                    found = 1; //set to 1 if a match found
                }
            }
            if (found == 0)//if no match found display a msg saying it 
            {
                printf("No match found !\n");
                printf("--------------------------------------------\n");
            }
        } while (periorityChoice);
    }
}

void ascending()
{
    if (tasksCounter == 0)//making sure there is tasks to sort
    {
        printf("There is no task to sort\n");
        printf("--------------------------------------------\n");
    }
    else
    {
        for (int i = 0; i < tasksCounter; i++)           //sorting tasks (ascending)
        {
            for (int j = i + 1; j < tasksCounter; j++)      
            {
                if (tasksListe[i].date.year > tasksListe[j].date.year || 
                    tasksListe[i].date.year == tasksListe[j].date.year && 
                    tasksListe[i].date.month > tasksListe[j].date.month || 
                    tasksListe[i].date.month == tasksListe[j].date.month && 
                    tasksListe[i].date.day > tasksListe[j].date.day)
                {
                    task temp = tasksListe[i];
                    tasksListe[i] = tasksListe[j];      //switching tasks
                    tasksListe[j] = temp;
                } 
            }
        }

        printf("Tasks ordered by ascending date.\n");
        printf("--------------------------------------------\n");
    }
}

void descending()
{
    if (tasksCounter == 0)// making sure there is tasks to order
    {
        printf("There is no task to sort\n");
        printf("--------------------------------------------\n");
    }
    else
    {
        for (int i = 0; i < tasksCounter; i++)                  //sorting tasks (descending)
        {
            for (int j = i + 1; j < tasksCounter; j++)    
            {
                if (tasksListe[i].date.year < tasksListe[j].date.year ||
                    tasksListe[i].date.year == tasksListe[j].date.year &&
                    tasksListe[i].date.month < tasksListe[j].date.month ||
                    tasksListe[i].date.month == tasksListe[j].date.month &&
                    tasksListe[i].date.day < tasksListe[j].date.day)
                {
                    task temp = tasksListe[i];
                    tasksListe[i] = tasksListe[j];     //switching tasks
                    tasksListe[j] = temp;
                }
            }
        }
        
        printf("Tasks ordered by descending date.\n");
        printf("--------------------------------------------\n");
    }
}

int main()
{   
    int menuChoice; //to take the choice of the user from the menu
    do
    {
        printf("--------------------Menu--------------------\n");
        printf("1. Add a new task.\n");
        printf("2. Modify a task.\n");
        printf("3. Delete a task.\n");
        printf("4. Display tasks.\n");
        printf("5. Filter tasks based on priority.\n");
        printf("6. Sorting tasks by date(ascending).\n");
        printf("7. Sorting tasks by date(descending).\n");
        printf("0. Exit\n");
        scanf("%d", &menuChoice);
        printf("--------------------------------------------\n");

        switch (menuChoice)
        {
            case 1 :// to add a new task 
                addTask();
            break;

            case 2 :// to modify a task
                modifyTask();
            break;

            case 3 ://deleting a task
                deleteTask();
            break;

            case 4 ://displaying all tasks
                displayAll();
            break;

            case 5 ://filtering tasks based on priority 
                priorityFilter();
            break;

            case 6 ://sorting tasks based on ascending date
                ascending();
            break;

            case 7 ://sorting tasks based on descending date
                descending();
            break;

            case 0 ://to exit the program
                printf("Exiting...(see you next time :v )\n");
            break;
        
            default://error msg if user takes invalid choice
                printf("Invalid choice. Please select a valid option.\n");
                printf("--------------------------------------------\n");
            break;
        }    
    } while (menuChoice);
}

