#include <stdio.h>
#include <time.h>

int main(int argc, char * argv[]) {
    char largeArray [4096];
    char accessed;
    clock_t t; 
    t = clock();
    for (int i = 0; i < sizeof(largeArray); i++) {
        accessed = largeArray[i];
    }
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("loop took %f seconds to execute \n", time_taken);

    return 0;
}