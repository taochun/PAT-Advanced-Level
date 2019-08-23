#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int inf = 1000000000;
int G[maxn][maxn];
int d[maxn];
int cost[maxn][maxn];
int c[maxn];
int pre[maxn];
bool vis[maxn] = {false};
int n, m, st, ed;
void Dijkstra(int s) {
	fill(d, d + maxn, inf);
	fill(c, c + maxn, inf);
	d[s] = 0;
	c[s] = 0;
	for (int i = 0; i < n; i++) {
		pre[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int u = -1, min = inf;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < min) {
				u = j;
				min = d[j];
			}
		} 
		if (u == -1) {
			return;
		}
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != inf) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				} else if (d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]) {
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
			}
		}
	}
}
void DFS(int s, int v) {
	if (v == s) {
		printf("%d ", s);
		return;
	}
	DFS(s, pre[v]);
	printf("%d ", v);
}
int main() {
	int u, v;
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	fill(G[0], G[0] + maxn * maxn, inf);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		scanf("%d%d", &G[u][v], &cost[u][v]);
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	Dijkstra(st);
	DFS(st, ed);
	printf("%d %d", d[ed], c[ed]);
	return 0;
}
