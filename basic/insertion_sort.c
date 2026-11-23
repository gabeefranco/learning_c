#include <stdio.h>

int main(void) {
  int a[] = {1, 3, 6, 7, 7, 8, 0, 2, 5, 9};
  int l = sizeof(a) / sizeof(a[0]);
  for (int i = 0; i < l; i++) {
    int j = i;
    while (j > 0 && a[j - 1] > a[j]) {
      a[j - 1] = a[j - 1] ^ a[j];
      a[j] = a[j - 1] ^ a[j];
      a[j - 1] = a[j - 1] ^ a[j];

      j--;
    }
  }

  for (int i = 0; i < l; i++) {
    printf("%d\n", a[i]);
  }
}
