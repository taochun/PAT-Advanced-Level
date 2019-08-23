#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 10100;
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
bool hashtable[maxn] = {false};
int main() {
	int tsize, n;
	scanf("%d%d", &tsize, &n);
	while (!isPrime(tsize)) {
		tsize++;
	}
	int key, pos;
	for (int i = 0; i < n; i++) {
		scanf("%d", &key);
		pos = key % tsize;
		if (hashtable[pos] == false) {
			hashtable[pos] = true;
			if (i == 0) {
				printf("%d", pos);
			} else {
				printf(" %d", pos);
			}
		} else {
			int step;
			for (step = 1; step < tsize; step++) {
				pos = (key + step * step) % tsize;
				if (hashtable[pos] == false)  {
					hashtable[pos] = true;
					if (i == 0) {
						printf("%d", pos);
					} else {
						printf(" %d", pos);
					}
					break;
				}
			}
			if (step == tsize) {
				if (i == 0) {
					printf("-");
				} else {
					printf(" -");
				}
			}
		}
	}
	return 0;
}
