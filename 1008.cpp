#include <cstdio>
int a[110];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int total = a[0] * 6 + 5;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) {
			total += (a[i] - a[i - 1]) * 6 + 5;
		} else {
			total += (a[i - 1] - a[i]) * 4 + 5;
		}
	} 
	printf("%d", total);
	return 0;
}
