#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "../../lib/shell-utils.h"

int main(int argc, char **argv)
{
	assert(argv[1]);
	const char *argvp = argv[1];
	char *ap = argv[1];
	for (;; ++ap, ++argvp) {
		switch (*ap) {
		default:
			++ap;
			break;
		case '\n':
		case '\t':
		case '\r':
		case ' ':
			continue;
		case '\0':
			goto SKIP;
		}
		break;
	}
	for (;; ++ap) {
		switch (*ap) {
		default:
			continue;
		case '\n':
		case '\t':
		case '\r':
		case ' ':
			*ap = '\0';
		case '\0':;
		}
		break;
	}
SKIP:
	puts(argvp);
	return 0;
}
