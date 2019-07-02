#include <stdio.h>
  void addTen(int (*arr)[3][4]) {
  int i, j;
  for (i = 0; i < 3; ++i) {
    for (j = 0; j < 4; ++j) {
      printf("%d\n", (*arr)[i][j]);
    }
  }
 }
 int main() {
   int arr[3][4] = { 0, };
   addTen(&arr);
   return 0;
 }

