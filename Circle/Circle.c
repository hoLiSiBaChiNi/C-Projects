//U10810015地生系許惟智
//修改範例6.26，方向規則改成右、下、左、上的循環，輸出時每n個數字一列。

#include <stdio.h>
#include<assert.h>
#define ARRAYSIZE 10
void main(){
    int n;
    printf("%s\n", "請輸入要建立的陣列維度(奇數):");
    scanf("%d", &n);
    assert(n < ARRAYSIZE);
    assert(n % 2 != 0);
    int array[ARRAYSIZE][ARRAYSIZE];
    for (int i = 0; i < n; i++) {
        printf("%s%d%s\n", "請輸入第", i + 1, "列的元素:");
        for (int j = 0; j < n; j++) {
            scanf("%d", &(array[i][j]));
        }
    }
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    int row = n / 2;
    int col = n / 2;
    int direction = 0;
    int count = 1;
    printf("%s\n", "依右、下、左、上的循環由中間元素繞圈結果為:");
    printf("%-3d", array[row][col]);//中間那個數(起始位置)
    count++;
    for (int dist = 1; dist < n; dist++) {
        for (int step = 0; step < ((dist == n - 1) ? 3 : 2); step++) {
            for (int i = 0; i < dist; i++) {
                row += dr[direction];
                col += dc[direction];
                printf("%-3d", array[row][col]);
                if (count % n == 0) {
                    printf("\n");
                }
                count++;
            }
            direction = ((direction + 1) % 4);

        }

    }
}


