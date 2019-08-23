#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int inf = 100000000;
vector<int> pre[maxn];
vector<int> path, tempPath;
int G[maxn][maxn];
int d[maxn];
int weight[maxn];
bool vis[maxn] = {false};
int n, m, cmax, sp;
int minNeed = inf, minRemain = inf;
void Dijkstra(int s) {
	fill(d, d + maxn, inf);
	d[s] = 0;
	for (int i = 0; i <= n; i++) {
		int u = -1, min = inf;
		for (int j = 0; j <= n; j++) {
			if (vis[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		}
		if (u == -1) {
			return;
		}
		vis[u] = true;
		for (int v = 0; v <= n; v++) {
			if (G[u][v] != inf && vis[v] == false) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if (d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u);
				}				
			}
		}
	}
}
void DFS(int v) {
	if (v == 0) {
		int need = 0, remain = 0;
		tempPath.push_back(v);
		for (int i = tempPath.size() - 2; i >= 0; i--) {
			int id = tempPath[i];
			if (weight[id] > 0) {
				remain += weight[id];
			} else {
				if (remain >= abs(weight[id])) {
					remain -= abs(weight[id]);
				} else {
					need += abs(weight[id]) - remain;
					remain = 0;
				}
			}
		}
		if (need < minNeed) {
			minNeed = need;
			minRemain = remain;
			path = tempPath;
		} else if (need == minNeed && remain < minRemain) {
			minRemain = remain;
			path = tempPath;

		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}
int main() {
	fill(G[0], G[0] + maxn * maxn, inf);
	cin >> cmax >> n >> sp >> m;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
		weight[i] -= cmax / 2;
	}
	int s1, s2, t;
	for (int i = 0; i < m; i++) {
		cin >> s1 >> s2 >> t;
		G[s1][s2] = G[s2][s1] = t;
	}
	Dijkstra(0);
	DFS(sp);
	cout << minNeed << " ";
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i];
		if (i > 0) {
			cout << "->";
		}
	}
	cout << " " << minRemain;
	return 0;
}
