#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int coupon[maxn];
int product[maxn];
int n, m;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> coupon[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> product[i];
	}
	sort(coupon, coupon + n);
	sort(product, product + n);
	int total = 0;
	for (int i = 0; i < n && i < m && coupon[i] < 0 && product[i] < 0; i++) {
		total += coupon[i] * product[i];
	}
	for (int i = n - 1, j = m - 1; i >= 0 && j >= 0 && coupon[i] > 0 && product[i] > 0; i--, j--) {
		total += coupon[i] * product[i];
	}
	cout << total;
	return 0;
}
