#include <stdio.h>
#include <string.h>

#define max_tasks 100 /// set max tasks to 100

typedef struct // struct to store the date
{
    int day;
    int mounth;
    int year;
}taskDate;
       
typedef struct 
{
    char title[100];
    char description[100];
    taskDate date;
    int priority;
}task;

task tasksListe[max_tasks];
int tasksCounter = 0;

void addTask()
{   
    int x;
    printf("How many tasks would you like to add ?\n");
    printf("0. To go back\n");
    scanf("%d", &x);//number for how many tasks to create
    printf("--------------------------------------------\n");

    if (tasksCounter+x > max_tasks)
    {
        printf("The list can store 100 task only. Impossible to add more! \n");
    }
    else
    {
        for (int i = tasksCounter; i < tasksCounter+x; i++)//making new tasks
        {
            printf("Task %d :\n", i+1);
            printf("Title : ");
            scanf(" %[^\n]s", tasksListe[i].title);

            printf("Description :");
            scanf(" %[^\n]s", tasksListe[i].description);

            printf("Date (dd/mm/yy) :");
            scanf("%d/%d/%d", &tasksListe[i].date.day, &tasksListe[i].date.mounth, &tasksListe[i].date.year);

            do 
            {
                printf("Priority:\n 1. Low\n 2. Medium\n 3. High\n 4. Very High\n ");
                scanf("%d", &tasksListe[i].priority);

                if (tasksListe[i].priority < 1 || tasksListe[i].priority > 4) 
                {
                    printf("--------------------------------------------\n");
                    printf("Invalid priority. Please enter a number between 1 and 4.\n");
                    printf("--------------------------------------------\n");
                }
            } while (tasksListe[i].priority < 1 || tasksListe[i].priority > 4);

            printf("--------------------------------------------\n");
            printf("task number %d has been created successfully.\n", i+1);
            printf("--------------------------------------------\n");
        }
        tasksCounter = tasksCounter + x;
    }
}

void display(task t)
{
    printf("Title : %s\n", t.title);
    printf("Description : %s\n", t.description);
    printf("Date : %02d/%02d/%02d\n", t.date.day, t.date.mounth, t.date.year);

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
    printf("--------------------------------------------\n");
}

void tempDisplay(task t)
{
    printf("Title : %s\n", t.title);
    printf("--------------------------------------------\n");
}

void modifyTask()
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
                    for (int i = 0; i < tasksCounter; i++)//displaying tasks to modify
                    {
                        printf("task %d\n", i+1);
                        tempDisplay(tasksListe[i]);
                    }
                    
                    printf("Which task you want to modify ? ... (1 to %d)\n", tasksCounter);
                    scanf("%d", &modifyChoice);//taking the number of task to modify

                    if (modifyChoice<1 || modifyChoice>tasksCounter)//making sure user picks a valid choice
                    {
                        printf("--------------------------------------------\n");
                        printf("Invalid choice. Please select a valid option.\n");
                        printf("--------------------------------------------\n");
                    }
                    else
                    {   
                        int continueModifying = 1;//variable to control modification loop
                        do
                        {
                            display(tasksListe[modifyChoice-1]);
                            printf("What do you want to modify ?\n");
                            printf("1. Title\n");
                            printf("2. Description\n");
                            printf("3. date\n");
                            printf("4. priority\n");
                            printf("0. back\n");
                            scanf("%d", &modifyindex);
                            printf("--------------------------------------------\n");

                            switch (modifyindex)
                            {
                                case 1:
                                    printf("Previous title : %s\n", tasksListe[modifyChoice-1].title);
                                    printf("Enter the new title ?\n");
                                    scanf(" %[^\n]s", tasksListe[modifyChoice-1].title);
                                break;

                                case 2:
                                    printf("Previous description : %s\n", tasksListe[modifyChoice-1].description);
                                    printf("Enter the new description ?\n");
                                    scanf(" %[^\n]s", tasksListe[modifyChoice-1].description);
                                break;

                                case 3:
                                    printf("Previous date : %d/%d/%d\n", tasksListe[modifyChoice-1].date.day, 
                                                                        tasksListe[modifyChoice-1].date.mounth,
                                                                        tasksListe[modifyChoice-1].date.year);
                                    printf("Enter the new date ?\n");
                                    scanf("%d/%d/%d", &tasksListe[modifyChoice-1].date.day, 
                                                    &tasksListe[modifyChoice-1].date.mounth,
                                                    &tasksListe[modifyChoice-1].date.year);
                                break;

                                case 4:
                                    printf("Previous priority : ");
                                    switch (tasksListe[modifyChoice-1].priority)
                                    {
                                        case 1 : printf("Low\n"); break;
                                        case 2 : printf("Medium\n"); break;
                                        case 3 : printf("High\n"); break;
                                        case 4 : printf("Very high\n"); break;
                                        default : printf("No priority\n");break;
                                    }

                                    do
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

                                case 0 :
                                continueModifying = 0;
                                break;
                                
                                default://error msg if user takes invalid choice
                                    printf("--------------------------------------------\n");
                                    printf("Invalid choice. Please select a valid option.\n");
                                    printf("--------------------------------------------\n");
                                break;

                                printf("--------------------------------------------\n");
                            }
                        } while (continueModifying);
                    }
                }
}

void deleteTask()
{
    int deleteChoice;//number to choose who to delete
    if (tasksCounter == 0)//validating that there is members to delete
    {
        printf("There is no task to delete. \n");
        printf("--------------------------------------------\n");
    }
    else
    {
        int continueDeleting = 1;//var to control deleting loop
        do
        {
            for (int i = 0; i < tasksCounter; i++)//displaying tasks titles only for delete 
            {
                printf("task %d :\n", i+1);
                tempDisplay(tasksListe[i]);//hereeee
            }

            printf("Enter a task number to delete ... (1 to %d)\n", tasksCounter);
            printf("0. To go back\n");
            scanf("%d", &deleteChoice);

            switch (deleteChoice)
            {
                case 0:
                    continueDeleting = 0;
                break;
                            
                default:
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
                break;
            }
        } while (continueDeleting);
    }
}

void displayAll()
{
    if (tasksCounter == 0)//validating that there is tasks to display
    {
        printf("There is no tasks to display\n");
        printf("--------------------------------------------\n");
    }
    else
    {
        for (int i = 0; i < tasksCounter; i++)
        {
            printf("task %d :\n", i+1);
            display(tasksListe[i]);
        }
    }
}

int main()
{   
    int menuChoice; //to take the choice of the user from the menu
    do
    {
        printf("--------------------Menu--------------------\n");
        printf("1. Add a new task\n");
        printf("2. Modify a task\n");
        printf("3. Delete a task\n");
        printf("4. Display tasks\n");
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

            case 4 :
                displayAll();
            break;

            case 5 :
                
            break;

            case 0 :
                menuChoice = 0;
                printf("Exiting...(see you next time :v )\n");
            break;
        
            default://error msg if user takes invalid choice
                printf("Invalid choice. Please select a valid option.\n");
                printf("--------------------------------------------\n");
            break;
        }    
    } while (menuChoice);
}

