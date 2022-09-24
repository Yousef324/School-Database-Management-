#include <stdio.h>
#include <stdlib.h>
#include "student.h"


int main()
{

    int input = 0;
    char input2;
    int ID = 0;
    int input4;




    int age;
    char name [20];
    char grade;



    char address[100];
    char phonenumber[12];




    WelcomeMessage();



    list_t *l = list_CreateList();



    while(input != 6)
    {
        age = 0;
        grade = 0;
        DisplayMenu();
        printf("\t\t\t\t\t\t Choose your option >>>> ");
        scanf("%d", &input);

        switch(input)
        {

        case 1:
            system("cls");
            printf("\t\t\t\t\t\t << Inserting Student Info >>\n");
            input2 = 'y';
            while(input2 != 'n')
            {
                printf("\nEnter student name: ");
                scan_string(name,20);
                printf("Enter student age: ");
                scanf("%d", &age);
                printf("Enter student grade: ");
                scanf(" %c", &grade);

                printf("Enter The address of student: ");
                scan_string(address,100);

                printf("Enter The phone number of his father: ");
                scan_string(phonenumber,12);


                if(List_Addstudent(l,name,age,grade,address,phonenumber) == OK)
                {
                    setColor(2);
                    printf("\n\t\t\t\t\tStudent info is entered\n");
                    setColor(15);
                }

                printf("\nDo you want to continue (y/n): ");
                scanf(" %c",&input2);

                if(input2 == 'n')
                {
                    system("cls");
                }
            }
            break;







        case 2:

            system("cls");
            printf("\t\t\t\t\t\t <<  Editing Student Info  >>\n");

            printf("Enter Student ID: ");
            scanf("%d", &ID);

            if(PrintDetailsStudentByID(l,ID) == NOT_FOUND)
            {
                setColor(4);
                printf("\n\t\t\t\t\t Student Not Found !\n");
                setColor(15);

            }

            else
            {
                printf("--------------------------------------------------------------------------------------------------------------------\n");

                printf("\n\t\t\tTo edit Name enter:\t\t1\n");
                printf("\t\t\tTo edit Age enter:\t\t2\n");
                printf("\t\t\tTo edit Grade enter:\t\t3\n");
                printf("\t\t\tTo edit Address enter:\t\t4\n");
                printf("\t\t\tTo edit PhoneNumber enter:\t5\n");
                printf("\t\t\tTo Exit enter:\t\t\tany number\n");


                printf("\n\t\tChoose your option >>>> ");

                scanf("%d", &input4);

                if(input4 == 1)
                {
                    printf("\n\t\t\tEnter the New name: ");
                    scan_string(name,20);
                    List_EditStudent_Name(l,ID,name);
                }
                else if(input4 == 2)
                {
                    printf("\n\t\t\tEnter the New age: ");
                    scanf("%d", &age);
                    List_EditStudent_Age(l,ID,age);
                }
                else if(input4 == 3)
                {
                    printf("\n\t\t\tEnter the New Grade: ");
                    scanf(" %c", &grade);
                    List_EditStudent_Grade(l,ID,grade);
                }
                else if(input4 == 4)
                {
                    printf("\n\t\t\tEnter the New Address: ");
                    scan_string(address,100);
                    List_EditStudent_Address(l,ID,address);

                }

                else if(input4 == 5)
                {
                    printf("\n\t\t\tEnter the New PhoneNumber: ");
                    scan_string(phonenumber,12);
                    List_EditStudent_PhoneNumber(l,ID,phonenumber);

                }
                else
                {
                    system("cls");
                    break;
                }
            }
            break;



        case 3:
            system("cls");
            if (List_PrintAllStudents(l) == EMPTY_LIST)
            {
                setColor(4);
                printf("\n\t\t\t\t\tEmpty Database ! \n");
                setColor(15);
            }
            break;



        case 4:
            system("cls");
            printf("\t\t\t\t\t\t <<  Student Info  >>\n");
            printf("Do you want to search by ID or by Name (enter i or n): ");
            input2 = 0;
            scanf(" %c",&input2);

            if(input2 == 'i')
            {
                printf("Enter student ID: ");
                scanf("%d", &ID);
                PrintDetailsStudentByID(l,ID);
            }
            else if(input2 == 'n')
            {
                printf("Enter student Name: ");
                scan_string(name,20);
                PrintDetailsStudentByName(l,name);
            }

            break;


        case 5:
            system("cls");
            printf("\t\t\t\t\t\t <<  Student Info  >>\n");
            printf("Do you want to delete by ID or by Name (enter i or n): ");
            scanf(" %c",&input2);

            if(input2 == 'i')
            {
                printf("Enter student ID: ");
                scanf("%d", &ID);
                List_RemoveStudentByID(l,ID);
            }
            else if(input2 == 'n')
            {
                printf("Enter student Name: ");
                scan_string(name,20);
                List_RemoveStudentByName(l,name);
            }

            break;

        }
    }










    return 0;
}
