#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct node {
	vector<int> child;
	int layer;
} Node[maxn];
int cnt[maxn] = {0};
int n, m;
void BFS(int index) {
	queue<node> q;
	node root = Node[index];
	root.layer = 1;
	q.push(root);
	while (!q.empty()) {
		node top = q.front();
		q.pop();
		cnt[top.layer]++;
		for (int i = 0; i < top.child.size(); i++) {
			node next = Node[top.child[i]];
			next.layer = top.layer + 1;
			q.push(next);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int id, k, t;
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			cin >> t;
			Node[id].child.push_back(t);
		}
	}
	BFS(1);
	int maxCnt = 0, id = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] > maxCnt) {
			maxCnt = cnt[i];
			id = i;
		}
	}
	cout << maxCnt << " " << id;
	return 0;
}
