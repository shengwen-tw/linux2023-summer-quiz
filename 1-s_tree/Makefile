CFLAGS=-I./

SRC=main.c \
	rbtree.c \
	rbtree_int.c \
	stree_int.c

all:
	gcc ${CFLAGS} -o s_tree ${SRC} 

clang-format:
	clang-format -i ./*.c
