#include <cstdio>
#include <cmath> 
using namespace std;
bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	} 
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	int first, len = 0;
	if (n == 2) {
		printf("1\n2");
		return 0;
	}
	if (isPrime(n)) {
		printf("1\n%d", n);
		return 0;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		long long temp = 1, j;
		for (j = i; j <= sqrt(n); j++) {
			temp *= j;
			if (n % temp != 0) {
				break;
			}
		}
		if (j - i > len) {
			len = j - i;
			first = i;
		}
	} 
	printf("%d\n", len);
	for (int i = first; i < first + len; i++) {
		if (i == first) {
			printf("%d", i);
		} else {
			printf("*%d", i);
		}
	}
	return 0;
}
