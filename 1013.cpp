#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int G[maxn][maxn];
bool vis[maxn];
int n, m, k;
void DFS(int u) {
	vis[u] = true;
	for (int v = 1; v <= n; v++) {
		if (G[u][v] == 1 && vis[v] == false) {
			DFS(v);
		}
	}
}
int main() {
	// fill(G[0], G[0] + maxn * maxn, 0);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][v] = 1;
		G[v][u] = 1;
	}
	for (int i = 0; i < k; i++) {
		int t, ans = 0;
		scanf("%d", &t);
		fill(vis, vis + maxn, false);
		// for (int j = 1; j <= n; j++) {
		// 	G[t][j] = 0;
		// 	G[j][t] = 0;
		// }
		vis[t] = true;
		for (int j = 1; j <= n; j++) {
			if (vis[j] == false) {
				ans++;
				DFS(j);
			}
		}
		printf("%d\n", ans - 1);
	}
}
