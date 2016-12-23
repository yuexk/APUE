#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/stat.h>

void make_temp( char *template );

int main()
{
	char good_template[] = "/tmp/dirXXXXXX";
	/*bad_template 相关的字符串不能进行修改,再创建文件的时候会出现相应的错误*/
	char *bad_template = "/tmp/dirXXXXXX";
	
	printf("trying to create first temp file...\n");
	make_temp(good_template);
	
	printf("trying to create second temp file...\n");
	make_temp(bad_template);
	exit(0);
}

void make_temp( char *template )
{
	int fd;
	struct stat sbuf;
	
	if( (fd = mkstemp(template)) == -1 )
	{
		printf("cann't create temp file\n");
	}
	printf("temp name = %s\n",template);
	close(fd);
	if( stat(template,&sbuf) == -1)
	{
		/*ENOENT 错误为：No such file or directory*/
		if( errno == ENOENT )
			printf("file dosen't exist\n");
		else
			printf("stat failed\n");
	}else
	{
		printf("file exists\n");
		/*释放相关的文件*/
		unlink(template);
	}
}
