#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int max = 20;
  int n = rand() % (max + 1);
  int guess;

  do {
    printf("Guess the number: \n");
    int r = scanf("%d", &guess);

    if(r != 1) {
      printf("Only numbers allowed!\n");
      int c;
      while((c = getchar()) != '\n' && c != EOF)
        ;
      guess = -1;
      continue;
    }

    if (guess < n) {
      printf("higher than that!\n");
    }
    if (guess > n) {
      printf("lower than that!\n");
    }
  } while (guess != n);

  printf("You found it!\n");
}
