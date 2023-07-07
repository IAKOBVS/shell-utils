#if defined(__GLIBC__) ||  defined(__GNUC__)
#	define _GNU_SOURCE
#else
#	define memrchr(s, c, n) strrchr(s, c)
#endif

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../../lib/shell-utils.h"

int main(int argc, char **argv)
{
	assert(argv[1]);
	size_t len = strlen(argv[1]);
	char *RESTRICT const delim = memrchr(argv[1], '.', len);
	if (likely(delim))
		len = delim - argv[1];
	fwrite(argv[1], 1, len, stdout);
	return 0;
}
