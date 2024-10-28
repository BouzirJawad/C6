#include <stdio.h>
#include <string.h>

typedef struct  
{
    char street[50];
    char city[50];
    int code_postal;
}adr;

typedef struct
{
    char name[50];
    int age;
    adr Adress;
}person;

void createPerson(person *p) // function to create new persons
{
    printf("Name : ");
    scanf("%49s", p->name);

    printf("Age : ");
    scanf("%d", &p->age);

    printf("Adress (Street) : ");
    scanf("%49s", p->Adress.street);

    printf("Adress (City) : ");
    scanf("%49s", p->Adress.city);

    printf("Adress (Code Postal) : ");
    scanf("%d", &p->Adress.code_postal);

    printf("-------------------------\n");
}

void display(person p){ //function to display the list of members 
        
        printf("Name : %s\n", p.name);
        printf("Age : %d\n", p.age);
        printf("Adress(Street) :%s\n", p.Adress.street);
        printf("Adress(City) :%s\n", p.Adress.city);
        printf("Adress(Code Postal) :%d\n", p.Adress.code_postal);
        printf("--------------------------\n");
}

void displayForDelete(person p){ //function to display members names only for deleting
        printf("Name : %s\n", p.name);
        printf("--------------------------\n");
}

void deletePerson(person persons[], int *person_count, int index){// function to delete memebrs
    if (index<1 || index>*person_count)
    {
        printf("Invalid person number");
        return;
    }

    for (int i = index-1; i < *person_count-1; i++)
    {
        persons[i] = persons[i+1];
    }
    (*person_count)--;

    printf("Person number %d deleted successfully.\n", index);
    printf("--------------------------\n");
}

 int main()
{ 
    person persons[100]; //array to store created persons
    int choice; //to take the choice of the user about what to do next
    int x; //numbers to control how many persons to add
    int person_count = 0; // to track the total of persons i have so far
    int index; // number to choose who to delete
    int index2; // number to choose who to modify 
    int choice2; // number to choose what to modify

    do
    {
        printf("What's next ?\n");
        printf("1. add a person\n");
        printf("2. delete a person\n");
        printf("3. modify a person\n");
        printf("4. display \n");
        printf("0. exit\n");
        scanf("%d", &choice);
        printf("-----------------------------\n");// list to ask the user what he wanna do 

        switch (choice)
        {
            case 1: //adding a new person
                printf("How many persons would you like to add ?\n");
                printf("0. to go back\n");
                scanf("%d", &x);//number for how many persons to create
                printf("-----------------------------\n");

                for (int i = 0; i < x; i++)//making new persons
                {
                    printf("Person %d\n", person_count+1);
                    createPerson(&persons[person_count]);
                    person_count++;
                }
            break;

            case 2://deleting persons
                if (person_count == 0)//validating that there is members to delete
                {
                    printf("There is no person to delete. \n");
                    printf("---------------------\n");
                }

                else
                {
                    for (int i = 0; i < person_count; i++)//displaying all memebers to choose who to delete
                    {
                        printf("Person %d :\n", i+1);
                        displayForDelete(persons[i]);
                    }

                        printf("Enter a person number to delete ... (1 to %d)\n", person_count);
                        scanf("%d", &index);//choosing a person number to delete

                    if (index <1 || index > person_count)//validating that the users pick a valid choice
                    {
                        printf("Invalid choice. Please select a valid option.\n");
                        printf("--------------------------------------------\n");
                    }

                    else
                    {
                        deletePerson(persons, &person_count, index);//deleting the chosen one
                    }
                }
                break;

            case 3:
                if (person_count == 0)//validating that there is members to modify
                {
                    printf("There is no person to modify\n");
                    printf("-----------------------------\n");
                }

                else
                {
                    for (int i = 0; i < person_count; i++)//displaying members to choose who to modify
                    {
                        printf("Person %d :\n", i+1);
                        displayForDelete(persons[i]);
                    }

                        printf("Which person you want to modify ? ... (1 to %d)\n", person_count);
                        scanf("%d", &index2);//taking the number of person to modify

                    if (index2<1 || index2>person_count)//making sure user picks a valid user
                    {
                        printf("Invalid choice. Please select a valid option.\n");
                        printf("--------------------------------------------\n");
                    }
                    else//starting modifying code
                    {
                        do
                        {
                            display(persons[index2-1]);
                            printf("What do you want to modify ?\n");
                            printf("1. name\n");
                            printf("2. age\n");
                            printf("3. street\n");
                            printf("4. city\n");
                            printf("5. code postal\n");
                            printf("0. back\n");
                            scanf("%d", &choice2);
                            printf("--------------------------\n");//list to choose what to modify
                            
                            switch (choice2)
                            {
                                case 1: //modifying name
                                    printf("Previous name : %s\n", persons[index2-1].name);
                                    printf("Enter the new name ?\n");
                                    scanf("%49s", persons[index2-1].name);
                                    printf("--------------------------\n");
                                break;

                                case 2: //modifying age
                                    printf("Previous age: %d\n", persons[index2-1].age);
                                    printf("Enter the new age ?\n");
                                    scanf("%d", &persons[index2-1].age);
                                    printf("--------------------------\n");
                                break;
                                        
                                case 3: // modifying street
                                    printf("Previous street: %s\n", persons[index2-1].Adress.street);
                                    printf("Enter the new street ?\n");
                                    scanf("%49s", &persons[index2-1].Adress.street);
                                    printf("--------------------------\n");
                                break;

                                case 4: // modifying city
                                    printf("Previous city: %s\n", persons[index2-1].Adress.city);
                                    printf("Enter the new city ?\n");
                                    scanf("%49s", &persons[index2-1].Adress.city);
                                    printf("--------------------------\n");
                                break;

                                case 5: // modifying code postral
                                    printf("Previous code postal: %d\n", persons[index2-1].Adress.code_postal);
                                    printf("Enter the new code postal ?\n");
                                    scanf("%d", &persons[index2-1].Adress.code_postal);
                                    printf("--------------------------\n");
                                break;

                                default://error msg for user if he chooses wrong one
                                    printf("Invalid choice. Please select a valid option.");
                                    printf("--------------------------------------------\n");
                                break;
                            }

                        } while (choice2 != 0);//to keep code running as long as user don't pick 0 to exit
                    }
                }
            break;

            case 4:
                if (person_count == 0)//validating that there is members to display
                {
                    printf("There is no person to display\n");
                    printf("------------------------------\n");
                }

                else
                {
                    for (int i = 0; i < person_count; i++)//displaying memebers
                    {
                        printf("Person %d :\n", i+1);
                        display(persons[i]);
                    }
                }
            break;

            case 0:// 0 to stop the app
                printf("Exiting...\n");
            break;
            
            default://error code if the user takes invalid choice
                printf("Invalid choice. Please select a valid option.\n");
                printf("----------------------------------------------\n");
            break;
        }
    } while (choice != 0);//to keep code running as long as user don't pick 0 to exit
                    
    return 0;
}




