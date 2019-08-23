#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn], in[maxn], post[maxn];
int n;
node* create(int preL, int preR, int inL, int inR) {
	if (preL > preR) {
		return NULL;
	}
	node* root = new node;
	root->data = pre[preL];
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == pre[preL]) {
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create(preL + 1 + numLeft, preR, k + 1, inR);
	return root;
}
int cnt = 0;
void postorder(node* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	cout << root->data;
	cnt++;
	if (cnt < n) {
		cout << " ";
	}
}
int main() {
	cin >> n;
	stack<int> st;
	string str;
	int x, preCnt = 0, inCnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		cin >> str;
		if (str == "Push") {
			cin >> x;
			pre[preCnt++] = x;
			st.push(x);
		} else if (str == "Pop") {
			in[inCnt++] = st.top();
			st.pop();
		}
	}
	node* root = create(0, n - 1, 0, n - 1);
	postorder(root);
	return 0;
}
