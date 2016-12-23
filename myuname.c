#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/utsname.h>

int main()
{
	struct utsname name;
	printf("=================打印详细信息================\n");
	if ( uname(&name) == -1 )
		printf("函数调用失败\n");
	printf("sysname\t= [%s]\n",name.sysname);
	printf("nodename\t= [%s]\n",name.nodename);
	printf("release\t= [%s]\n",name.release);
	printf("version\t= [%s]\n",name.version);
	printf("machine\t= [%s]\n",name.machine);
	return 0;
}
