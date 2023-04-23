#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../lib/shell-utils.h"

int main(int argc, char **argv)
{
	assert(argc == 2);
	char *RESTRICT const delim = strrchr(argv[1], '.');
	if (likely(delim))
		*delim = '\0';
	puts(argv[1]);
	return 0;
}
