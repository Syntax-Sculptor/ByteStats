byte_stats:
	gcc -Iinclude tests/test_byte_stats.c src/byte_stats.c -o byte_stats

all: byte_stats

clean:
	rm -f byte_stats