#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "../../lib/shell-utils.h"

int main(int argc, char **argv)
{
	assert(argv[1]);
	char *RESTRICT ap = argv[1] + strlen(argv[1]) - 1;
	for (;; --ap) {
		if (unlikely(ap <= argv[1]))
			goto SKIP;
		switch (*ap) {
		default:
			*(ap-- + 1) = '\0';
			break;
		case '\n':
		case '\t':
		case '\r':
		case ' ':
			continue;
		}
		break;
	}
	for (;; --ap) {
		if (unlikely(ap <= argv[1]))
			break;
		switch (*ap) {
		default:
			continue;
		case '\n':
		case '\t':
		case '\r':
		case ' ':
			++ap;
		}
		break;
	}
SKIP:
	puts(ap);
	return 0;
}
