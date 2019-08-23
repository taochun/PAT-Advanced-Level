#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
vector<int> origin, pre, preM, post, postM;
int n, data;
void insert(node* &root, int x) {
	if (root == NULL) {
		root = new node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}
	if (x < root->data) {
		insert(root->lchild, x);
	} else {
		insert(root->rchild, x);
	}
}
void preorder(node* root) {
	if (root == NULL) {
		return;
	}
	pre.push_back(root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void preMorder(node* root) {
	if (root == NULL) {
		return;
	}
	preM.push_back(root->data);
	preMorder(root->rchild);
	preMorder(root->lchild);
}
void postorder(node* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	post.push_back(root->data);
}
void postMorder(node* root) {
	if (root == NULL) {
		return;
	}
	postMorder(root->rchild);
	postMorder(root->lchild);
	postM.push_back(root->data);
}
int main() {
	cin >> n;
	node* root = NULL;
	for (int i = 0; i < n; i++) {
		cin >> data;
		origin.push_back(data);
		insert(root, data);
	}
	preorder(root);
	preMorder(root);
	postorder(root);
	postMorder(root);
	if (pre == origin) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				cout << " ";
			}
			cout << post[i];
		}
	} else if (preM == origin) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				cout << " ";
			}
			cout << postM[i];
		}
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
