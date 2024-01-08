all:
	clang vice.c init.c bitboards.c -o vice
	./vice