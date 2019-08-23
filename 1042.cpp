#include <cstdio>
int main() {
	int k;
	scanf("%d", &k);
	int a[100];
	for (int i = 1; i <= 54; i++) {
		a[i] = i;
	}
	int pos[100];
	for (int i = 1; i <= 54; i++) {
		scanf("%d", &pos[i]);
	}
	int temp[100];
	for (int i = 0; i < k; i++) {
		for (int j = 1; j <= 54; j++) {
			temp[pos[j]] = a[j];
		}
		for (int j = 1; j <= 54; j++) {
			a[j] = temp[j];
		}
	}
	for (int i = 1; i <= 54; i++) {
		int t = a[i];
		if (t >= 1 && t <= 13) {
			printf("S%d", t);
		}
		if (t >= 14 && t <= 26) {
			printf("H%d", t - 13);
		}
		if (t >= 27 && t <= 39) {
			printf("C%d", t - 26);
		}
		if (t >= 40 && t <= 52) {
			printf("D%d", t - 39);
		}
		if (t == 53) {
			printf("J1");
		}
		if (t == 54) {
			printf("J2");
		}
		if (i < 54) {
			printf(" ");
		}
	}
	return 0;
}
