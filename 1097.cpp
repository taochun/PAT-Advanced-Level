#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node {
	int addr, data, next;
	int order;
} node[maxn];
bool exist[maxn] = {false};
bool cmp(Node a, Node b) {
	return a.order < b.order;
}
int main() {
	for (int i = 0; i < maxn; i++) {
		node[i].order = 2 * maxn;
	}
	int begin, n;
	scanf("%d%d", &begin, &n);
	int addr, data, next;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &addr, &data, &next);
		node[addr].addr = addr;
		node[addr].data = data;
		node[addr].next = next;
	}
	int p = begin, cnt1 = 0, cnt2 = 0;
	while (p != -1) {
		if (exist[abs(node[p].data)] == false) {
			node[p].order = cnt1++;
			exist[abs(node[p].data)] = true;
			p = node[p].next;
		} else {
			node[p].order = maxn + cnt2++;
			p = node[p].next;
		}
	}
	sort(node, node + maxn, cmp);
	for (int i = 0; i < cnt1; i++) {
		if (i != cnt1 - 1) {
			printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i + 1].addr);
		} else {
			printf("%05d %d -1\n", node[i].addr, node[i].data);
		}
	}
	for (int i = cnt1; i < cnt1 + cnt2; i++) {
		if (i != cnt1 + cnt2 - 1) {
			printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i + 1].addr);
		} else {
			printf("%05d %d -1\n", node[i].addr, node[i].data);
		}
	}
	return 0;
}
