// Author: SyntaxSculptor
// File: test_byte_stat.c
// Date: 4/23/2026

#include <stdlib.h>
#include <assert.h>
#include "byte_stats.h"

int main() {
    // Test 1: Empty files
    ByteStats stats1 = analyzeFile("tests/test_01.txt");
    assert(stats1.total_bytes == 0);

    // Test 2: Basic counting ("hello")
    ByteStats stats2 = analyzeFile("tests/test_02.txt");
    assert(stats2.total_bytes == 5);

    return EXIT_SUCCESS;
}