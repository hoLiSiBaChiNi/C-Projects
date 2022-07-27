// U10810015地生三 許惟智
#include<stdio.h>


void main()
{
    for (int i = 1 ; i < 8 ; i=i+3) {
        for (int j = 1; j < 10; j++) {
            int X = i + 1;
            int Y = i + 2;
            int k = i * j;
            int Xm = X * j;
            int Ym = Y * j;
            printf("%d* %d =%2d\t%d* %d =%2d\t%d* %d =%2d\n",i,j,k,X,j,Xm,Y,j,Ym);
         
        }
        printf("\n");
    }
}
