#include <stdio.h>
#include "../../lib/shell-utils.h"
#include <assert.h>

int main(int argc, char **argv)
{
	assert(argv[1]);
	char *argp = argv[1];
	for (;; ++argp) {
		switch (*argp) {
		CASE_LOWER
			continue;
		default:
			return 1;
		case '\0':;
		}
		break;
	}
	return 0;
}
