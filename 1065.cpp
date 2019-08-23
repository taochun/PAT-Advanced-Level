#include <cstdio>
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		long long res = a + b;
		int flag;
		if (a > 0 && b > 0 && res <= 0) {
			flag = 1;
		} else if (a < 0 && b < 0 && res >= 0) {
			flag = 0;
		} else if (res > c) {
			flag = 1;
		} else {
			flag = 0;
		}
		if (flag == 1) {
			printf("Case #%d: true\n", i);
		} else {
			printf("Case #%d: false\n", i);
		}
	}
	return 0;
}
