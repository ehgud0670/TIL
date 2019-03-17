extern int num; // int형 변수 num이 외부에 선언되어 있다.
// extern 선언은 이 num이라는 변수의 정의가 외부에 있다고 말하는 것인데
// 굳이 안해도 implicit하게 선언이 된다.

void Increment(){
  
  num++;

}

int getNum(){

  return num;

}



