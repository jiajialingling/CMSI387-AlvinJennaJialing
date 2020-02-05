#include <stdio.h>

int main(int argc, char * argv[]) {
    char letters[3];
    int duration[3];
    for (int i = 0; i < 3; i++) {
        printf("\nPlease enter a single letter: ");
        scanf("%s", letters);
        printf("\nPlease enter a integer duration in mS: ");
        scanf("%d", duration);
    }
    printf("KEY -- thread:used:remaining\n\n");
    for (int i = 0; i < 3; i++) {
        if (duration[i] <= 40) {
            printf("%s:%d:done", letters[i], duration[i]);
        }
    }
    if (duration[i])
    
}
