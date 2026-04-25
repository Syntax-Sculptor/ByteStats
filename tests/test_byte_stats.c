// Author: SyntaxSculptor
// File: test_byte_stat.c
// Date: 4/23/2026

#include <stdlib.h>
#include <assert.h>
#include "byte_stats.h"
#include <stdio.h>

void testStats(
    const ByteStats *stats,
    const char* test_name,
    long total_bytes, 
    long total_lines, 
    long printable_ascii, 
    long non_ascii_bytes
) {
    printf("Now testing unit %s\n", test_name);
    assert(stats->non_ascii_bytes == non_ascii_bytes);
    assert(stats->printable_ascii == printable_ascii);
    assert(stats->total_lines == total_lines);
    assert(stats->total_bytes == total_bytes);
}

int main() {
    // Test 1: Empty file
    ByteStats stats1 = analyzeFile("tests/test_01");
    testStats(&stats1, "test1", 0, 0, 0, 0);

    // Test 2: Single line without trailing newline ("hello")
    ByteStats stats2 = analyzeFile("tests/test_02");
    testStats(&stats2, "test2", 5, 1, 5, 0);

    // Test 3: File containing only one newline
    ByteStats stats3 = analyzeFile("tests/test_03");
    testStats(&stats3, "test3", 1, 1, 0, 0);

    // Test 4: Single line with trailing newline ("hello\n")
    ByteStats stats4 = analyzeFile("tests/test_04");
    testStats(&stats4, "test4", 6, 1, 5, 0);

    // Test 5: Two lines without trailing newline ("hello\nworld")
    ByteStats stats5 = analyzeFile("tests/test_05");
    testStats(&stats5, "test5", 11, 2, 10, 0);

    // Test 6: Two empty lines
    ByteStats stats6 = analyzeFile("tests/test_06");
    testStats(&stats6, "test6", 2, 2, 0, 0);

    printf("All unit tests passed :)\n");

    return EXIT_SUCCESS;
}