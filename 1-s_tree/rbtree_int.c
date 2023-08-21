#include <assert.h>
#include <stddef.h> /* offsetof */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "common.h"
#include "rbtree.h"
#include "rbtree_int.h"

#define rbtreeint_entry(ptr) container_of(ptr, struct rbtreeint, rb_n)

#define rb_root(r) (r->rb_node)
#define rb_left(n) (n->rb_left)
#define rb_right(n) (n->rb_right)

static struct rb_root *tree;

int rbtreeint_init()
{
    tree = calloc(sizeof(struct rb_root), 1);
    assert(tree);
    return 0;
}

static void __rbtreeint_destroy(struct rb_node *n)
{
    if (rb_left(n))
        __rbtreeint_destroy(rb_left(n));

    if (rb_right(n))
        __rbtreeint_destroy(rb_right(n));

    struct rbtreeint *i = rbtreeint_entry(n);
    free(i);
}

int rbtreeint_destroy()
{
    assert(tree);
    if (rb_root(tree))
        __rbtreeint_destroy(rb_root(tree));

    free(tree);
    return 0;
}

struct rbtreeint *rbtreeint_insert(int a)
{
    struct rb_node *parent = NULL;
    struct rb_node *node;
    struct rb_node **node_ptr;

    for (node_ptr = &rb_root(tree); *node_ptr;) {
        parent = *node_ptr;
        node = *node_ptr;

        struct rbtreeint *t = container_of(node, struct rbtreeint, rb_n);
        if (a == t->value)
            return NULL;

        if (a < t->value) {
            node_ptr = &rb_left(node);
        } else if (a > t->value) {
            node_ptr = &rb_right(node);
        }
    }

    /* insert node without considering about the node colors */
    struct rbtreeint *i = calloc(sizeof(struct rbtreeint), 1);
    rb_link_node(&i->rb_n, parent, node_ptr);

    /* repaint colors */
    rb_insert_color(&i->rb_n, tree);

    i->value = a;
    return i;
}

struct rbtreeint *rbtreeint_find(int a)
{
    struct rb_node *n = rb_root(tree);
    while (n) {
        struct rbtreeint *t = rbtreeint_entry(n);
        if (a == t->value)
            return t;

        if (a < t->value)
            n = rb_left(n);
        else if (a > t->value)
            n = rb_right(n);
    }

    return 0;
}

int rbtreeint_remove(int a)
{
    struct rbtreeint *n = rbtreeint_find(a);
    if (!n)
        return -1;

    rb_erase(&n->rb_n, tree);
    free(n);
    return 0;
}

/* ascending order */
static void __rbtreeint_dump(struct rb_node *n, int depth)
{
    if (!n)
        return;

    __rbtreeint_dump(rb_left(n), depth + 1);

    struct rbtreeint *v = rbtreeint_entry(n);
    printf("%d\n", v->value);

    __rbtreeint_dump(rb_right(n), depth + 1);
}

void rbtreeint_dump()
{
    __rbtreeint_dump(rb_root(tree), 0);
}
