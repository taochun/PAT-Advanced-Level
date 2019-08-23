#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 20;
struct node {
	int lchild, rchild;
} Node[maxn];
bool notRoot[maxn] = {false};
int n, cnt;
void postorder(int root) {
	if (root == -1) {
		return;
	}
	postorder(Node[root].lchild);
	postorder(Node[root].rchild);
	swap(Node[root].lchild, Node[root].rchild);
}
void layerorder(int root) {
	if (root == -1) {
		return;
	}
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		printf("%d", top);
		cnt++;
		if (cnt < n) {
			printf(" ");
		} else {
			printf("\n");
		}
		if (Node[top].lchild != -1) {
			q.push(Node[top].lchild);
		}
		if (Node[top].rchild != -1) {
			q.push(Node[top].rchild);
		}
	}
}
void inorder(int root) {
	if (root == -1) {
		return;
	}
	inorder(Node[root].lchild);
	printf("%d", root);
	cnt++;
	if (cnt < n) {
		printf(" ");
	} else {
		printf("\n");
	}
	inorder(Node[root].rchild);
}
int change(char c) {
	if (c == '-') {
		return -1;
	} else {
		notRoot[c - '0'] = true;
		return c - '0';
	}
}
int findRoot() {
	int root;
	for (int i = 0; i < n; i++) {
		if (notRoot[i] == false) {
			root = i;
			break;
		}
	}
	return root;
}
int main() {
	scanf("%d", &n);
	char lchild, rchild;
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c %c", &lchild, &rchild);
		Node[i].lchild = change(lchild);
		Node[i].rchild = change(rchild);
	}
	int root = findRoot();
	postorder(root);
	cnt = 0;
	layerorder(root);
	cnt = 0;
	inorder(root);
	return 0;
}
