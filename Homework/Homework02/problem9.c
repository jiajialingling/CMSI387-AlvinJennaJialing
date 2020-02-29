#include <unistd.h>
int main(int argc, char **argv) {
   int i; 
   
   //iterates 3 times, calling fork() each time
   for(i = 0; i < 3; i++) {
      fork();
   } 
   
   //sleep for 30 seconds
   sleep(30);
}
