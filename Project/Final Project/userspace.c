#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	if (argc != 2) 
	{
		printf("Please provide only one argument- the pathname for the new directory.\n");
		return -1;
	}	
	char *pathname = argv[1];
	char s[100];
	printf("Currently in %s\n", getcwd(s, 100));
	if(syscall(548, pathname) < 0) 
	{
        	printf("Error creating directory %s\n", pathname);
        	return -1;
	}

	printf("New directory %s has been made.\n", pathname);
	printf("Now in new directory %s\n", getcwd(s, 100));
	return 0;
}
