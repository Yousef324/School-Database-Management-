

typedef struct student
{
    struct student *next;
    int ID;
    int Age;
    char Name[20];
    char grade;
    char address[100];
    char phoneNumber[12];

} std_t;


typedef struct list
{
    int size;
    struct student *head;

} list_t;



typedef enum
{
    OK,
    EMPTY_LIST,
    NOT_FOUND,
    FAILED

} student_status_t;



void setColor(int ForgC);
void WelcomeMessage(void);
void DisplayMenu(void);


list_t *list_CreateList(void);
student_status_t  List_Addstudent(list_t *list,char *name, int age, char *address, char *phoneNumber);

/***************************** FOR REMOVING Functions ************************************************/

student_status_t List_RemoveStudentByID(list_t *list, int serachID);
student_status_t List_RemoveStudentByName(list_t *list, char *studentname);

/***************************** FOR EDITING Functions ************************************************/
student_status_t List_EditStudent_Name(list_t *list, int OldID, char *NewName);
student_status_t List_EditStudent_Age(list_t *list, int OldID, int NewAge);
student_status_t List_EditStudent_Grade(list_t *list, int OldID, char NewGrade);
student_status_t List_EditStudent_PhoneNumber(list_t *list, int OldID, char *NewPhoneNumber);
student_status_t List_EditStudent_Address(list_t *list, int OldID, char *NewAddress);


/***************************** FOR PRINTING Functions ************************************************/
student_status_t  PrintDetailsStudentByName(list_t *list, char *SearchName, int *RetID);
student_status_t  PrintDetailsStudentByID(list_t *list, int searchID);
student_status_t List_PrintAllStudents(list_t *list);
