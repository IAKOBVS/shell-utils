#include <stdio.h>
#include <stdlib.h>

#include "../../lib/shell-utils.h"

int main(int argc, char **argv)
{
	if (unlikely(argc != 3)) {
		puts("usage: ./getncharof <Nth index> <string>\ne.g.,\n./getncharof 1 hello\ne");
		return 1;
	}
	putchar(argv[2][strtol(argv[1], NULL, 10)]);
	return 0;
}
