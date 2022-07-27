// U10810015地生三許惟智
//使用者自訂一元二次方程式係數，求方程式的根。
//字串輸出總共使用了3種方法，不確定哪一種較好，要再請教老師。
#include <stdio.h>
#include <math.h>
#define STRINGLEN 40
void main() {
	int a, b, c;
	double x1, x2, D;
	char hint[STRINGLEN] = "請依序輸入a,b,c定義方程式ax^2+bx+c";
	char defineA[STRINGLEN] = "請輸入a";
	char defineB[STRINGLEN] = "請輸入b";
	char defineC[STRINGLEN] = "請輸入c";
	
	printf("%s\n", hint);
	printf("%s\n", defineA);
	scanf("%d", &a);
	printf("%s\n", defineB);
	scanf("%d", &b);
	printf("%s\n", defineC);
	scanf("%d", &c);
	D = (b * b) - (4 * a * c);
	x1 = (-b + sqrt(D)) / (2 * a);
	x2 = (-b - sqrt(D)) / (2 * a);
	if (D > 0) {
		printf("%s%f,%f", "兩根為:", x1, x2);
	}
	else if (D == 0) {
		printf("%s,%f","兩重根為:", x1);
	}
	else if (D < 0) {
		printf("%s", "無實數解");
	}
	else
	{
		printf("不合法的方程式");
	}
	
}
