#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0;

struct sinfo {
    char fname[50];
    char lname[50];
    int roll;
    float cgpa;
    int cid[10];
} st[55];

void add_student()
{
    printf("Add the Student's Details\n");
    printf("-------------------------\n");
    printf("Enter the first name of the student: ");
    scanf("%s", st[i].fname);
    printf("Enter the last name of the student: ");
    scanf("%s", st[i].lname);
    printf("Enter the Roll Number: ");
    scanf("%d", &st[i].roll);
    printf("Enter the CGPA obtained: ");
    scanf("%f", &st[i].cgpa);
    printf("Enter the course ID of each course (5 courses): ");
    for (int j = 0; j < 5; j++) {
        scanf("%d", &st[i].cid[j]);
    }
    i++;
}

void find_rl()
{
    int x;
    printf("Enter the Roll Number of the student: ");
    scanf("%d", &x);
    for (int j = 0; j < i; j++) {
        if (x == st[j].roll) {
            printf("The Student's Details are:\n");
            printf("First name: %s\n", st[j].fname);
            printf("Last name: %s\n", st[j].lname);
            printf("CGPA: %f\n", st[j].cgpa);
            printf("Course IDs: ");
            for (int k = 0; k < 5; k++) {
                printf("%d ", st[j].cid[k]);
            }
            printf("\n");
            return;
        }
    }
    printf("No student found with the given Roll Number.\n");
}

void find_fn()
{
    char a[50];
    printf("Enter the First Name of the student: ");
    scanf("%s", a);
    int c = 0;
    for (int j = 0; j < i; j++) {
        if (strcmp(st[j].fname, a) == 0) {
            printf("The Student's Details are:\n");
            printf("First name: %s\n", st[j].fname);
            printf("Last name: %s\n", st[j].lname);
            printf("Roll Number: %d\n", st[j].roll);
            printf("CGPA: %f\n", st[j].cgpa);
            printf("Course IDs: ");
            for (int k = 0; k < 5; k++) {
                printf("%d ", st[j].cid[k]);
            }
            printf("\n");
            c = 1;
            break;
        }
    }
    if (c == 0) {
        printf("No student found with the given First Name.\n");
    }
}

void find_c()
{
    int id;
    printf("Enter the course ID: ");
    scanf("%d", &id);
    int c = 0;
    for (int j = 0; j < i; j++) {
        for (int d = 0; d < 5; d++) {
            if (id == st[j].cid[d]) {
                printf("The Students Details are:\n");
                printf("First name: %s\n", st[j].fname);
                printf("Last name: %s\n", st[j].lname);
                printf("Roll Number: %d\n", st[j].roll);
                printf("CGPA: %f\n", st[j].cgpa);
                c = 1;
                break;
            }
        }
    }
    if (c == 0) {
        printf("No student found enrolled in the given course ID.\n");
    }
}

void tot_s()
{
    printf("The total number of students is %d\n", i);
    printf("You can have a maximum of 50 students.\n");
    printf("You can have %d more students.\n", 50 - i);
}

void del_s()
{
    int a;
    printf("Enter the Roll Number of the student you want to delete: ");
    scanf("%d", &a);
    for (int j = 0; j < i; j++) {
        if (a == st[j].roll) {
            for (int k = j; k < 49; k++) {
                st[k] = st[k + 1];
            }
            i--;
            printf("The Roll Number is removed successfully.\n");
            return;
        }
    }
    printf("No student found with the given Roll Number.\n");
}

void up_s()
{
    printf("Enter the roll number to update the entry: ");
    int x;
    scanf("%d", &x);
    for (int j = 0; j < i; j++) {
        if (st[j].roll == x) {
            printf("1. First name\n");
            printf("2. Last name\n");
            printf("3. Roll Number\n");
            printf("4. CGPA\n");
            printf("5. Courses\n");
            printf("Enter your choice: ");
            int z;
            scanf("%d", &z);
            switch (z) {
                case 1:
                    printf("Enter the new first name: ");
                    scanf("%s", st[j].fname);
                    break;
                case 2:
                    printf("Enter the new last name: ");
                    scanf("%s", st[j].lname);
                    break;
                case 3:
                    printf("Enter the new roll number: ");
                    scanf("%d", &st[j].roll);
                    break;
                case 4:
                    printf("Enter the new CGPA: ");
                    scanf("%f", &st[j].cgpa);
                    break;
                case 5:
                    printf("Enter the new course IDs (5 courses): ");
                    for (int k = 0; k < 5; k++) {
                        scanf("%d", &st[j].cid[k]);
                    }
                    break;
            }
            printf("Updated successfully.\n");
            return;
        }
    }
    printf("No student found with the given Roll Number.\n");
}

int main()
{
    int choice;
    while (1) {
        printf("Tasks:\n");
        printf("1. Add Student Details\n");
        printf("2. Find Student Details by Roll Number\n");
        printf("3. Find Student Details by First Name\n");
        printf("4. Find Student Details by Course ID\n");
        printf("5. Find Total Number of Students\n");
        printf("6. Delete Student Details by Roll Number\n");
        printf("7. Update Student Details by Roll Number\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                find_rl();
                break;
            case 3:
                find_fn();
                break;
            case 4:
                find_c();
                break;
            case 5:
                tot_s();
                break;
            case 6:
                del_s();
                break;
            case 7:
                up_s();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
