#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int inf = 1000000000;
int G[maxn][maxn];
int d[maxn];
int weight[maxn];//点权重 
int w[maxn];//点总权重 
int num[maxn];//最短路径条数 
bool vis[maxn] = {false};
int n, m, st, ed;//点数，边数，起点，终点 
void Dijkstra(int s) {
	fill(d, d + maxn, inf);
	d[s] = 0;
	fill(w, w + maxn, 0);
	w[s] = weight[s];
	fill(num, num + maxn, 0);
	num[s] = 1;
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
				if (d[u] + G[u][v] < d[v])  {
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				} else if (d[u] + G[u][v] == d[v]) {
					num[v] += num[u];
					if (w[u] + weight[v] > w[v]) {
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
	} 
}
int main() {
	int u, v;
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	fill(G[0], G[0] + maxn * maxn, inf);
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	} 
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];
	}
	Dijkstra(st);
	printf("%d %d", num[ed], w[ed]);
	return 0;
}
