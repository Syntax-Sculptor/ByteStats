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
    assert(stats1.total_lines == 0);

    // Test 2: Basic counting ("hello")
    ByteStats stats2 = analyzeFile("tests/test_02.txt");
    assert(stats2.total_bytes == 5);

    // Test 3: Line counting
    ByteStats stats3 = analyzeFile("tests/test_03.txt");
    assert(stats3.total_lines == 2);

    // Test 4: Not counting trailing newlines
    ByteStats stats4 = analyzeFile("tests/test_04.txt");
    assert(stats4.total_lines == 1);

    // Test 5: \n only
    ByteStats stats5 = analyzeFile("tests/test_05.txt");
    assert(stats5.total_lines == 1);

    return EXIT_SUCCESS;
}