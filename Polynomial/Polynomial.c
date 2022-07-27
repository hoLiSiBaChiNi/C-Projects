// U10810015 地生三 許惟智
//Polynomial
/*
函數原型為 double polynomial(double x, coble coef[], int n);
return value 為多項式計值結果
x為多項式代入的值
coef為係數陣列，coef[0]為常數項係數，coef[k]為x的k次方項係數
n為多項式的次數
*/
#include <stdio.h>
#include <math.h>
#include <assert.h>
#define ARRAYSIZE 30

double polynomial(double x,int coef[],int n) {
    double value = 0;
    double temp = 0;
    for (int i = 0; i <= n; i++) {
        temp = coef[i] * (pow(x, i));
        value += temp;
    }
    return value;
}
void main()
{
    int n = 0;
    double x = 0;
    int coef[30];
    assert(n <= 30);
    printf("===此程式可計算一多項式之值===\n");
    printf("請輸入多項式的次數:\n");
    scanf("%d", &n);
    printf("===請依序輸入x的各次項係數===\n");
    for (int i = 0; i <= n; i++) {
        int temp = 0;
        printf("請輸入x的%d次項係數\n", i);
        scanf("%d", &temp);
        coef[i] = temp;
    }
    printf("請輸入x要帶入的值\n");
    scanf("%lf", &x);
    printf("x為%.2lf的多項式之值為:\n",x);
    printf("%.2lf",polynomial(x, coef, n));
}

