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
    
    if (file_char != EOF) {
        stats.total_lines = 1;
    }
    
    while (file_char != EOF) {
        stats.total_bytes++;

        if (file_char == '\n') {
            stats.total_lines++;
        } 

        file_char = fgetc(file_ptr);
    }
    
    fclose(file_ptr);

    return stats;
}