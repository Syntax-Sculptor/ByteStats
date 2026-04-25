// Author: SyntaxSculptor
// File: test_byte_stat.c
// Date: 4/23/2026

#include <stdlib.h>
#include <assert.h>
#include "byte_stats.h"

int main() {
    // Test 1: Empty file
    ByteStats stats1 = analyzeFile("tests/test_01");
    assert(stats1.total_bytes == 0 && stats1.total_lines == 0);

    // Test 2: Single line without trailing newline ("hello")
    ByteStats stats2 = analyzeFile("tests/test_02");
    assert(stats2.total_bytes == 5 && stats2.total_lines == 1 && stats2.printable_ascii == 5);

    // Test 3: File containing only one newline
    ByteStats stats3 = analyzeFile("tests/test_03");
    assert(stats3.total_lines == 1 && stats3.total_bytes == 1);

    // Test 4: Single line with trailing newline ("hello\n")
    ByteStats stats4 = analyzeFile("tests/test_04");
    assert(stats4.total_lines == 1 && stats4.total_bytes == 6 && stats4.printable_ascii == 5);

    // Test 5: Two lines without trailing newline ("hello\\nworld")
    ByteStats stats5 = analyzeFile("tests/test_05");
    assert(stats5.total_lines == 2 && stats5.total_bytes == 11);

    // Test 6: Two empty lines
    ByteStats stats6 = analyzeFile("tests/test_06");
    assert(stats6.total_lines == 2 && stats6.total_bytes == 2);
    return EXIT_SUCCESS;
}