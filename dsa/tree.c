#include <stdlib.h>

typedef struct node {
  int value;
  struct node *parent;
  struct node *first_child;
  struct node *next_sibling;
} node;

typedef struct {
  node *root;
  size_t size;
} tree;

void tree_new(tree *t, int root_value) {
  t->root = malloc(sizeof(node));
  *(t->root) = (node){root_value};
  t->size = 0;
}

node *tree_insert(tree *t, node *parent, int value) {
  if (t == NULL) {
    return NULL;
  }

  if (parent == NULL && t->root != NULL) {
    return NULL;
  }

  if (parent != NULL && t->root == NULL) {
    return NULL;
  }

  node *n = malloc(sizeof(node));
  if (n == NULL) {
    return NULL;
  }

  *n = (node){
      .parent = parent,
      .value = value,
      .first_child = NULL,
      .next_sibling = NULL,
  };

  if (parent == NULL && t->root == NULL) {
    t->root = n;
    return n;
  }

  node *temp = parent->first_child;
  if (temp == NULL) {
    parent->first_child = n;
    return n;
  }
  while (temp->next_sibling != NULL) {
    temp = temp->next_sibling;
  }
  temp->next_sibling = n;
  return n;
}

node *tree_find_from(tree *t, node *start, int value) {
  if (t == NULL) {
    return NULL;
  }
  if (start == NULL) {
    return NULL;
  }

  if (start->value == value) {
    return start;
  }

  node *temp = start->first_child;
  while (temp != NULL) {
    node *result = tree_find_from(t, temp, value);
    if (result != NULL) {
      return result;
    }
    temp = temp->next_sibling;
  }

  return NULL;
}

node *tree_find(tree *t, int value) {
  return tree_find_from(t, t->root, value);
}
