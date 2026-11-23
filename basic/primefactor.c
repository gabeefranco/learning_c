#include <math.h>
#include <stdio.h>

int main(void) {
  int number;
  printf("Insira um número para ser decomposto em fatores primos\n");
  scanf("%d", &number);

  if (number < 1) {
    printf("Número inválido!\n");
    return 1;
  }

  int originalNumber = number;
  int primeFactors = 0;
  while (number != 1) {
    double limit = sqrt(number);
    int i = 2;
    for (; i <= limit; i++) {
      if (number % i == 0) {
        printf("Fator primo encontrado: %d\n", i);
        primeFactors++;
        number /= i;
        break;
      }
    }
    if (i > limit) {
      printf("Fator primo encontrado: %d\n", number);
      primeFactors++;
      number = 1;
    }
  }

  if (primeFactors == 1) {
    printf("%d é primo!\n", originalNumber);
    return 0;
  }
  printf("Fatores primos encontrados: %d\n", primeFactors);
  return 0;
}
