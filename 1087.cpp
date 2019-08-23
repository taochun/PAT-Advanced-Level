#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 210;
const int inf = 100000000;
vector<int> path, tempPath;
vector<int> pre[maxn];
map<string, int> stringToInt;
map<int, string> intToString;
int G[maxn][maxn];
int d[maxn];
int weight[maxn];
bool vis[maxn] = {false};
int n, k;
int cnt = 0, maxValue = 0, maxAvg = 0;
void Dijkstra(int s) {
	fill(d, d + maxn, inf);
	d[s] = 0;
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
		cnt++;
		tempPath.push_back(v);
		int value = 0, avg = 0;
		for (int i = tempPath.size() - 2; i >= 0; i--) {
			int id = tempPath[i];
			value += weight[id];
		}
		avg = value / (tempPath.size() - 1);
		if (value > maxValue) {
			maxValue = value;
			maxAvg = avg;
			path = tempPath;
		} else if (value == maxValue && avg > maxAvg) {
			maxAvg = avg;
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
	string c1, c2;
	int t;
	cin >> n >> k >> c1;
	stringToInt[c1] = 0;
	intToString[0] = c1;
	for (int i = 1; i < n; i++) {
		cin >> c1 >> t;
		stringToInt[c1] = i;
		intToString[i] = c1;
		weight[i] = t;
	}
	for (int i = 0; i < k; i++) {
		cin >> c1 >> c2 >> t;
		int id1 = stringToInt[c1];
		int id2 = stringToInt[c2];
		G[id1][id2] = G[id2][id1] = t;
	}
	Dijkstra(0);
	int rom = stringToInt["ROM"];
	DFS(rom);
	printf("%d %d %d %d\n", cnt, d[rom], maxValue, maxAvg);
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << intToString[path[i]];
		if (i > 0) {
			cout << "->";
		}
	}
	return 0;
}
