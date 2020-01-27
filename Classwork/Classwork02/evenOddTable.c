#include <stdio.h>

int main(int argc, char * argv[]) {
    int i;
    char* parity;
    int evens;
    for( i = -10; i < 11; i++ ) {
      if ( i % 2 == 0 ) {
        parity = "Even";
        evens++;
      } else {
        parity = "Odd";
      }
      printf( "%d \t %d \t %s\n" , i, i*i, parity );

    }
    printf( "# of evens: %d\n# of odds: %d\n", evens, 21 - evens );
}
