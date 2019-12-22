# include <stdio.h>

int main(void){

  FILE * src = fopen("src.bin", "rb");
  FILE * dst = fopen("dst.bin", "wb");
  char buf[20];
  int readCnt;

  if(src==NULL || dst ==NULL){
    printf("파일 오픈 실패 \n");  
   return -1;
	}
  
  while(1){
    readCnt= fread((void*)buf, 1 , sizeof(buf), src);

    if(readCnt< sizeof(buf)) //에러 혹은 파일의 끝에 도달했을 때
		{
      if(feof(src)!=0)
			{

				break;
			}

	}
  

  return 0;
}
