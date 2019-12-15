# Algo2
## ���� ����

�� ���� ���� ���� ������ ����� �� ������ ���� ������ �о�ް��� �մϴ�. ������ ���簢�� ���·� �о���� �� ������, x��(�������)�� y��(���� ����)�� ���� ��������� 2���� ��鿡�� �� �� P1(x1,y1)�� P2(x2,y2)�� ǥ���� �� �ֽ��ϴ�. ���� �������� �ļ����� �����Ͽ�, �̹� �о�� ������ ��ġ�� ������ �ļ��� �Ϻθ� ������ ������ �о�ް��� �մϴ�.

�̹� �о�� ������ ��ġ�� ���� ������ �迭 lands�� �ļ����� ��ġ�� ���� ������ �迭 wells, �о�ް��� �ϴ� ������ ��ġ�� ���� �迭 point�� �Ű������� �־��� ��, �����о��� �������� �Ǻ��Ͽ� return �ϵ��� solution�� �ϼ����ּ���.

## ���ѻ���

* lands�� wells�� ���̴� 1�̻� 10,000 �����Դϴ�. 
* lands�� wells�� ����(������ �ļ����� ��ġ)�� \[x1,y1,x2,y2]�� ����ֽ��ϴ�.
* point�� ���̴� 4�Դϴ�. 
* point���� ���� \[x1,y1,x2,y2]�� ����ֽ��ϴ�. 
* x��ǥ�� y��ǥ�� 0 �̻� 1,000,000 ������ �����Դϴ�.


## ����� ��

| lands | wells | point | result |
|-------|-------|-------|--------|
|\[10,0,30,5] \[0,30,20,50], \[30,30,40,40]|\[15,15,25,25],\[40,10,50,20]| \[10,10,30,30,]| true |
|\[0,0,20,10],\[10,20,20,40],\[30,0,50,20]|\[20,40,30,50],\[30,20,50,30]| \[20,30,30,40]| false |


## ����Ǯ�� 

> ���� x,y ���� Ȯ���� ��������. 

������ input ������ x1, x2 �߿� ������ ũ��, y1, y2�߿� ������ ū�� Ȯ���� �� ���� ���ǿ��� ��õǾ����� �ʴ�. 
���� �迭�� x1,y1,x2,y2 ���� minX, maxX, minY, maxY �� �ٽ� ��������.

* like this
```java 
int pMinX = Math.min(point[0], point[2]);
int pMaxX = Math.max(point[0], point[2]);
int pMinY = Math.min(point[1], point[3]);
int pMaxY = Math.max(point[1], point[3]);
```

> lands�� wells�� point�� ��ġ���� Ȯ���ϴ� ���

=> **lands�� wells�� ������ 4�� �� 1����** point�� �����ȿ� ������ ��ġ�� ���̴�!

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

> ���� 

* point�� lands�� ��ġ�� false�� �����Ѵ�. 
* point�� wells�� ��ġ�� true�� �����Ѵ�. 
* point�� lands�� ��ġ�� ������, well���� ��ġ�� ������ false�� �����Ѵ�.

## �ڵ� 

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

