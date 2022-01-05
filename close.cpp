#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int fd = -1;
	int ret = 0; 
	printf("input the fd num which you want to close:\n");
	scanf("%d", &fd);
	printf("the fd num which you want to close is %d\n", fd);
	ret = close( fd);
	if( ret < 0)
	{
		printf("close failed, because: %s\n", strerror( errno));
		printf("terminal\n");
	}
	else
	{
		printf("close successfully, congratulations\n");
	}


	return 0;
}
