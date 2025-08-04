#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    char branch[50];
    int batch_no;
};

void main() {
    struct Student s1;
    struct Student *ptr = &s1;

    printf("Enter Roll No: ");
    scanf("%d", &ptr->roll_no);
    printf("Enter Name: ");
    scanf("%s", ptr->name);
    printf("Enter Branch: ");
    scanf("%s", ptr->branch);
    printf("Enter Batch No: ");
    scanf("%d", &ptr->batch_no);

    printf("\nStudent Info:\n");
    printf("Roll No: %d\n", ptr->roll_no);
    printf("Name: %s\n", ptr->name);
    printf("Branch: %s\n", ptr->branch);
    printf("Batch No: %d\n", ptr->batch_no);

}
