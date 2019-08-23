#include <cstdio>
#include <cmath>
using namespace std;
int a[100];
bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	} 
	return true;
}
int main() {
	int n, d;
	while (scanf("%d", &n) != EOF) {
		if (n < 0) {
			break;
		}
		scanf("%d", &d);
		if (!isPrime(n)) {
			printf("No\n");
		} else {
			int len = 0;
			do {
				a[len++] = n % d;
				n /= d;
			} while (n != 0);
			for (int i = 0; i < len; i++) {
				n = n * d + a[i];
			} 
			if (isPrime(n)) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	}
	return 0;
}
