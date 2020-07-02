#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>
#include <stdint.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	struct stat test;

	stat("/dev/null", &test);
	printf("/dev/null: st_dev = %ju\n", (uintmax_t)test.st_dev);
	printf("/dev/null: major = %ju\n", (uintmax_t)major(test.st_dev));
	printf("/dev/null: minor = %ju\n", (uintmax_t)minor(test.st_dev));

	stat("/dev/random", &test);
	printf("/dev/null: st_dev = %ju\n", (uintmax_t)test.st_dev);
	printf("/dev/random: major = %ju\n", (uintmax_t)major(test.st_dev));
	printf("/dev/random: minor = %ju\n", (uintmax_t)minor(test.st_dev));
	
}
