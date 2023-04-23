#include <assert.h>
#include <stdio.h>

#include "../lib/shell-utils.h"

int main(int argc, char **argv)
{
	assert(argc == 2);
	putchar(argv[1][0]);
	return 0;
}
