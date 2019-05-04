# include <stdio.h>

int main(void){
  
  float num1;
  double num2;
  long double num3;

  scanf("%f %lf %Lf", &num1, &num2, &num3);
  printf("num1: %f \n", num1);
  printf("num2: %lf \n", num2);
  printf("num3: %Lf \n", num3);
  
  return 0;
}
