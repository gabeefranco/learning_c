#include <stdio.h>

void reverse(int *a, int length) {
  int *left = a;
  int *right = a + length - 1;
  while (left < right) {
    int temp = *left;
    *left = *right;
    *right = temp;

    left++;
    right--;
  }
}

int main(void) {
  int numbers[] = {1, 2, 3, 4, 5};
  reverse(numbers, 5);

  for (int i = 0; i < 5; i++) {
    printf("%d\n", numbers[i]);
  }

  return 0;
}
