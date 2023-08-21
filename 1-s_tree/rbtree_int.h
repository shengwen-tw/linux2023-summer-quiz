#ifndef __RBTREE_INT_H__
#define __RBTREE_INT_H__

#include "rbtree_types.h"

struct rbtreeint {
    int value;
    struct rb_node rb_n;
};

int rbtreeint_init();
int rbtreeint_destroy();
struct rbtreeint *rbtreeint_insert(int a);
struct rbtreeint *rbtreeint_find(int a);
int rbtreeint_remove(int a);
void rbtreeint_dump();

#endif
