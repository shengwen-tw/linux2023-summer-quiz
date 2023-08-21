#ifndef __STTREE_H__
#define __STTREE_H__

#define st_root(r) (r->root)
#define st_left(n) (n->left)
#define st_right(n) (n->right)
#define st_rparent(n) (st_right(n)->parent)
#define st_lparent(n) (st_left(n)->parent)
#define st_parent(n) (n->parent)

enum st_dir { LEFT, RIGHT };

struct st_node {
    short hint;
    struct st_node *parent;
    struct st_node *left, *right;
};

struct st_root {
    struct st_node *root;
};

struct streeint {
    int value;
    struct st_node st_n;
};

int streeint_init();
int streeint_destroy();
struct streeint *streeint_insert(int a);
struct streeint *streeint_find(int a);
int streeint_remove(int a);
void streeint_dump();

#endif
