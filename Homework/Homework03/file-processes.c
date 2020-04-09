#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
  pid_t returnedValue = fork();
  int input;
  int fd;

  if(returnedValue < 0){
    perror("error forking");
    return -1;
  } else if (returnedValue == 0){
    input = open("/etc/passwd", O_RDONLY);
    if(input < 0){
      perror("error opening passwd");
      return -1;
    }
    fd = dup2(input, STDIN_FILENO);
    if(fd < 0){
      perror("error dup2");
      return -1;
    }
    close(input);
    execlp("tr", "tr", "a-z", "A-Z", NULL);
    perror("error executing tr");
    return -1;
  } else {
      if(waitpid(returnedValue, 0, 0) < 0){
        perror("error waiting for child");
        return -1;
      }
  }
}
