#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

int globval = 6;
char buf[]="a write to stdout\n";

int main()
{
	int var;
	pid_t pid;
	
	var = 88;
	if ( write(STDOUT_FILENO,buf,sizeof(buf) -1 ) != sizeof(buf) -1 )
		printf("write error\n");
	printf("before fork\n");
	
	if ( (pid = fork()) <0)
	{
		printf("fork error\n");
	} else if (pid == 0){
		globval ++;
		var ++;
	}else{
		sleep(2);
	}
	printf("pid = %ld, glob = %d, var = %d\n",(long)getpid(),globval,var);
	exit(0);
}
