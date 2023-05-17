#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../../lib/shell-utils.h"

int main(int argc, char **argv)
{
	assert(argv[1]);
	char *RESTRICT ext = strrchr(argv[1], '.');
	if (likely(ext++))
		puts(ext);
	return 0;
}
