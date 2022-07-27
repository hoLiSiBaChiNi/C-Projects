//U10810015 地生三 許惟智
//百位數字運算
/*
寫一個C程式，符合下列要求:
1.提示使用者輸入兩個一百位以內的數值(輸入的數值假設均為正值)
2.詢問使用者要進行加法或減法計算
3.執行計算後顯示計算結果，如果數值超出範圍，要顯示數值超出範圍無法計算
4.詢問使用者是否要再次計算，是就回1，否則就結束程式。
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#define ARRAYSIZE 101
void main(){
    char n1[ARRAYSIZE];
    char n2[ARRAYSIZE];
    int n1Array[ARRAYSIZE];
    int n2Array[ARRAYSIZE];
    int anserArray[ARRAYSIZE] = {0};

    printf("%s\n", "請輸入第一個百位數字:");
    scanf("%s", &n1);
    assert(n1[0] != "0");
    printf("%s\n", "請輸入第二個百位數字:");
    scanf("%s", &n2);
    printf("\n");
    assert(n2[0] != "0");

    //計算位數並轉成int陣列
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; n1[i]!= 0 ; i++) {
        count1++;
        n1Array[i] = n1[i] - 48;
    }
    printf("The nubers of digits for n1: %d\n", count1);
    for (int i = 0; n2[i]!= 0 ; i++) {
        count2++;
        n2Array[i] = n2[i] - 48;
    }
    printf("The nubers of digits for n2: %d\n", count2);

    //選擇要加法還是減法
    int choice;
    printf("Pls chooce PLUS(1) or MINUS(0):\n");
    scanf("%d", &choice);

    //確認是否數字超出範圍跟加減法選項
    assert(count1 <= 100);
    assert(count2 <= 100);
    assert(choice == 1 || choice == 0);

    //對齊兩int陣列
    if (count1 > count2) {//n1>n2
        int delta = count1 - count2;
        int temp[ARRAYSIZE];
        for (int i = 0; i < count2; i++) {
            temp[i] = n2Array[i];
        }
        for (int i = 0; i < count2 ;i++) {
            n2Array[i + delta] = temp[i];
        }
        for (int i = 0; i < delta; i++) {
            n2Array[i] = 0;
        }
    }
    else if (count2 > count1) {//n2>n1
        int delta = count2 - count1;
        int temp[ARRAYSIZE];
        for (int i = 0; i < count1; i++) {
            temp[i] = n1Array[i];
        }
        for (int i = 0; i < count1; i++) {
            n1Array[i + delta] = temp[i];
        }
        for (int i = 0; i < delta; i++) {
            n1Array[i] = 0;
        }
    }

    //加法
    int maxCount = (count1 >= count2) ? count1 : count2;
    if(choice == 1){
        int carry = 0;
        for (int i = maxCount - 1; i >= 0; i--) {
            int counter = 0;
            counter = n1Array[i] + n2Array[i]+carry;
            if (counter < 10) {
                anserArray[i] += counter;
                carry = 0;
            }
            if (counter >= 10) {
                carry = 1;
                if (i != 0) {
                    counter -= 10;
                }
                anserArray[i] += counter;
            }
        }
    }

    //減法
    if (choice == 0) {
        if (count1 > count2) {
            int minus = 0;
            for (int i = count1-1; i >= 0; i--) {
                int counter = 0;
                counter = n1Array[i] - n2Array[i] + minus;
               
                if (counter >= 0) {
                    anserArray[i] += counter;
                    minus = 0;
                }
                if (counter < 0) {
                    anserArray[i] += counter;
                    anserArray[i] += 10;
                    minus = -1;
                }
            }
        }
        if (count2 > count1) {
            int minus = 0;
            for (int i = count2 - 1; i >= 0; i--) {
                int counter = 0;
                counter = n2Array[i] - n1Array[i] + minus;

                if (counter >= 0) {
                    anserArray[i] += counter;
                    minus = 0;
                }
                if (counter < 0) {
                    anserArray[i] += counter;
                    anserArray[i] += 10;
                    minus = -1;
                }
            }
        }
        if (count1 == count2) {
            int flag1 = 0;
            for (int i = 0; i < count1; i++) {
                if (n1Array[i] > n2Array[i]) {
                    flag1 = 1;
                    break;
                }
            }
            if (flag1 == 1) {
                int minus = 0;
                for (int i = count1 - 1; i >= 0; i--) {
                    int counter = 0;
                    counter = n1Array[i] - n2Array[i] + minus;

                    if (counter >= 0) {
                        anserArray[i] += counter;
                        minus = 0;
                    }
                    if (counter < 0) {
                        anserArray[i] += counter;
                        anserArray[i] += 10;
                        minus = -1;
                    }
                }
            }
            if (flag1 == 0) {
                int minus = 0;
                for (int i = count2 - 1; i >= 0; i--) {
                    int counter = 0;
                    counter = n2Array[i] - n1Array[i] + minus;

                    if (counter >= 0) {
                        anserArray[i] += counter;
                        minus = 0;
                    }
                    if (counter < 0) {
                        anserArray[i] += counter;
                        anserArray[i] += 10;
                        minus = -1;
                    }
                }
            }
        }
    }
    printf("\n");

    //輸出答案
    printf("計算結果為:\n");
    for (int i = 0; i < maxCount ; i++) {
        printf("%d", anserArray[i]);
    }
    //詢問是否要繼續計算
    printf("\n");
    int flag2 = 0;
    printf("是否要繼續計算 Yes(1),No(0)\n");
    scanf("%d", &flag2);
    if (flag2 == 1) {
        printf("\n");
        main();
    }
    
}

