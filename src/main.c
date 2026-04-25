#include <stdlib.h>
#include <stdio.h>
#include "byte_stats.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: byte_stats [file_name]");
        return EXIT_FAILURE;
    }

    char* file_name = argv[1];
    ByteStats stats = analyzeFile(file_name);

    printf("ANALYSIS FOR %s\n", file_name);
    printf("---\n");
    
    printf("Total Bytes:                     %d\n", stats.total_bytes);
    printf("Total Lines:                     %d\n", stats.total_lines);
    printf("Total printable ASCII bytes:     %d\n", stats.total_lines);
    printf("Total non-printable ASCII bytes: %d\n", stats.non_ascii_bytes);

    return EXIT_SUCCESS;

}