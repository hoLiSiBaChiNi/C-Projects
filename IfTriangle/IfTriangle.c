#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define S ((a)+(b)+(c))/(2)
#define AREA sqrt((S)*((S) - (a))*((S) - (b))*((S) - (c)))
int main() {

	int a, b, c;

	printf("%s\n", "���{���N�P�_�ϥΪ̿�J���T����O�_�Φ��@�T����,�Y�O�i�H�N��X���n�A�_�h��X0�C");
	printf("%s\n", "�п�J�T���Ϊ���� a:");
	scanf("%d", &a);
	printf("%s\n", "�п�J�T���Ϊ���� b :");
	scanf("%d", &b);
	printf("%s\n", "�п�J�T���Ϊ���� c :");
	scanf("%d", &c);
	bool identicalTriangle = (a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b);
	if (identicalTriangle == true) {
		printf("%s\n", "�i�Φ��T����");
		printf("�T���έ��n��: %.2f", AREA);
	}
	else {
		printf("�L�k�Φ��T����\n");
		printf("%d", 0);
	}





}