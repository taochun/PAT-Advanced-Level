#include <cstdio>
int main() {
	int n;
	scanf("%d", &n);
	double a, ans;
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &a);
		ans += a * i * (n + 1 - i); 
	} 
	printf("%.2f", ans);
	return 0;
}
