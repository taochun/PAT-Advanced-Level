#include <cstdio>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int sum = a + b;
	if (sum < 0) {
		printf("-");
		sum = -sum;
	}
	int len = 0;
	int arr[10];
	if (sum == 0) {
		arr[len++] = 0;
	}
	while (sum) {
		arr[len++] = sum % 10;
		sum /= 10;
	}
	for (int i = len - 1; i >= 0; i--) {
		printf("%d", arr[i]);
		if (i % 3 == 0 && i > 0) {
			printf(",");
		}
	}
	return 0;
}
