#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
// Finding log(1+x) from infinity Teylor's row, -1<x<=1
int main(void) {
	float y, x, sum, step;
	int i;
	long float prec; 
	
	printf("Enter the precision of calculathion: ");
	scanf("%lf", &prec);
	printf("Enter step of calculation: ");
	scanf("%f", &step);
	
	x = -1 + step;
	while (x <= 1) {
		i = 1;
		y = x;
		sum = 0;
		while (fabs(y) > prec) {
			y = pow(x, i) / i;
			if (i % 2 == 0) {
				sum = sum - y;
			}
			else {
				sum += y;
			}
			i++;
		}
		float tru;
		tru = log1p(x);
		for (i = 0; i < 120; i++) {
			printf("=");
		}
		printf("|X \t\t\t|My logo \t\t|lg(1+x) \t\t|Diff\n");
		printf("|%.13lf \t|%.13lf \t|%.13lf \t|%.13lf\n", x, sum, tru, (tru-sum));
		x += step;
	}
	for (i = 0; i < 120; i++) {
		printf("=");
	}
}