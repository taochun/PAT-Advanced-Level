#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 40;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int post[maxn], in[maxn];
int n;
node* create(int postL, int postR, int inL, int inR) {
	if (postL > postR) {
		return NULL;
	}
	node* root = new node;
	root->data = post[postR];
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == post[postR]) {
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	return root;
}
int cnt = 0;
void BFS(node* root) {
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node* top = q.front();
		q.pop();
		cout << top->data;
		cnt++;
		if (cnt < n) {
			cout << " ";
		}
		if (top->lchild != NULL) {
			q.push(top->lchild);
		}
		if (top->rchild != NULL) {
			q.push(top->rchild);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	node* root = create(0, n - 1, 0, n - 1);
	BFS(root);
	return 0;
}
