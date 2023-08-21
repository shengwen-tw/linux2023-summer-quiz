CFLAGS=-I./

SRC=rbtree.c \
	rbtree_int.c \
	stree_int.c

all: perf
	gcc ${CFLAGS} -o s_tree ${SRC} main.c

perf:
	gcc ${CFLAGS} -o perf ${SRC} perf.c
	./perf
	octave plot_csv.m 

clang-format:
	clang-format -i ./*.c

.PHONY: perf
