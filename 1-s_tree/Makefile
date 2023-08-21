CFLAGS=-I./

SRC=main.c \
	rbtree.c

all:
	gcc ${CFLAGS} -o s_tree ${SRC} 

clang-format:
	clang-format -i ./*.c
