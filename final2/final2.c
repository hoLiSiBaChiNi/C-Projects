#include <stdio.h>
#include<assert.h>
#define ARRAYSIZE 32

void count(int t) {
	int rArray[ARRAYSIZE];
	int fArray[ARRAYSIZE];
	rArray[0] = 100;
	fArray[0] = 100;
	for (int i = 1; i <= t; i++) {
		rArray[i] = (4 * rArray[i-1] - 2 * fArray[i-1]);
		fArray[i] = (rArray[i-1] + fArray[i-1]);
	}
	return printf("Rabbit = %d\nFox = %d\n",rArray[t], fArray[t]);
}
int main(void)
{
	int t;
	printf("which year?\n");
	scanf("%d", &t);
	assert(t >= 0 & t < 32);
	count(t);
	return 0;
}


