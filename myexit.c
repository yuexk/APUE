#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>


static void my_exit1(void);
static void my_exit2(void);

int main()
{
	if (atexit(my_exit2) != 0)
		printf("cann't register my_exit2\n");
	if (atexit(my_exit1) != 0)
		printf("cann't register my_exit1\n");
	if (atexit(my_exit1) != 0)
		printf("cann't register my_exit1\n");
	return 0;
}

static void my_exit1(void)
{
	printf("first exit handler\n");
}

static void my_exit2(void)
{
	printf("second exit handler\n");
}
