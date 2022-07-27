#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define S ((a)+(b)+(c))/(2)
#define AREA sqrt((S)*((S) - (a))*((S) - (b))*((S) - (c)))
int main(){

int a, b, c;

printf("%s\n","此程式將判斷使用者輸入之三邊長是否形成一三角形,若是可以就輸出面積，否則輸出0。");
printf("%s\n", "請輸入三角形的邊長 a:");
scanf("%d", &a);
printf("%s\n", "請輸入三角形的邊長 b :");
scanf("%d", &b);
printf("%s\n", "請輸入三角形的邊長 c :");
scanf("%d", &c);
bool identicalTriangle = 
(a > 0 && b > 0 && c > 0 && a + b > c && b + c  > a && a + c > b);
if (identicalTriangle == true) {
	printf("%s\n", "可形成三角形");
	printf("%.1f",AREA);
	
}
printf("%d", S);

	



}   

