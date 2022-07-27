//U10810015地生三許惟智實作eval_f函式計算f(x,y)=4x-6y並求最大值

#include <stdio.h>

#define N 256
int eval_f(int* iptr[], int n, int* index) {
    int temp;
    int i;
    int value = 4 * (*iptr[0]) - 6 * (*(iptr[0] + 1));
    *index = 0;
    for (int i = 1; i < n; i++) {
        temp = 4 * (*iptr[i]) - 6 * (*(iptr[i] + 1));
        if (temp >= value) {
            value = temp;
            *index = i;
        }
    }
    return value;
}



int main(void)
{
    int n = 0;
    int x, y;
    int xy[2 * N];
    int xy_n = 0;
    int max, max_index;
    int* iptr[N];

    while (scanf("%d%d", &x, &y) != EOF) {
        iptr[n] = &(xy[xy_n]);
        n++;
        xy[xy_n] = x;
        xy_n++;
        xy[xy_n] = y;
        xy_n++;
    }

    max = eval_f(iptr, n, &max_index);
    printf("%d %d\n", max, max_index);

    return 0;
}