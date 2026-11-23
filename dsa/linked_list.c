#include <stdio.h>
#include <stdlib.h>

struct node {
  int element;
  struct node *next;
};

typedef struct node node;

typedef struct {
  node *head;
} llist;

void llist_new(llist *l) { l->head = NULL; }

void llist_add(llist *l, int e) {
  node *n = malloc(sizeof *n);
  if (n == NULL) {
    return;
  }

  *n = (node){e, NULL};

  if (l->head == NULL) {
    l->head = n;
    return;
  }
  node *temp = l->head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = n;
}

void llist_add_at(llist *l, int idx, int e) {
  node *n = malloc(sizeof *n);
  if (n == NULL) {
    return;
  }

  *n = (node){e, NULL};

  if (l->head == NULL) {
    l->head = n;
    return;
  }

  node *temp = l->head;
  int i = idx - 1;
  while (temp->next != NULL && i != 0) {
    temp = temp->next;
    i--;
  }
  n->next = temp->next;
  temp->next = n;
}

int llist_size(llist *l) {
  node *temp = l->head;
  int i = 0;
  while (temp != NULL) {
    temp = temp->next;
    i++;
  }
  return i;
}
void llist_print(llist *l) {
  printf("llist(");
  node *temp = l->head;
  while (temp != NULL) {
    printf("%d", temp->element);
    if (temp->next != NULL) {
      printf(", ");
    }
    temp = temp->next;
  }
  printf(")\n");
}

void llist_free(llist *l) {
  node *temp = l->head;

  while (temp != NULL) {
    node *next = temp->next;
    free(temp);
    temp = next;
  }

  l->head = NULL;
}

int main(void) {
  llist l;
  llist_new(&l);

  llist_add(&l, 1);
  llist_add(&l, 2);
  llist_add(&l, 3);
  llist_add_at(&l, 2, 67);

  llist_print(&l);
}
