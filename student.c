#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read_data();
void search();
void selection();
void login();
typedef struct login
{
    int user_id;
    char password[15];
} L;
typedef struct student
{
    char name[25];
    int roll_no;
    char dob[25];
    char dept[50];
    float gpa;
} s;
void delay(int d)
{
    int i, j;
    for (i = 0; i < d; i++)
    {
        j = i;
    }
}
void design()
{
    for (int i = 0; i < 5; i++)
    {
        delay(50000000);
        printf(".");
    }
}
void login()
{
    system("cls");
    int ch;
    char pass[15], con_pass[15] = "123", user_id[15], con_user_id[15] = "SRM";
    printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2  WELCOME TO SRM AP STUDENT INFORMATION SYSTEM  \xB2\xB2\xB2\n\n");
    printf("\n\t\t\t\t\t\t\t\xB2\xB2\xB2       LOGIN PAGE OF SRM AP STUDENT INFORMATION SYSTEM      \xB2\xB2\xB2\n\n\n");
details:
    printf("\t\t\tEnter the user id:\t\t\t\t");
    fflush(stdin);
    gets(user_id);
    printf("\n\t\t\tEnter your password:\t\t\t\t");
    gets(pass);
    if ((strcmp(pass, con_pass) == 0) && (strcmp(user_id, con_user_id) == 0))
    {
        printf("\n\t\t\tUSER ID MATCH FOUND!!\n");
        printf("\t\t\tPASSWORD MATCH FOUND!!\n\n");
        printf("\t\t\tRedirecting you securely to the main menu");
        design();
        selection();
    }
    else
    {
        printf("\n\t\t\tInvalid credentials\n");
    try_again:
        printf("\n\t\t\tPLEASE CHOOSE AN OPTION FROM THE FOLLLOWING MENU:\n");
        printf("\t\t\t1)TRY AGAIN\n\t\t\t2)EXIT\n\n");
        printf("\t\t\tENTER AN OPTION FROM THE ABOVE MENU(1/2): \t");
        scanf("%d", &ch);
        system("cls");
        printf("\n\n\t\t\t\t\t\t\t\xB2\xB2\xB2      LOGIN PAGE OF SRM AP STUDENT INFORMATION SYSTEM           \xB2\xB2\xB2\n\n");
        switch (ch)
        {
        case 1:
            goto details;
            break;
        case 2:
            printf("\n\t\t\tThank you for your time!!\n");
            printf("\t\t\tDo visit us again!!\n");
            exit(0);
        default:
            printf("\n\n\t\t\tInvalid Choice!\n");
            printf("\t\t\tKindly choose again!\n");
            goto try_again;
            break;
        }
    }
}
int main()
{
    login();
}
void read_data()
{
    s *stud;
    int roll, found = 0, n, i, ch;
    char line[100];
    char *sp;
    FILE *fp, *fr;
    fr = fopen("dummy.txt", "ab+");
    fp = fopen("records.csv", "r");
    stud = (s *)calloc(1000, sizeof(s));
    if (fp == NULL || fr == NULL)
    {
        printf("Program teminating....");
        exit(0);
    }
    printf("\n\n\t\t\tHow many records do you want to enter:\t");
    scanf("%d",&n);
    printf("\n\n\t\t\tReading the data from the excel file");
    design();
    printf("\n\n\t\t\tName\tRoll_Number\tD.O.B\t\tDepartment\tEnd semester GPA\n");
    for (i = 1; i <= n; i++)
    {
        while (fgets(line, 100, fp) != NULL)
        {
            sp = strtok(line, ",");
            stud[i].roll_no = atoi(sp);
            sp = strtok(NULL, ",");
            strcpy(stud[i].name, sp);
            sp = strtok(NULL, ",");
            strcpy(stud[i].dob, sp);
            sp = strtok(NULL, ",");
            strcpy(stud[i].dept, sp);
            sp = strtok(NULL, ",");
            stud[i].gpa = atof(sp);
            printf("\t\t\t%d\t%s\t\t%s\t%s\t\t%0.2f\n", stud[i].roll_no, stud[i].name, stud[i].dob, stud[i].dept, stud[i].gpa);
            fwrite(&stud[i], sizeof(s), 1, fr);
        }
    }
    fclose(fr);
    fclose(fp);
    printf("\n\t\t\tPLEASE SELECT FROM THE FOLLOWING FROM THE FOLLOWING:\n\n");
    printf("\t\t\t1)READING STUDENT RECORDS\n\t\t\t2)SEARCH RECORD\n\t\t\t3)EXIT\n\n");
    printf("\t\t\tEnter your choice: \t\t\t\t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\n\n\t\t\tRedirecting you securely to the display page");
        design();
        read_data();
        break;
    case 2:
        printf("\n\n\t\t\tRedirecting you securely to the search record page");
        design();
        search();
        break;
    case 3:
        printf("\n\t\t\tThank you for your time!!\n");
        printf("\t\t\tDo visit us again!!\n");
        exit(0);
    default:
        printf("\n\n\t\t\tInvalid Choice!\n");
        printf("\t\t\tKindly choose again!\n\n");
        printf("\t\t\tRedirecting you securely to the main menu");
        design();
        selection();
        break;
    }
}
void search()
{
    FILE *fr;
    s stud;
    int found = 0, roll, ch;
    fr = fopen("dummy.txt", "rb+");
    printf("\n\n\t\t\tEnter the roll number of the student you're looking for:\t");
    scanf("%d", &roll);
    while (fread(&stud, sizeof(s), 1, fr))
    {
        if (stud.roll_no == roll)
        {
            found = 1;
            printf("\n\t\t\tStudent details with the roll number AP21110010%d:\n", roll);
            printf("\t\t\tRoll number:  \t%d\n", stud.roll_no);
            fflush(stdin);
            printf("\t\t\tName:  \t\t%s\n", stud.name);
            fflush(stdin);
            printf("\t\t\tD.O.B:  \t%s\n", stud.dob);
            fflush(stdin);
            printf("\t\t\tDepartment:  \t%s\n", stud.dept);
            fflush(stdin);
            printf("\t\t\tEnd Semester GPA: %0.2f\n", stud.gpa);
            break;
        }
    }
    if (found != 1)
    {
        printf("\t\t\tStudent Record not found!!\n");
    }
    fclose(fr);
    printf("\n\t\t\tPLEASE SELECT FROM THE FOLLOWING FROM THE FOLLOWING:\n\n");
    printf("\t\t\t1)READING STUDENT RECORDS\n\t\t\t2)SEARCH RECORD\n\t\t\t3)EXIT\n\n");
    printf("\t\t\tEnter your choice: \t\t\t\t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\n\n\t\t\tRedirecting you securely to the display page");
        design();
        read_data();
        break;
    case 2:
        printf("\n\n\t\t\tRedirecting you securely to the search record page");
        design();
        search();
        break;
    case 3:
        printf("\n\t\t\tThank you for your time!!\n");
        printf("\t\t\tDo visit us again!!\n");
        exit(0);
    default:
        printf("\n\n\t\t\tInvalid Choice!\n");
        printf("\t\t\tKindly choose again!\n\n");
        printf("\t\t\tRedirecting you securely to the main menu");
        design();
        selection();
        break;
    }
}
void selection()
{
    system("cls");
    int ch;
    printf("\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2  WELCOME TO SRM AP STUDENT INFORMATION SYSTEM  \xB2\xB2\xB2\n\n");
    printf("\n\t\t\t\t\t\t\t\xB2\xB2\xB2       MAIN MENU PAGE          \xB2\xB2\xB2\n\n");
    printf("\t\t\tPLEASE SELECT FROM THE FOLLOWING FROM THE FOLLOWING:\n\n");
    printf("\t\t\t1)READING STUDENT RECORDS\n\t\t\t2)SEARCH RECORD\n\t\t\t3)EXIT\n\n");
    printf("\t\t\tEnter your choice: \t\t\t\t");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\n\n\t\t\tRedirecting you securely to the display page");
        design();
        read_data();
        break;
    case 2:
        printf("\n\n\t\t\tRedirecting you securely to the search record page");
        design();
        search();
        break;
    case 3:
        printf("\n\t\t\tThank you for your time!!\n");
        printf("\t\t\tDo visit us again!!\n");
        exit(0);
    default:
        printf("\n\n\t\t\tInvalid Choice!\n");
        printf("\t\t\tKindly choose again!\n\n");
        printf("\t\t\tRedirecting you securely to the main menu");
        design();
        selection();
        break;
    }
}
