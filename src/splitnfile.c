#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../lib/shell-utils.h"

#define FILENAME argv[2]
#define NUM_CHUNKS argv[1]

int main(int argc, char **argv)
{
	char delim;
	switch (argc) {
	default:
		puts("usage: ./splitnfile <n-chunks> <filename> <delim>\ndelim defaults to \\n if not given");
		return 1;
	case 3:
		delim = '\n';
		break;
	case 4:
		delim = argv[3][0];
	}
	size_t file_size = sizeof_file(FILENAME);
	assert(file_size);
	char *filebuf = malloc(file_size + 1);
	assert(filebuf);
	cat(filebuf, FILENAME, file_size);
	const int num_chunks = strtol(NUM_CHUNKS, NULL, 10);
	size_t chunksz = file_size / num_chunks;
	char *p = filebuf;
	char *end = filebuf + file_size;
	char *nul;
	int i = 0;
	FILE *fp;
	char filepath[64];
	while (p < end) {
		if (i != num_chunks - 1) {
			nul = memchr(p + chunksz, delim, chunksz);
			assert(nul);
			*nul = '\0';
		} else {
			nul = filebuf + file_size;
		}
		sprintf(filepath, "%s_%d", FILENAME, i++);
		fp = fopen(filepath, "w");
		assert(fp);
		fwrite(p, 1, nul - p, fp);
		fclose(fp);
		p = nul + 1;
	}
	free(filebuf);
	return 0;
}
