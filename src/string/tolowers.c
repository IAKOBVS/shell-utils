#include <stdio.h>
#include "../../lib/shell-utils.h"
#include <assert.h>
int main(int argc, char **argv)
{
	assert(argv[1]);
	char *argp = argv[1];
	for (;; ++argp) {
		switch (*argp) {
		CASE_UPPER
			*argp = *argp - 'A' + 'a';
		default:
			continue;
		case '\0':
			break;
		}
		break;
	}
	fwrite(argv[1], 1, argp - argv[1], stdout);
	return 0;
}
