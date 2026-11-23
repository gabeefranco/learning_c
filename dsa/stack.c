#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

typedef struct node node;

typedef struct {
  node *head;
} stack;

void stack_new(stack *s) { s->head = NULL; }

int stack_push(stack *s, int v) {
  node *n = malloc(sizeof(*n));
  if (n == NULL) {
    return 0;
  }

  n->value = v;
  n->next = s->head;
  s->head = n;
  return 1;
}

int stack_pop(stack *s, int *out) {
  if (s->head == NULL) {
    return 0;
  }

  node *old_head = s->head;
  *out = old_head->value;
  s->head = old_head->next;

  free(old_head);
  return 1;
}

void stack_free(stack *s) {
  while (s->head != NULL) {
    int out;
    stack_pop(s, &out);
  }
}

int main(void) {
  stack s;
  stack_new(&s);

  stack_push(&s, 67);
  int out;
  stack_pop(&s, &out);
  printf("%d\n", out);

  stack_free(&s);
  return 0;
}
