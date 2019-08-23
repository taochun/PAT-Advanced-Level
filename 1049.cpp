#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
int cnt = 0;
int main() {
	int n;
	cin >> n;
	int temp = n;
	while (temp != 0) {
		a.push_back(temp % 10);
		temp /= 10;
	}
	a.push_back(0);
	reverse(a.begin(), a.end());
	int k = 1;
	for (int i = 1; i <= a.size() - 1; i++) {
		int left = 0;
		for (int j = 1; j <= a.size() - 1 - i; j++) {
			left = left * 10 + a[j];
		}
		int right = 0;
		for (int j = a.size() + 1 - i; j <= a.size() - 1; j++) {
			right = right * 10 + a[j];
		}
		if (a[a.size() - i] == 0) {
			cnt += left * k;
		} else if (a[a.size() - i] == 1) {
			cnt += left * k + right + 1;
		} else if (a[a.size() - i] >= 2) {
			cnt += (left + 1) * k;
		}
		k *= 10;
	}
	cout << cnt;
	return 0;
}
