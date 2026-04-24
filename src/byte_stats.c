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

    FILE* file_ptr = fopen(file_name, "rb");

    if (file_ptr == NULL) {
        printf("Failed to open file!");
        return stats;
    }

    int file_char = fgetc(file_ptr);
    int is_last_byte_new_line = 0;
    int read_any_bytes = 0;

    while (file_char != EOF) {
        stats.total_bytes++;
        read_any_bytes = 1;

        if (file_char == '\n') {
            is_last_byte_new_line = 1;
        }
        else if (is_last_byte_new_line) {
            stats.total_lines++;
            is_last_byte_new_line = 0;
        }

        file_char = fgetc(file_ptr);
    }

    if (read_any_bytes) {
        stats.total_lines++;
    }

    fclose(file_ptr);

    return stats;
}