#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct node {
	int data;
	vector<int> child;
} Node[maxn];
vector<int> path;
int n, m, w;
bool cmp(int a, int b) {
	// return a > b;
	return Node[a].data > Node[b].data;
}
void DFS(int index) {
	if (Node[index].child.size() == 0) {
		path.push_back(index);
		int value = 0;
		for (int i = 0; i < path.size(); i++) {
			value += Node[path[i]].data;
		}
		if (value == w) {
			for (int i = 0; i < path.size(); i++) {
				if (i > 0) {
					cout << " ";
				}
				cout << Node[path[i]].data;
			}
			cout << endl;
		}
		path.pop_back();
		return;
	}
	path.push_back(index);
	for (int i = 0; i < Node[index].child.size(); i++) {
		DFS(Node[index].child[i]);
	}
	path.pop_back();
}
int main() {
	cin >> n >> m >> w;
	for (int i = 0; i < n; i++) {
		cin >> Node[i].data;
	}
	for (int i = 0; i < m; i++) {
		int id, k, t;
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			cin >> t;
			Node[id].child.push_back(t);
		}
	}
	for (int i = 0; i < n; i++) {
		sort(Node[i].child.begin(), Node[i].child.end(), cmp);
	}
	DFS(0);
	return 0;
}
