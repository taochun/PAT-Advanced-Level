#include <cstdio>
double a1[1010], a2[1010], a[2010];
int main() {
	int k, k1, exp1, k2, exp2, count = 0;
	double coef1, coef2;
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++) {
		scanf("%d%lf", &exp1, &coef1);
		a1[exp1] = coef1;
	}
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++) {
		scanf("%d%lf", &exp2, &coef2);
		a2[exp2] = coef2;
	}
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			a[i+j] += a1[i] * a2[j];
		}
	}
	for (int i = 2000; i >= 0; i--) {
		if (a[i] != 0) {
			count++;
		}
	}
	printf("%d", count);
	for (int i = 2000; i >=0; i--) {
		if (a[i] != 0) {
			printf(" %d %.1lf", i, a[i]);
		}
	}
	return 0;
}
