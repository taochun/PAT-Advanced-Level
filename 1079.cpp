#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node {
	int data;
	vector<int> child;
} Node[maxn];
int n;
double p, r, total = 0;
void DFS(int index, int depth) {
	if (Node[index].child.size() == 0) {
		total += p * pow(1 + r, depth) * Node[index].data;
		return;
	}
	for (int i = 0; i < Node[index].child.size(); i++) {
		DFS(Node[index].child[i], depth + 1);
	}
}
int main() {
	cin >> n >> p >> r;
	r /= 100;
	int k, t;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k > 0) {
			for (int j = 0; j < k; j++) {
				cin >> t;
				Node[i].child.push_back(t);
			}
		} else {//k == 0
			cin >> t;
			Node[i].data = t;
		}
	}
	DFS(0, 0);
	printf("%.1f", total);
	return 0;
}
