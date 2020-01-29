#include <stdio.h>

int main(int argc, char * argv[]) {
    int numbers [25];
    while (argv[2] != -9999) {
        printf("Enter a number: ");
        gets(numbers);
    }
    int sum = 0;
    for (int i = 0; i < sizeof(numbers); i++) {
        sum = sum + i;
    }
    int avg = sum / 25;
    
    
}
