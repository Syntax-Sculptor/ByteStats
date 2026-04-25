all: byte_stats

byte_stats:
	gcc -Iinclude src/main.c src/byte_stats.c -o byte_stats

byte_stats_test:
	gcc -Iinclude tests/test_byte_stats.c src/byte_stats.c -o byte_stats_test

test: byte_stats_test
	./byte_stats_test

clean:
	rm -f byte_stats byte_stats_test