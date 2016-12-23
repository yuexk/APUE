#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

#define MAXLINE 4096

int main()
{
	char name[L_tmpnam],line[MAXLINE];
	FILE *fp;
	
	printf("%s\n",tmpnam(NULL));
	
	tmpnam(name);
	printf("%s\n",name);
	
	if((fp=tmpfile()) == NULL )
		printf("tmpfile error\n");
	fputs("one line of output\n",fp);
	rewind(fp);
	if(fgets(line,sizeof(line),fp) == NULL )
		printf("fgets error\n");
	fputs(line,stdout);
	return 0;
	
}
