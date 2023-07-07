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
	char *RESTRICT ext = memrchr(argv[1], '.', len);
	if (unlikely(!ext))
		return 1;
	fwrite(ext + 1, 1, len - (ext + 1 - argv[1]), stdout);
	return 0;
}
