#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
vector<int> child[maxn];
int cnt[maxn] = {0};
int n, m, maxDepth = 0;//结点数，边数
void DFS(int index, int depth) {
	if (child[index].size() == 0) {
		cnt[depth]++;
		if (depth > maxDepth) {
			maxDepth = depth;
		}
		return;
	}
	for (int i = 0; i < child[index].size(); i++) {
		DFS(child[index][i], depth + 1);
	}
}
int main() {
	cin >> n >> m;
	int id, k, t;
	for (int i = 0; i < m; i++) {
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			cin >> t;
			child[id].push_back(t);
		}
	}
	DFS(1, 1);
	for (int i = 1; i <= maxDepth; i++) {
		if (i > 1) {
			cout << " ";
		}
		cout << cnt[i];
	}
	return 0;
}
