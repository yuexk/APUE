#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	if ( chdir("/tmp") == -1)
		printf("chdir failed\n");
	printf("chdir to /tmp successed\n");
	return 0;
}
