all:
	clang++ lib/main.cpp lib/hamming.cpp -o hamming
test:
	clang++ tests/test.cpp lib/hamming.cpp -o test
clear:
	rm -f hamming test