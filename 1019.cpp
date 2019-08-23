#include <cstdio>
int main() {
	long long N, b;
	int a[100], len;
	scanf("%lld%lld", &N, &b);
	if (N == 0) {
		a[1] = 0;
		len = 1;
	} else {
		for (int i = 1; N != 0; i++) {
			a[i] = N % b;
			N /= b;
			len = i;
		}
	}
	int flag = 1;
	for (int i = 1; i <= len/2; i++) {
		if (a[i] != a[len-i+1]) {
			flag = 0;
		}
	}
	if (flag == 1) {
		printf("Yes\n");
	} else if (flag == 0) {
		printf("No\n");
	}
	for (int i = len; i >= 1; i--) {
		printf("%lld", a[i]);
		if (i != 1) {
			printf(" ");
		}
	}
	return 0;
} 
