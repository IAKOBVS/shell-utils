#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "../lib/shell-utils.h"

int main(int argc, char **argv)
{
	assert(argv[1]);
	putchar(argv[1][strlen(argv[1]) - 1]);
	return 0;
}
