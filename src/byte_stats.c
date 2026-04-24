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
    int just_found_new_line = 0;

    while (file_char != EOF) {
        stats.total_bytes++;

        if (file_char == '\n') {
            stats.total_lines++;
            just_found_new_line = 1;
        }
        else {
            just_found_new_line = 0;
        }

        if (stats.total_lines == 0) {
            stats.total_lines = 1;
        }

        file_char = fgetc(file_ptr);
    }

    // Exclude trailing newlines
    if (just_found_new_line) {
        stats.total_lines--;
    }
    
    fclose(file_ptr);

    return stats;
}