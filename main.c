#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "string.h"


/* For Interfacing */
int input = 0;
char input2;
int input3 = 0;




/* User Requirement */
int ID = 0;
int age;
char name [20];
char grade;
char address[100];
char phonenumber[12];




int main()
{

    list_t *l = list_CreateList();

    WelcomeMessage();


    while(input != 5)
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
            printf("\t\t\t\t\t\t << Inserting Student Info Window >>\n");
            input2 = 'y';

            while(input2 != 'n')
            {
                printf("\nEnter Student Fullname: ");
                scan_string(name,20);
                printf("Enter student age: ");
                scanf("%d", &age);

                printf("Enter The address of student: ");
                scan_string(address,100);

                printf("Enter The phone number of his father: ");
                scan_string(phonenumber,12);

                if((string_length(name)<3) || (string_length(phonenumber)<10) || (string_length(address) < 10) || (age == '\0'))
                {
                    setColor(4);
                    printf("\n\t\t\t\t\tStudent info is wrong or incompleted !\n");
                    setColor(15);
                }

                else
                {
                    if(List_Addstudent(l,name,age,address,phonenumber) == OK)
                    {
                        setColor(2);
                        printf("\n\t\t\t\t\tStudent info is entered successfully !\n");
                        setColor(15);
                    }

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
            printf("\t\t\t\t\t\t <<  Welcome to Student Details Window  >>\n");
            printf("\nDo you want to search by ID or by Name (enter i or n): ");
            input2 = 0;
            scanf(" %c",&input2);

            if(input2 == 'i')
            {
                printf("Enter student ID: ");
                scanf("%d", &ID);
                if(PrintDetailsStudentByID(l,ID) == NOT_FOUND)
                {
                    setColor(4);
                    printf("\n\t\t\tStudent Not Found !\n");
                    setColor(15);
                    break;
                }
            }

            else if(input2 == 'n')
            {
                printf("Enter student Name: ");
                scan_string(name,20);
                if (PrintDetailsStudentByName(l,name,&ID) == NOT_FOUND)
                {
                    setColor(4);
                    printf("\n\t\t\tStudent Not Found !\n");
                    setColor(15);
                    break;
                }
            }

            printf("\n\t\tDo you want to edit the student info ? (y/n): ");
            input2 = 0;
            input3 = 0;
            scanf(" %c",&input2);

            if(input2 == 'y')
            {
                printf("--------------------------------------------------------------------------------------------------------------------\n");

                printf("\n\t\t\tTo edit Name enter:\t\t1\n");
                printf("\t\t\tTo edit Age enter:\t\t2\n");
                printf("\t\t\tTo edit Grade enter:\t\t3\n");
                printf("\t\t\tTo edit Address enter:\t\t4\n");
                printf("\t\t\tTo edit PhoneNumber enter:\t5\n");
                printf("\t\t\tTo Finish enter:\t\t6\n");


                while(input3 != 6)
                {
                    printf("\n\t\tChoose your option >>>> ");

                    scanf("%d", &input3);
                    if(input3 == 1)
                    {
                        printf("\n\t\t\tEnter the New name: ");
                        scan_string(name,20);

                        if(string_length(name)<5)
                        {
                            setColor(4);
                            printf("\n\t\t\t\tWrong Name !\n");
                            setColor(15);
                        }
                        else
                        {
                            setColor(2);
                            List_EditStudent_Name(l,ID,name);
                            printf("\n\t\t\t The name is changed successfully !\n");
                            setColor(15);
                        }

                    }

                    else if(input3 == 2)
                    {
                        printf("\n\t\t\tEnter the New age: ");
                        scanf("%d", &age);
                        if(age == 0)
                        {
                            setColor(4);
                            printf("\n\t\t\t\tWrong Age !\n");
                            setColor(15);
                        }
                        else
                        {
                            setColor(2);
                            List_EditStudent_Age(l,ID,age);
                            printf("\n\t\t\t The Age is changed successfully !\n");
                            setColor(15);
                        }

                    }

                    else if(input3 == 3)
                    {
                        printf("\n\t\t\tEnter the New Grade: ");
                        scanf(" %c", &grade);
                        setColor(2);
                        List_EditStudent_Grade(l,ID,grade);
                        printf("\n\t\t\t The Grade is changed successfully !\n");
                        setColor(15);
                    }

                    else if(input3 == 4)
                    {
                        printf("\n\t\t\tEnter the New Address: ");
                        scan_string(address,100);

                        if(string_length(address)<10)
                        {
                            setColor(4);
                            printf("\n\t\t\t\tWrong Address !\n");
                            setColor(15);
                        }
                        else
                        {
                            setColor(2);
                            List_EditStudent_Address(l,ID,address);
                            printf("\n\t\t\t The Address is changed successfully !\n");
                            setColor(15);
                        }
                    }

                    else if(input3 == 5)
                    {
                        printf("\n\t\t\tEnter the New PhoneNumber: ");
                        scan_string(phonenumber,12);
                        if(string_length(phonenumber)<10)
                        {
                            setColor(4);
                            printf("\n\t\t\t\tWrong PhoneNumber !\n");
                            setColor(15);
                        }
                        else
                        {
                            setColor(2);
                            List_EditStudent_PhoneNumber(l,ID,phonenumber);
                            printf("\n\t\t\t The PhoneNumber is changed successfully !\n");
                            setColor(15);
                        }
                    }

                }
            }

            system("cls");
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
            printf("\t\t\t\t\t\t <<  Deleting Student Window  >>\n");
            printf("Do you want to delete by ID or by Name (enter i or n): ");
            scanf(" %c",&input2);

            if(input2 == 'i')
            {
                printf("Enter student ID: ");
                scanf("%d", &ID);
                if (List_RemoveStudentByID(l,ID) == EMPTY_LIST)
                {
                    setColor(4);
                    printf("\n\t\t\tSorry Empty LIST !\n");
                    setColor(15);
                }
                else if(List_RemoveStudentByID(l,ID) == NOT_FOUND)
                {
                    setColor(4);
                    printf("\n\t\t\t Student Not Found !\n");
                    setColor(15);
                }
                else
                {
                    setColor(2);
                    printf("\n\t\t\t The Student is Deleted successfully !\n");
                    setColor(15);
                }
            }
            else if(input2 == 'n')
            {
                printf("Enter student Name: ");
                scan_string(name,20);
                if (List_RemoveStudentByName(l,name) == EMPTY_LIST)
                {
                    setColor(4);
                    printf("\n\t\t\tSorry Empty LIST !\n");
                    setColor(15);
                }
                else if(List_RemoveStudentByName(l,name) == NOT_FOUND)
                {
                    setColor(4);
                    printf("\n\t\t\t Student Not Found !\n");
                    setColor(15);
                }
                else
                {
                    setColor(2);
                    printf("\n\t\t\t The Student is Deleted successfully !\n");
                    setColor(15);
                }
            }

            break;
        }
    }


    return 0;
}
