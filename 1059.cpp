#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 100010;
int prime[maxn], pnum = 0;
int fnum = 0;
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
void findPrime() {
	for (int i = 2; i < maxn; i++) {
		if (isPrime(i)) {
			prime[pnum++] = i;
		}
	}
}
struct factor {
	int x;
	int cnt;
} fac[10];
int main() {
	findPrime();
	int n;
	scanf("%d", &n);
	printf("%d=", n);
	if (n == 1) {
		printf("1");
		return 0;
	}
	if (isPrime(n)) {
		printf("%d", n);
		return 0;
	}
	for (int i = 0; i < pnum; i++) {
		int temp = n;
		while (temp % prime[i] == 0) {
			fac[fnum].x = prime[i];
			fac[fnum].cnt++;
			temp /= prime[i];
		}
		if (n % prime[i] == 0) {
			fnum++;
		}
	}
	for (int i = 0; i < fnum; i++) {
		if (i != 0) {
			printf("*"); 
		}
		if (fac[i].cnt == 1) {
			printf("%d", fac[i].x);
		} else {
			printf("%d^%d", fac[i].x, fac[i].cnt);
		}
	}
	return 0;
}
