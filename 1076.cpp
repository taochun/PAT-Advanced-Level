#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1010;
struct Node {
	int id;
	int layer;
} node;
int G[maxn][maxn] = {0};
bool inq[maxn];
int n, l;
int BFS(int u) {
	int cnt = 0;
	queue<Node> q;
	node.id = u;
	node.layer = 0;
	q.push(node);
	inq[u] = true;
	while (!q.empty()) {
		Node top = q.front();
		q.pop();
		int u = top.id;
		for (int v = 1; v <= n; v++) {
			if (G[u][v] == 1 && inq[v] == false) {
				if (top.layer + 1 <= l) {
					node.id = v;
					node.layer = top.layer + 1;
					q.push(node);
					inq[v] = true;
					cnt++;					
				}
			}
		}
	}
	return cnt;
}
int main() {
	cin >> n >> l;
	int m, user;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		for (int j = 1; j <= m; j++) {
			cin >> user;
			G[user][i] = 1;
		}
	}
	int k, query;
	cin >> k;
	for (int i = 0; i < k; i++) {
		fill(inq, inq + maxn, false);
		cin >> query;
		int ans = BFS(query);
		cout << ans << endl;
	}
	return 0;
}
