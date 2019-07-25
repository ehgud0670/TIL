#include <stdio.h>

int factorial(int n){

//  if(n<=1){
//    return 1;
//	} else {
//		return n * factorial(n-1);
//	}
  return n>1 ? n*factorial(n-1) : 1 ;
}

int main(){

  int result = factorial(3);
  
  printf("factorial(3) is %d\n", result);

  return 0;
}



// int factorial(3){
//  if(3<=1){
//    return 1; (x)
//	} else {
//    return 3 * factorial(2); (o)
//  }
//}
//
// int factorial(2){
//  if(2<=1){
//    return 1; (x)
//	} else {
//    return 2 * factorial(1); (o)
//  }
//}
//
// int factorial(1){
//  if(1<=1){
//    return 1; (o)
//}
// result : 3 * 2 * 1 = 6 
