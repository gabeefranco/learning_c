#include <stdio.h>
#include <string.h>

size_t my_strlen(const char *S);
char *my_strcpy(char *dst, char *src);

int main() {
  char *str = "Gabriel";
  printf("strlen(Gabriel): %zu\n", my_strlen(str));

  char dest[50];
  my_strcpy(dest, str);
  printf("dest: %s\n", dest);

  char *str2 = "Gabriela";
  char *str3 = "Gabriel";
  printf("strcmp(Gabriel, Gabriela): %d\n", strcmp(str, str2));
  printf("strcmp(Gabriel, Gabriel): %d\n", strcmp(str, str3));

  return 0;
}

size_t my_strlen(const char *s) {
  size_t length = 0;
  while (s[length] != '\0') {
    length++;
  }
  return length;
}

char *my_strcpy(char *dst, char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
  return dst;
}

int my_strcmp(char *s1, char *s2) {
  while (*s1 && *s1 == *s2) {
    s1++;
    s2++;
  }

  return (unsigned char)*s1 - (unsigned char)*s2;
}
