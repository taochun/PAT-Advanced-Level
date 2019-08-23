#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];
int n;
double p, r;
int maxDepth = 0, num = 0;
void DFS(int index, int depth) {
	if (child[index].size() == 0) {
		if (depth > maxDepth) {
			maxDepth = depth;
			num = 1;
		} else if (depth == maxDepth) {
			num++;
		}
		return;
	}
	for (int i = 0; i < child[index].size(); i++) {
		DFS(child[index][i], depth + 1);
	}
}
int main() {
	cin >> n >> p >> r;
	int root, t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t != -1) {
			child[t].push_back(i);
		} else {
			root = i;
		}
	}
	DFS(root, 0);
	double price = p;
	for (int i = 0; i < maxDepth; i++) {
		price *= (1 + 0.01 * r);
	}
	printf("%.2f %d", price, num);
	return 0;
}
