

#include <stdio.h>
#include<assert.h>
int Rabbit(int t) {
	if (t == 0) {
		int intialR = 100;
		return intialR;
	}
	return(4 * Rabbit(t - 1) - 2 * Fox(t - 1));
}
int Fox(int t) {
	if (t == 0) {
		int intialF = 100;
		return intialF;
	}
	return(Rabbit(t - 1) + Fox(t - 1));
}
int main(void)
{
	int t;
	printf("which year?\n");
	scanf("%d", &t);
	assert(t > 0 & t < 32);
	printf("Rabbit = %d\n", Rabbit(t));
	printf("Fox = %d\n", Fox(t));



	return 0;
}
