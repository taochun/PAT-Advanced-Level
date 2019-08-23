#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
struct mooncake {
	double num;
	double sum;
	double price;
} cake[maxn];
bool cmp(mooncake a, mooncake b) {
	return a.price > b.price;
}
int main() {
	int n;
	double demand;
	cin >> n >> demand;
	for (int i = 0; i < n; i++) {
		cin >> cake[i].num;
	}
	for (int i = 0; i < n; i++) {
		cin >> cake[i].sum;
		cake[i].price = cake[i].sum / cake[i].num;
	}
	sort(cake, cake + maxn, cmp);
	double cnt = 0, total = 0;
	for (int i = 0; i < n; i++) {
		if (cnt + cake[i].num >= demand) {
			total += (demand - cnt) * cake[i].price;
			break;
		} else {
			cnt += cake[i].num;
			total += cake[i].sum;
		}
	}
	printf("%.2f", total);
	return 0;
}
