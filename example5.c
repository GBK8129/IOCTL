#include <stdio.h>
//#include <stblib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)

int main()
{
	int fd;
	int32_t value, number;

	printf("\nOpening Driver\n");
	fd = open("/dev/eg_device",O_RDWR);
	if(fd<0)
	{
		printf("Cannot open device File\n");
		return 0;
	}


	printf("Enter the value to send\n");
	scanf("%d",&number);
	printf("Writing value to Driver\n");

	ioctl(fd, WR_VALUE, (int32_t*)&number);

	printf("Reading value from Driver\n");
	ioctl(fd, RD_VALUE, (int32_t*)&value);
	printf("Value is %d\n",value);
	printf("Closeing Driver\n");
	close(fd);
	return 0;
}

