# Algo2
## 문제 설명

물 좋고 공기 좋은 강원도 양양의 한 개발자 마을 토지를 분양받고자 합니다. 토지는 직사각형 형태로 분양받을 수 있으며, x축(수평방향)과 y축(수직 방향)에 의해 만들어지는 2차원 평면에서 두 점 P1(x1,y1)과 P2(x2,y2)로 표현할 수 있습니다. 마을 곳곳에는 식수원이 존재하여, 이미 분양된 토지와 겹치지 않으며 식수원 일부를 포함한 토지를 분양받고자 합니다.

이미 분양된 토지별 위치를 담은 이차원 배열 lands와 식수원별 위치를 담은 이차원 배열 wells, 분양받고자 하는 토지의 위치를 담은 배열 point가 매개변수로 주어질 때, 토지분양이 가능한지 판별하여 return 하도록 solution을 완성해주세요.

## 제한사항

* lands와 wells의 길이는 1이상 10,000 이하입니다. 
* lands와 wells의 원소(토지와 식수원의 위치)는 \[x1,y1,x2,y2]로 들어있습니다.
* point의 길이는 4입니다. 
* point에는 점이 \[x1,y1,x2,y2]로 들어있습니다. 
* x좌표와 y좌표는 0 이상 1,000,000 이하인 정수입니다.


## 입출력 예

| lands | wells | point | result |
|-------|-------|-------|--------|
|\[10,0,30,5] \[0,30,20,50], \[30,30,40,40]|\[15,15,25,25],\[40,10,50,20]| \[10,10,30,30,]| true |
|\[0,0,20,10],\[10,20,20,40],\[30,0,50,20]|\[20,40,30,50],\[30,20,50,30]| \[20,30,30,40]| false |


## 문제풀이 

> 먼저 x,y 값을 확실히 구분하자. 

들어오는 input 값에서 x1, x2 중에 무엇이 크고, y1, y2중에 무엇이 큰지 확인할 수 없고 조건에도 명시되어있지 않다. 
따라서 배열의 x1,y1,x2,y2 값을 minX, maxX, minY, maxY 로 다시 정리하자.

* like this
```java 
int pMinX = Math.min(point[0], point[2]);
int pMaxX = Math.max(point[0], point[2]);
int pMinY = Math.min(point[1], point[3]);
int pMaxY = Math.max(point[1], point[3]);
```

> lands나 wells가 point와 겹치는지 확인하는 방법

=> **lands나 wells의 꼭지점 4개 중 1개라도** point의 범위안에 있으면 겹치는 것이다!

![qq](https://user-images.githubusercontent.com/38216027/68462073-1ff45680-024f-11ea-9477-29b05c891ceb.png)

* like this 
```java
// t is temp 
public boolean isOverlap(int[] newP, int[] newT){
  int pMinX = newP[0];
  int pMaxX = newP[1];
  int pMinY = newP[2];
  int pMaxY = newP[3];
    
  int tMinX = newT[0];
  int tMaxX = newT[1];
  int tMinY = newT[2];
  int tMaxY = newT[3];

  if(tMaxX > pMinX && tMaxX <= pMaxX){
      if( tMinY >= pMinY && tMinY < pMaxY){
        return false;
      } else if (tMaxY > pMinY && tMaxY <= pMaxY){
        return false;
      }

  } else if (tMinX <= pMinX && tMinX > pMaxX){
      if( tMinY >= pMinY && tMinY < pMaxY){
        return false;
      } else if (tMaxY > pMinY && tMaxY <= pMaxY){
        return false;
      }
  }  
  return false;
}
```

> 이후 

* point와 lands가 겹치면 false를 리턴한다. 
* point와 wells가 겹치면 true를 리턴한다. 
* point가 lands와 겹치지 않지만, well랑도 겹치지 않으면 false를 리턴한다.

## 코드 

```java
    public boolean solution(int[][] lands, int[][] wells, int[] point) {
        int pMinX = Math.min(point[0], point[2]);
        int pMaxX = Math.max(point[0], point[2]);
        int pMinY = Math.min(point[1], point[3]);
        int pMaxY = Math.max(point[1], point[3]);
        int[] newP = {pMinX, pMaxX, pMinY, pMaxY};
        System.out.println("newP = " + Arrays.toString(newP));
        if (isOverlap(newP, lands)) {
            return false;
        }
        return isOverlap(newP, wells);
    }

    private boolean isOverlap(int[] newP, int[][] temps) {
        int pMinX = newP[0];
        int pMaxX = newP[1];
        int pMinY = newP[2];
        int pMaxY = newP[3];

        for (int[] temp : temps) {
            System.out.println("temp = " + Arrays.toString(temp));
            int tMinX = Math.min(temp[0], temp[2]);
            int tMaxX = Math.max(temp[0], temp[2]);
            int tMinY = Math.min(temp[1], temp[3]);
            int tMaxY = Math.max(temp[1], temp[3]);

            if (tMaxX > pMinX && tMaxX <= pMaxX) {
                if (tMinY >= pMinY && tMinY < pMaxY) {
                    return true;
                }
                if (tMaxY > pMinY && tMaxY <= pMaxY) {
                    return true;
                }
            } else if (tMinX >= pMinX && tMinX < pMaxX) {
                if (tMinY >= pMinY && tMinY < pMaxY) {
                    return true;
                }
                if (tMaxY > pMinY && tMaxY <= pMaxY) {
                    return true;
                }
            }
        }
        return false;
    }
```

