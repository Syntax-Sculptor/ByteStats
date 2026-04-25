// Author: SyntaxSculptor
// File: byte_stats.h
// Date: 4/23/2026

#ifndef BYTE_STATS
#define BYTE_STATS

typedef struct {
    long total_bytes;
    long total_lines;
    long printable_ascii;
} ByteStats;

ByteStats analyzeFile(const char* file_name);

#endif