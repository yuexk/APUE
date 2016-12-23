#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pwd.h>
#include<errno.h>
#include<stddef.h>

struct passwd *getpwname( const char *name )
{
	struct passwd *ptr;
	while((ptr = getpwent()) != NULL)
	{
		if (strcmp(ptr->pw_name,name) == 0)
			break;
	}	
	endpwent();
	return ptr;
}

int main()
{
	
}

