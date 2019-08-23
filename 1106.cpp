#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
const int inf = 100000000;
vector<int> child[maxn];
bool notRoot[maxn] = {false};
int n;
double p, r;
int minDepth = inf, cnt = 0;
void DFS(int index, int depth) {
	if (child[index].size() == 0) {
		if (depth < minDepth) {
			minDepth = depth;
			cnt = 1;
		} else if (depth == minDepth) {
			cnt++;
		}
		return;
	}
	for (int i = 0; i < child[index].size(); i++) {
		DFS(child[index][i], depth + 1);
	}
}
int main() {
	cin >> n >> p >> r;
	r /= 100;
	int k, t;
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> t;
			child[i].push_back(t);
			notRoot[t] = true;
		}
	}
	int root;
	for (int i = 0; i < n; i++) {
		if (notRoot[i] == false) {
			root = i;
			break;
		} 
	}
	DFS(root, 0);
	printf("%.4f %d", p * pow(1 + r, minDepth), cnt);
	return 0;
}
