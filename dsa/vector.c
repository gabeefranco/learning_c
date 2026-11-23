#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size;
  size_t capacity;
  int *array;
} vec;

int vec_new(vec *v, int initialCapacity) {
  size_t capacity = initialCapacity * sizeof(int);
  int *a = malloc(capacity);
  v->size = 0;
  v->capacity = capacity;
  v->array = a;
  return a != NULL;
}

int vec_size(vec *v) { return v->size; }

size_t vec_capacity(vec *v) { return v->capacity / sizeof(int); }

int vec_get(vec *v, int i) { return v->array[i]; }

int vec_add(vec *v, int element) {
  if ((size_t)v->size == vec_capacity(v)) {
    size_t newCapacity = (v->size + 10) * sizeof(int);
    int *newArray = realloc(v->array, newCapacity);
    if (newArray == NULL) {
      return 1;
    }
    v->capacity = newCapacity;
    v->array = newArray;
  }
  v->array[v->size] = element;
  v->size++;
  return 0;
}

void vec_print(vec *v) {
  printf("size: %d\n", vec_size(v));
  printf("capacity: %zu\n", vec_capacity(v));
  printf("values: ");
  if (v->size == 0) {
    printf("\n====\n");
    return;
  }
  for (int i = 0; i < vec_size(v); i++) {
    if (i == vec_size(v) - 1) {
      printf("%d\n", vec_get(v, i));
      continue;
    }
    printf("%d, ", vec_get(v, i));
  }
  printf("====\n");
}

void vec_free(vec *v) { free(v->array); }

int main(void) {
  vec v;
  vec_new(&v, 2);
  printf("created vector\n");
  vec_print(&v);

  vec_add(&v, 67);
  printf("added 67 to vector\n");
  vec_print(&v);

  vec_add(&v, 69);
  printf("added 69 to vector\n");
  vec_print(&v);

  vec_add(&v, 42);
  printf("added 42 to vector\n");
  vec_print(&v);

  for (int i = 1; i <= 10; i++) {
    vec_add(&v, i);
  }

  printf("added numbers from 1 to 10 to vector\n");
  vec_print(&v);

  return 0;
}
