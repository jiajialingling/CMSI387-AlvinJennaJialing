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
        perror( argv[1] );                           // check if an error occurred
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

    // // open the output file ~ check the flags here
    //  int fd_out = open( argv[2], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR );
    //  if( fd_out < 0 ) {
    //     perror( argv[2] );
    //     return -1;
    //  }

    // // clear any of the file contents
    //  if( ftruncate( fd_out, info.st_size ) < 0 ) {
    //     perror( "Error setting output file size" );
    //     return -1;
    //  }

    // map the output file into memory
     // void *addr_out = mmap( 0, info.st_size, PROT_WRITE, MAP_SHARED, fd_out, 0 );
     // if( addr_out == MAP_FAILED ) {
     //    perror( "Error mapping output file" );
     //    return -1;
     // }

    // Actually copy the file
     if(memchr(addr_in, 'X', info.st_size)) {
       printf("Found X!\n");
       return 0;
     }
     printf("No X. \n");
     return 0;
  }
