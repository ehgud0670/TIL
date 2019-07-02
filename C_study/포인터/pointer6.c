#include <stdio.h>
  void addTen(int (*arr)[3][4], int n) {
  int i, j;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < 4; ++j) {
      printf("%d\n", (*arr)[i][j]);
    }
  }
 }
 int main() {
   int arr[3][4] = { 0, };
   addTen(&arr, 3);
   return 0;
 }

