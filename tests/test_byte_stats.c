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

void testEmptyFileHasZeroCounts() {
    // Setup
    long expected_total_bytes = 0;
    long expected_total_lines = 0;
    long expected_total_printable_ascii_chars = 0;
    long expected_total_non_ascii_bytes = 0;

    // Exercise
    ByteStats stats = analyzeFile("tests/test_01");

    // Verify
    testStats(
        &stats, 
        "emptyFileHasZeroCounts", 
        expected_total_bytes, 
        expected_total_lines, 
        expected_total_printable_ascii_chars, 
        expected_total_non_ascii_bytes
    );
}

void testSingleLineWithoutTrailingNewLine() {
    // Setup
    long expected_total_bytes = 5;
    long expected_total_lines = 1;
    long expected_total_printable_ascii_chars = 5;
    long expected_total_non_ascii_bytes = 0;

    // Exercise
    ByteStats stats = analyzeFile("tests/test_02");

    // Verify
    testStats(
        &stats, 
        "singleLineWithoutTrailingNewLine", 
        expected_total_bytes, 
        expected_total_lines, 
        expected_total_printable_ascii_chars, 
        expected_total_non_ascii_bytes
    );
}

void testFileContainingOnlyOneNewline() {
    // Setup
    long expected_total_bytes = 1;
    long expected_total_lines = 1;
    long expected_total_printable_ascii_chars = 0;
    long expected_total_non_ascii_bytes = 0;

    // Exercise
    ByteStats stats = analyzeFile("tests/test_03");

    // Verify
    testStats(
        &stats, 
        "fileContainingOnlyOneNewLine", 
        expected_total_bytes, 
        expected_total_lines, 
        expected_total_printable_ascii_chars, 
        expected_total_non_ascii_bytes
    );
}

void testSingleLineWithTrailingNewLine() {
    // Setup
    long expected_total_bytes = 6;
    long expected_total_lines = 1;
    long expected_total_printable_ascii_chars = 5;
    long expected_total_non_ascii_bytes = 0;

    // Exercise
    ByteStats stats = analyzeFile("tests/test_04");

    // Verify
    testStats(
        &stats, 
        "singleLineWithTrailingNewLine", 
        expected_total_bytes, 
        expected_total_lines, 
        expected_total_printable_ascii_chars, 
        expected_total_non_ascii_bytes
    );
}

void testTwoLinesWithoutTrailingNewLine() {
    // Setup
    long expected_total_bytes = 11;
    long expected_total_lines = 2;
    long expected_total_printable_ascii_chars = 10;
    long expected_total_non_ascii_bytes = 0;

    // Exercise
    ByteStats stats = analyzeFile("tests/test_05");

    // Verify
    testStats(
        &stats, 
        "twoLinesWithoutTrailingNewLine", 
        expected_total_bytes, 
        expected_total_lines, 
        expected_total_printable_ascii_chars, 
        expected_total_non_ascii_bytes
    );
}

void testTwoEmptyLines() {
    // Setup
    long expected_total_bytes = 2;
    long expected_total_lines = 2;
    long expected_total_printable_ascii_chars = 0;
    long expected_total_non_ascii_bytes = 0;

    // Exercise
    ByteStats stats = analyzeFile("tests/test_06");

    // Verify
    testStats(
        &stats, 
        "twoEmptyLines", 
        expected_total_bytes, 
        expected_total_lines, 
        expected_total_printable_ascii_chars, 
        expected_total_non_ascii_bytes
    );  
}

void testNonAsciiByte() {
    // Setup
    long expected_total_bytes = 1;
    long expected_total_lines = 1;
    long expected_total_printable_ascii_chars = 0;
    long expected_total_non_ascii_bytes = 1;

    // Exercise
    ByteStats stats = analyzeFile("tests/test_07");

    // Verify
    testStats(
        &stats, 
        "nonAsciiByte", 
        expected_total_bytes, 
        expected_total_lines, 
        expected_total_printable_ascii_chars, 
        expected_total_non_ascii_bytes
    );   
}

void testMixedAscii() {
    // Setup
    long expected_total_bytes = 3;
    long expected_total_lines = 2;
    long expected_total_printable_ascii_chars = 1;
    long expected_total_non_ascii_bytes = 1;

    // Exercise
    ByteStats stats = analyzeFile("tests/test_08");

    // Verify
    testStats(
        &stats, 
        "mixedAscii", 
        expected_total_bytes, 
        expected_total_lines, 
        expected_total_printable_ascii_chars, 
        expected_total_non_ascii_bytes
    );   
}

int main() {
    testEmptyFileHasZeroCounts();
    testSingleLineWithoutTrailingNewLine();
    testFileContainingOnlyOneNewline();
    testSingleLineWithTrailingNewLine();
    testTwoLinesWithoutTrailingNewLine();
    testTwoEmptyLines();
    testNonAsciiByte();
    testMixedAscii();
    
    printf("All unit tests passed :)\n");

    return EXIT_SUCCESS;
}