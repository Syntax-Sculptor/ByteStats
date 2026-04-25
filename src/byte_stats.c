// Author: SyntaxSculptor
// File: byte_stats.c
// Date: 4/23/2026

#include "byte_stats.h"
#include <stdlib.h>
#include <stdio.h>

ByteStats analyzeFile(const char* file_name) {
    ByteStats stats;
    stats.total_bytes = 0;
    stats.total_lines = 0;
    stats.non_ascii_bytes = 0;
    stats.printable_ascii = 0;

    FILE* file_ptr = fopen(file_name, "rb");

    if (file_ptr == NULL) {
        printf("Failed to open file!");
        return stats;
    }

    int file_char = fgetc(file_ptr);
    int read_any_bytes = 0;

    while (file_char != EOF) {
        stats.total_bytes++;
        read_any_bytes = 1;

        int next_char = fgetc(file_ptr);
       
        // Ignore trailing newlines.
        if (file_char == '\n' && next_char != EOF) {
            stats.total_lines++;
        }

        // Range of printable characters
        if (file_char >= 32 && file_char <= 126) {
            stats.printable_ascii++;
        }
        else if (file_char > 126) {
            stats.non_ascii_bytes++;
        }

        file_char = next_char;
    }

    if (read_any_bytes) {
        stats.total_lines++;
    }

    fclose(file_ptr);

    return stats;
}