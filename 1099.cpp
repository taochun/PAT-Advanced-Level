#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct node {
	int data;
	int lchild, rchild;
} Node[maxn];
int n, in[maxn], cnt;
void inorder(int root) {
	if (root == -1) {
		return;
	}
	inorder(Node[root].lchild);
	Node[root].data = in[cnt++];
	inorder(Node[root].rchild);
}
void layerorder(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		cout << Node[top].data;
		cnt++;
		if (cnt < n) {
			cout << " ";
		}
		if (Node[top].lchild != -1) {
			q.push(Node[top].lchild);
		}
		if (Node[top].rchild != -1) {
			q.push(Node[top].rchild);
		}
	}
}
int main() {
	cin >> n;
	int lchild, rchild;
	for (int i = 0; i < n; i++) {
		cin >> lchild >> rchild;
		Node[i].lchild = lchild;
		Node[i].rchild = rchild;
	}
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	sort(in, in + n);
	cnt = 0;
	inorder(0);
	cnt = 0;
	layerorder(0);
	return 0;
}
