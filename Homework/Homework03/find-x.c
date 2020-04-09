#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

  int main( int argc, char *argv[] ) {
     if( argc != 2 ) {
        perror("Error: no input file");
        return -1;
     }

    // open the file READ-ONLY
     int fd_in = open( argv[1], O_RDONLY );
     if( fd_in < 0 ) {
        perror( argv[1] );
        return -1;
     }
     struct stat info;
     if( fstat( fd_in, &info ) < 0 ) {
        perror( "Error stating input file" );
        return -1;
     }

    // map the input file into memory
     void *addr_in = mmap( 0, info.st_size, PROT_READ, MAP_SHARED, fd_in, 0 );
     if( addr_in == MAP_FAILED ) {
        perror( "Error mapping input file" );
        return -1;
     }

    // Search the file
     if(memchr(addr_in, 'X', info.st_size)) {
       printf("Found X!\n");
       return 0;
     }
     printf("No X. \n");
     return 0;
  }
