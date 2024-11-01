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
    char description[200];
    taskDate date;
    int priority;
    int status;
}task;

task tasksListe[max_tasks];//aray to store 100 task
int tasksCounter = 0;//tracking total tasks

bool validDate(int day, int month, int year)//to check is the date is valid 
{                                           //and forces user to put a valid one
    if (year<2024) return false; //no negative year or less than 2024
    if (month<1 || month>12) return false; //month between 1 and 12
    //set days of months
    int monthDays [] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2)
    {                       //leap year is div by 4 and not 100 / or by 400 only
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            monthDays[2] = 29;//leap year
        }
    }
    return (day > 0 && day <= monthDays[month]);//validating day date to 
}

void addTask()//to add a task
{   
    int x;//number for how many tasks to create

    printf("How many tasks would you like to add ?\n");
    printf("\t0. To go back\n");
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
            printf("\tTask %d :\n", i+1);
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
                printf("Invalid date! Please enter a valid date (dd/mm/yyyy): \nDate :");
                scanf("%d/%d/%d", &tasksListe[i].date.day, &tasksListe[i].date.month, &tasksListe[i].date.year);
            }
            

            do //dowhile loop force the user to take a valid priority
            {
                printf("Priority :\n\t1. Low\n\t2. Medium\n\t3. High\n\t4. Very High\n ");
                scanf("%d", &tasksListe[i].priority);

                if (tasksListe[i].priority < 1 || tasksListe[i].priority > 4) 
                {
                    printf("--------------------------------------------\n");
                    printf("Invalid priority! Please enter a number between 1 and 4.\n");
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
    {printf("Status : Incomplete.\n");}
    else
    {printf("Status : Complete.\n");}
    
    printf("--------------------------------------------\n");
}

void displayTask()//to display all tasks
{
    if (tasksCounter == 0)//validating that there is tasks to display
    {
        printf("There is no tasks to display!\n");
        printf("--------------------------------------------\n");
    }
    else
    {
        for (int i = 0; i < tasksCounter; i++)//running a loop to display all tasks
        {
            printf("\ttask %d :\n", i+1);
            display(tasksListe[i]);
        }
    }
}

void modifyTask()//to modify a task
{   
    int modifyChoice;// number to choose which task to modify
    int modifyindex;// number to choose what to modify in the task
    int statusMark;// number for status changing menu

    if (tasksCounter == 0)//making sure there is tasks to modify
    {
        printf("There is no task to modify!\n");
        printf("--------------------------------------------\n");
    }
    else//if so start the modification code
    {
        do//dowhile loop to keep displaying tasks for modification
        {
            for (int i = 0; i < tasksCounter; i++)//displaying tasks titles and status to modify
            {
                printf("\ttask %d :\n", i+1);
                printf("Title : %s\n", tasksListe[i].title);

                if (tasksListe[i].status == 1)
                {printf("Status : Incomplete.\n");}
                else{printf("Status : Complete.\n");}

                printf("--------------------------------------------\n");
            }
            
            printf("Which task you want to modify ? ... (1 to %d)\n", tasksCounter);
            printf("\t0. To go back\n");
            scanf("%d", &modifyChoice);//taking the number of task to modify
            printf("--------------------------------------------\n");

            if (modifyChoice == 0)
            {
                continue;//skips the rst of code and close dowhile
            }
            
            if (modifyChoice<0 || modifyChoice>tasksCounter)//making sure user picks a valid choice
            {
                printf("Invalid choice! Please select a valid option.\n");
                printf("--------------------------------------------\n");
            }
            else
            {   
                do//dowhile loop to keep displaying modification options
                {
                    display(tasksListe[modifyChoice-1]);
                    printf("What do you want to modify ?\n");
                    printf("\t1. Title.\n");
                    printf("\t2. Description.\n");
                    printf("\t3. Date.\n");
                    printf("\t4. Priority.\n");
                    printf("\t5. Status.\n");
                    printf("\t0. To go back.\n");
                    scanf("%d", &modifyindex);
                    printf("--------------------------------------------\n");

                    switch (modifyindex)
                    {
                        case 0 ://skips the rest of the code and closes dowhile
                        continue;

                        case 1://updating title
                            printf("Current title : %s\n", tasksListe[modifyChoice-1].title);
                            printf("Enter the new title ?\n");
                            scanf(" %[^\n]s", tasksListe[modifyChoice-1].title);
                            printf("--------------------------------------------\n");
                        break;

                        case 2://updating description
                            printf("Current description : %s\n", tasksListe[modifyChoice-1].description);
                            printf("Enter the new description ?\n");
                            scanf(" %[^\n]s", tasksListe[modifyChoice-1].description);
                            printf("--------------------------------------------\n");
                        break;

                        case 3://updating date
                            printf("Current date : %d/%d/%d\n", tasksListe[modifyChoice-1].date.day, 
                                                                tasksListe[modifyChoice-1].date.month,
                                                                tasksListe[modifyChoice-1].date.year);
                            printf("Enter the new date ?\n");
                            scanf("%d/%d/%d", &tasksListe[modifyChoice-1].date.day, 
                                            &tasksListe[modifyChoice-1].date.month,
                                            &tasksListe[modifyChoice-1].date.year);
                            printf("--------------------------------------------\n");

                            //making sure the new date is valid
                            while (!validDate(tasksListe[modifyChoice-1].date.day, 
                                            tasksListe[modifyChoice-1].date.month,
                                            tasksListe[modifyChoice-1].date.year))
                            {
                                printf("Invalid date. Please enter a valid date (dd/mm/yyyy): \n");
                                printf("Enter the new date :");
                                scanf("%d/%d/%d", &tasksListe[modifyChoice-1].date.day, 
                                                &tasksListe[modifyChoice-1].date.month,
                                                &tasksListe[modifyChoice-1].date.year);
                                printf("--------------------------------------------\n");
                            }
                            
                        break;

                        case 4://updating priority
                            printf("Current priority : ");//displaying current priority
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
                                printf("\t1. Low\n\t2. Medium\n\t3. High\n\t4. Very High\n ");
                                scanf("%d", &tasksListe[modifyChoice-1].priority);
                                printf("--------------------------------------------\n");

                                if (tasksListe[modifyChoice-1].priority < 1 
                                    || tasksListe[modifyChoice-1].priority > 4)
                                {
                                    printf("Invalid priority! Please enter a number between 1 and 4.\n");
                                    printf("--------------------------------------------\n");
                                }
                            } while (tasksListe[modifyChoice-1].priority < 1 
                                || tasksListe[modifyChoice-1].priority > 4);
                        break;

                        case 5 ://updating status
                            do//dowhile loop to keep display incase taking invalid choice
                            {
                                printf("Current status : ");//displaying current status with option menu
                                if (tasksListe[modifyChoice-1].status == 1)
                                {
                                    printf("Incomplete.\n");
                                    printf("\t0. To go back\n");
                                    printf("\t1. Mark as complete.\n");
                                }
                                else
                                {
                                    printf("Complete.\n");
                                    printf("\t0. To go back\n");
                                    printf("\t1. Mark as incomplete.\n");
                                }

                                scanf("%d", &statusMark);
                                printf("--------------------------------------------\n");

                                if (statusMark == 1 && statusMark != 0 && tasksListe[modifyChoice-1].status == 1)
                                {
                                    tasksListe[modifyChoice-1].status = 2;
                                    printf("\tTask %d marked as completed\n", modifyChoice);
                                    printf("--------------------------------------------\n");
                                    break;//to exit the loop after changing the stratus with number 1
                                }

                                else if(statusMark == 1 && statusMark != 0)
                                {
                                    tasksListe[modifyChoice-1].status = 1;
                                    printf("\tTask %d marked as incompleted\n", modifyChoice);
                                    printf("--------------------------------------------\n");
                                    break;//to exit the loop after changing the stratus with number 1
                                }

                                else if (statusMark>2)
                                {
                                    printf("Invalid choice! Please select a valid option.\n");
                                    printf("--------------------------------------------\n");
                                }
                            } while (statusMark);
                        break;

                        default://error msg if user takes invalid choice
                            printf("Invalid choice! Please select a valid option.\n");
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
        printf("There is no task to delete! \n");
        printf("--------------------------------------------\n");
    }
    else//if so start deleting code
    {
        do
        {
            for (int i = 0; i < tasksCounter; i++)//displaying tasks titles only for delete 
            {
                printf("\ttask %d :\n", i+1);
                printf("Title : %s\n", tasksListe[i].title);

                if (tasksListe[i].status == 1)
                {printf("Status : Incomplete.\n");}
                else{printf("Status : Complete.\n");}

                printf("--------------------------------------------\n");
            }

            printf("Enter a task number to delete ... (1 to %d)\n", tasksCounter);
            printf("\t0. To go back\n");
            scanf("%d", &deleteChoice);

            if (deleteChoice == 0)
            {
                continue;//if user takes 0, skip the rest of code and close dowhile
            }

            if (deleteChoice<0 || deleteChoice>tasksCounter)
            { //error message if user choose invalid task number
                printf("--------------------------------------------\n");
                printf("Invalid choice! Please select a valid option.\n");
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

void priorityFilter()//to filter tasks based on priority
{
    int periorityChoice;//number to choose which priority to filter with
     
    do //dowhile loop to keep displaying filter option till the user take 0 (0 is an option to go back)
    { 
        printf("Enter the priority you want to filter with ?\n");
        printf("\t1. Low\n\t2. Medium\n\t3. High \n\t4. Very High\n\t0. To go back\n");
        scanf("%d", &periorityChoice);//taking the choice of filtering
        printf("--------------------------------------------\n");

        switch (periorityChoice)//display msg showing to show what we filtering
        {
            case 1 : printf("\tTasks with priority : Low\n"); break;
            case 2 : printf("\tTasks with priority : Medium\n"); break;
            case 3 : printf("\tTasks with priority : High\n"); break;
            case 4 : printf("\tTasks with priority : Very high\n"); break;
            case 0 : continue;//skipping the rest of code and closing dowhile
            default :
                printf("Invalid choice! Please select a valid option.\n");
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
            printf("\tNo match found!\n");
            printf("--------------------------------------------\n");
        }
    } while (periorityChoice);
}

void statusFilter()//to filter tasks based on status
{
    int statusChoice;//number to choose which status to filter with
    
    do //dowhile loop to keep displaying filter option till the user take 0 (0 is an option to go back)
    { 
        printf("Enter the status you want to filter with ?\n");
        printf("\t1. Incomplete\n\t2. Complete\n\t0. To go back\n");
        scanf("%d", &statusChoice);//taking the choice of filtering
        printf("--------------------------------------------\n");

        switch (statusChoice)//display msg showing to show what we filtering
        {
            case 1 : printf("\tIncompleted tasks :\n"); break;
            case 2 : printf("\tCompleted tasks :\n"); break;
            case 0 : continue;//skipping the rest of code and closing dowhile
            default :
                printf("Invalid choice! Please select a valid option.\n");
                printf("--------------------------------------------\n");
            continue;//skipping the code but starting dowhile over
        }

        int found = 0;//to track if any tasks match the chosen status

        for (int i = 0; i < tasksCounter; i++)
        {
            if (tasksListe[i].status == statusChoice)//filtering tasks with the chosen status
            {
                display(tasksListe[i]);
                found = 1; //set to 1 if a match found
            }
        }
        if (found == 0)//if no match found display a msg saying it 
        {
            printf("\tNo match found!\n");
            printf("--------------------------------------------\n");
        }
    } while (statusChoice);
}

void ascending()
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

void descending()
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

void saveFile() {
    FILE *file = fopen("Tasks.txt", "w"); 

    for (int i = 0; i < tasksCounter; i++) {
        fprintf(file, "------------------Task %d :------------------\n", i+1);
        fprintf(file, "Title : %s\n", tasksListe[i].title);
        fprintf(file, "Description : %s\n", tasksListe[i].description);
        fprintf(file, "Date : %02d/%02d/%02d\n", tasksListe[i].date.day, tasksListe[i].date.month, tasksListe[i].date.year);

    switch (tasksListe[i].priority) 
    {
        case 1:
            fprintf(file, "Priority : Low\n");
            break;
        case 2:
            fprintf(file, "Priority : Medium\n");
            break;
        case 3:
            fprintf(file, "Priority : High\n");
            break;
        case 4:
            fprintf(file, "Priority : Very high\n");
            break;
        
        default:
            fprintf(file, "Priority : No priority\n");
        break;
    }

    if (tasksListe[i].status == 1)
    {fprintf(file, "Status : Incomplete.\n");}
    else
    {fprintf(file, "Status : Complete.\n");}
    
    fprintf(file, "--------------------------------------------\n");
    }

    fclose(file); 
    printf("Tasks saved Successfully!!\n");
}

int main()
{   
    int menuChoice; //to take the choice of the user from the main menu
    int filterChoice;//to take the choice of the user from the filter menu
    int statusChoice;//to take the choice of the user from the sort menu

    printf("\n------------Welcome to OneHand--------------\n\n");
    do
    {
        printf("-----------------Main menu------------------\n");
        printf("\t1. Add a new task.\n");
        printf("\t2. Modify a task.\n");
        printf("\t3. Delete a task.\n");
        printf("\t4. Display tasks.\n");
        printf("\t5. Filter tasks.\n");
        printf("\t6. Sort tasks.\n");
        printf("\t7. Save tasks.\n");
        printf("\t0. Exit\n");
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
                displayTask();
            break;

            case 5 ://filtering tasks based on priority or status
                if(tasksCounter == 0)//making sure is tasks to filter
                {
                    printf("There is no task to filter! \n");
                    printf("--------------------------------------------\n");
                }
                else
                {
                    do
                    {
                        printf("---------------Filter menu------------------\n");
                        printf("\t1. Filter with periority.\n");
                        printf("\t2. Filter with status.\n");
                        printf("\t0. To go back.\n");
                        scanf("%d", &filterChoice);
                        printf("--------------------------------------------\n");

                        if (filterChoice == 1)//filtering based on priority
                        {priorityFilter();}

                        else if(filterChoice == 2)//filtering based on status
                        {statusFilter();}

                        if(filterChoice>2)//error msg incase taking invalid choice
                        {

                            printf("Invalid choice! Please select a valid option.\n");
                            printf("--------------------------------------------\n");
                        }
                    } while (filterChoice);
                }
            break;

            case 6 ://sorting tasks based on ascending and descending date
                if(tasksCounter == 0)//making sure is tasks to filter
                {
                    printf("There is no task to sort! \n");
                    printf("--------------------------------------------\n");
                }
                else
                {
                    do
                    {
                        printf("----------------Sort menu-------------------\n");
                        printf("\t1. Sort by ascending date.\n");
                        printf("\t2. Sort by descending date.\n");
                        printf("\t0. To go back.\n");
                        scanf("%d", &statusChoice);
                        printf("--------------------------------------------\n");

                        if (statusChoice == 1)//ascending sort and display
                        {
                            ascending();
                            displayTask();
                        }

                        else if(statusChoice == 2)//descending sort and display
                        {
                            descending();
                            displayTask();
                        }

                        if(statusChoice>2)//error msg incase taking invalid choice
                        {
                            printf("Invalid choice! Please select a valid option.\n");
                            printf("--------------------------------------------\n");
                        }
                    } while (statusChoice);
                }
            break;

            case 7 :
                    if(tasksCounter == 0)//making sure is tasks to filter
                    {
                        printf("There is no task to save! \n");
                        printf("--------------------------------------------\n");
                    }
                    else
                    {
                        saveFile();
                    }   
            break;

            case 0 ://to exit the program
                printf("Exiting...(see you next time :v )\n");
            break;
        
            default://error msg if user takes invalid choice
                printf("Invalid choice! Please select a valid option.\n");
                printf("--------------------------------------------\n");
            break;
        }    
    } while (menuChoice);
}
