#include <stdio.h>

int main(int argc, char * argv[]) {
    char name[30];
    int age = -1;
    int classYear = -1;
    char gender[10];
    char state[50];
    char siblings[4];

    printf("What is your name: ");
    fgets(name, sizeof(name), stdin);
    //this is to handle the extra '\n' character at the end of the array
    for (int i = 0; i <= sizeof(name); i++) {
        if(name[i] == '\n') {
            name[i] = '\0';
            break;
        }
    }

    printf("\nWhat is your age: ");
    scanf("%d", &age);
    printf("\nWhat is your class year: ");
    scanf("%d", &classYear);
    printf("\nWhat is your gender: ");
    scanf("%s", gender);
    printf("\nWhich state are you from: ");
    scanf("%s", state);
    printf("\nDo you have siblings (Yes/No): ");
    scanf("%s", siblings);
    printf("\nThank you!\n");

    printf("\n====================\n");
    printf("    Demographics    \n");
    printf("====================\n");
    printf("Name: %s\nAge: %d\nClass year: %d\nGender: %s\nState: %s\nSiblings: %s\n\n", name, age, classYear, gender, state, siblings);
}
