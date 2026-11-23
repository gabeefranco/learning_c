#include <math.h>
#include <stdio.h>

int main() {
  long long n = pow(2, 1000);
  int count = 0;
  long long n_copy = n;
  while (n_copy != 0) {
    count++;
    n_copy /= 10;
  }

  int sum = 0;
  while (count != 0) {
    sum += n % ((long long int) pow(10, count));
    count--;
  }

  printf("Soma: %d\n", sum);
}
