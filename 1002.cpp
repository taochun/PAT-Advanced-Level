#include <cstdio>
const int maxn = 1010;
double a1[maxn], a2[maxn], a[maxn];
int main() {
	int K1, K2;
	int exp1, exp2, exp;
	double coef1, coef2;
	scanf("%d", &K1);
	for (int i = 0; i < K1; i++) {
		scanf("%d%lf", &exp1, &coef1);
		a1[exp1] = coef1;
	} 
	scanf("%d", &K2);
	for (int i = 0; i < K2; i++) {
		scanf("%d%lf", &exp2, &coef2);
		a2[exp2] = coef2;
	} 
	int cnt;
	for (int i = 0; i < maxn; i++) {
		a[i] = a1[i] + a2[i];
		if (a[i] != 0) {
			cnt++;
		}
	}
	printf("%d", cnt);
	for (int i = maxn - 1; i >= 0; i--) {
		if (a[i] != 0) {
			printf(" %d %.1f", i, a[i]);
		}
	}
	return 0;
}
