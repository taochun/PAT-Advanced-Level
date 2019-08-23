#include <cstdio> 
#include <algorithm>
using namespace std;
bool isSame(int num) {
	int a[4];
	for (int i = 0; i < 4; i++) {
		a[i] = num % 10;
		num /= 10;
	}
	if (a[0] == a[1] && a[0] == a[2] && a[0] == a[3]) {
		return true;
	} else {
		return false;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	if (isSame(n)) {
		printf("%d - %d = 0000\n", n, n);
		return 0;
	} 
	do {
		int a1 = 0, a2 = 0;
		int a[4];
		int temp = n;
		for (int i = 0; i < 4; i++) {
			a[i] = temp % 10;
			temp /= 10;
		}
		sort(a, a + 4);
		for (int i = 3; i >= 0; i--) {
			a1 = a1 * 10 + a[i];
		} 
		for (int i = 0; i < 4; i++) {
			a2 = a2 * 10 + a[i];
		}
		printf("%04d - %04d = %04d\n", a1, a2, a1 - a2);
		n = a1 - a2;
	} while (n != 6174 && n != 0);
	return 0;
}
