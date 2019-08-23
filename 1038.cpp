#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int n;
string a[maxn];
bool cmp(string a, string b) {
	return a + b < b + a;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	string str;
	for (int i = 0; i < n; i++) {
		str += a[i];
	}
	while (str.size() != 0 && str[0] == '0') {
		str.erase(str.begin());
	}
	if (str.size() != 0) {
		cout << str;
	} else {
		cout << 0;
	}
	return 0;
}
