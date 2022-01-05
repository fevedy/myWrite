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
	int size = 0;
	int length = 0;
	char buffer[ 256] = { 0};
	time_t timep;
	memset( buffer, 1, sizeof( buffer));
	fd = open( "/home/pixel/yszhang/close/a.dat", O_WRONLY | O_CREAT);
	printf("open successfully, my fd is %d\n", fd);
	while( true)
	{
		size = rand() % sizeof( buffer) + 1;	
		time( &timep);
		printf("current time is %s\n", asctime( gmtime(&timep)));
		length = write( fd, buffer, size);
		if( length < 0)
		{
			printf("write failed, because: %s\n", strerror( errno));	
			printf("terminal\n");	
			break;
		}
		else
		{
			printf("write successfully, length: %d\n", length);	
		}

		sleep( 1);
		printf("---\n");

	}
	close(fd);
	return 0;
}
