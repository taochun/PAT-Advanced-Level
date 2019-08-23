#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node {
	int addr, data, next;
	bool flag;
} node[maxn];
bool cmp(Node a, Node b) {
	if (a.flag == false || b.flag == false) {
		return a.flag > b.flag;
	} else {
		return a.data < b.data;
	}
}
int main() {
	for (int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}
	int n, begin;
	scanf("%d%d", &n, &begin);
	int addr, data, next;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &addr, &data, &next);
		node[addr].addr = addr;
		node[addr].data = data;
		node[addr].next = next;
	}
	int p = begin, count = 0;
	while (p != -1) {
		node[p].flag = true;
		count++;
		p = node[p].next;
	}
	n = count;
	if (n == 0) {
		printf("0 -1\n");
		return 0;
	}
	sort(node, node + maxn, cmp);
	printf("%d %05d\n", n, node[0].addr);
	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i + 1].addr);
		} else {
			printf("%05d %d -1\n", node[i].addr, node[i].data);
		}
	}
	return 0;
}
