#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/time.h>
#include<errno.h>
#include<bits/stat.h>

int main( int argc, char *argv[])
{
	int i,fd;
	struct stat statbuf;
	struct timespec times[2];

	for ( i = 0; i<argc; i++){
		if ( stat(argv[i],&statbuf) == -1 ){
			printf("%s,stat errror",argv[i]);
			continue;
		}
		if ( (fd = open(argv[1],O_RDWR|O_TRUNC)) == -1 ){
			printf("%s:open error",argv[i]);
			continue;
		}
		times[1] = statbuf.st_mtim;
		times[0] = statbuf.st_atim;
		if ( futimens(fd,times) == -1 ){
			printf("%s:futimens error",argv[i]);
		} 
		close(fd);
	}
	return 0;
}
