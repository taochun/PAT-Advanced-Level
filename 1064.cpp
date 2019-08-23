#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int number[maxn], CBST[maxn];
int n, cnt = 1;
void inorder(int root) {
	if (root > n) {
		return;
	}
	inorder(2 * root);
	CBST[root] = number[cnt++];
	inorder(2 * root + 1);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> number[i];
	}
	sort(number + 1, number + n + 1);
	inorder(1);
	for (int i = 1; i <= n; i++) {
		if (i > 1) {
			cout << " ";
		}
		cout << CBST[i];
	}
	return 0;
}
