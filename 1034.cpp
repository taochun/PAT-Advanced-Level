#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2010;
map<string, int> stringToInt;//人string——>人int
map<int, string> intToString;//人int——>人string
map<string, int> gang;//帮派领导string——>帮派人数int
int G[maxn][maxn] = {0};
int weight[maxn] = {0};
bool vis[maxn] = {false};
int n, k;
int cnt = 0;
void DFS(int index, int& head, int& num, int& total) {
	if (weight[index] > weight[head]) {
		head = index;
	}
	for (int i = 0; i < cnt; i++) {
		if (G[index][i] > 0) {
			total += G[index][i];
			G[index][i] = G[i][index] = 0;
			if (vis[i] == false) {
				vis[i] = true;
				num++;
				DFS(i, head, num, total);
			}
		}
	}
}
int change(string s) {
	if (stringToInt.find(s) != stringToInt.end()) {//已存在string
		return stringToInt[s];
	} else {//不存在string
		stringToInt[s] = cnt;
		intToString[cnt] = s;
		return cnt++;
	}
}
int main() {
	cin >> n >> k;
	string s1, s2;
	int w;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2 >> w;
		int id1 = change(s1);
		int id2 = change(s2);
		G[id1][id2] += w;
		G[id2][id1] += w;
		weight[id1] += w;
		weight[id2] += w;
	}
	for (int u = 0; u < cnt; u++) {
		if (vis[u] == false) {
			vis[u] = true;
			int head = u, num = 1, total = 0;//head和num存储到gang，total作判断
			DFS(u, head, num, total);
			if (num > 2 && total > k) {
				gang[intToString[head]] = num;
			}
		}
	}
	cout << gang.size() << endl;
	for (auto it = gang.begin(); it != gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
