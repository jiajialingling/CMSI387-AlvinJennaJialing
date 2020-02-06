#include <stdio.h>

int main(int argc, char * argv[]) {
    char name[30];
    int age = -1;
    int classYear = -1;
    char gender[10];
    char major[40];
    char occupation[50];
    
    printf("What is your name: ");
//    scanf("%s", &answers);
    gets(name, sizeof(name), stdin);
    printf("\nWhat is your age: ");
    scanf("%d", &age);
    printf("\nWhat is your class year: ");
    scanf("%d", &classYear);
//    printf("What is your name: ");
//    scanf("%s", answers);
//    printf("What is your name: ");
//    scanf("%s", answers);
//    printf("What is your name: ");
//    scanf("%s", answers);
    
    printf("====================\n");
    printf("    Demographics    \n");
    printf("====================\n");
    printf("Name: %s\nAge: %d\nClass year: %d\n", name, age, classYear);
}
