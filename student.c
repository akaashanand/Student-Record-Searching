#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read_data();
void search();
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
int main()
{
    printf("\n\n\t\t\t\xB2 \xB2 WELCOME TO STUDENT INFORMATION SYSTEM \xB2 \xB2\n\n");
    read_data();
}
void read_data()
{
    s *stud;
    int roll, found = 0, n, i;
    char line[100];
    char *sp;
    FILE *fp;
    fp = fopen("records.csv", "r");
    stud = (s *)calloc(1000, sizeof(s));
    if (fp == NULL)
    {
        printf("Program teminating....");
        exit(0);
    }
    printf("\nReading the data");
    design();
    printf("\n\nName\tRoll_Number\tD.O.B\t\tDepartment\tEnd semester GPA\n");
    while (fgets(line, 100, fp) != NULL)
    {
        sp = strtok(line, ",");
        stud->roll_no = atoi(sp);
        sp = strtok(NULL, ",");
        strcpy(stud->name, sp);
        sp = strtok(NULL, ",");
        strcpy(stud->dob, sp);
        sp = strtok(NULL, ",");
        strcpy(stud->dept, sp);
        sp = strtok(NULL, ",");
        stud->gpa = atof(sp);
        printf("%d\t%s\t\t%s\t%s\t\t%0.2f\n", stud->roll_no, stud->name, stud->dob, stud->dept, stud->gpa);
        //use fwrite to store data in another temp file.
    }
    printf("\nEnter the roll number of the student you're looking for:\n");
    scanf("%d", &roll);
    //while(use fread)
    if (stud->roll_no == roll)
    {
        found = 1;
        printf("\nStudent details with the roll number AP21110010%d:\n", roll);
        printf("Roll number:  \t%d\n", stud->roll_no);
        fflush(stdin);
        printf("Name:  \t\t%s\n", stud->name);
        fflush(stdin);
        printf("D.O.B:  \t%s\n", stud->dob);
        fflush(stdin);
        printf("Department:  \t%s\n", stud->dept);
        fflush(stdin);
        printf("End Semester GPA: %0.2f\n", stud->gpa);
    }
    if (found == 0)
        printf("Student Record not found!!\n");
    fclose(fp);
}
