#include <cstdio>
const int maxn = 100010;
struct Node {
	char data;
	int next;
	bool flag;
} node[maxn];
int main() {
	int s1, s2, n;
	scanf("%d%d%d", &s1, &s2, &n);
	for (int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}
	int addr, next;
	char data;
	for (int i = 0; i < n; i++) {
		scanf("%d %c %d", &addr, &data, &next);
		node[addr].data = data;
		node[addr].next = next;
	} 
	int p;
	for (p = s1; p != -1; p = node[p].next) {
		node[p].flag = true;
	}
	for (p = s2; p != -1; p = node[p].next) {
		if (node[p].flag == true) {
			break;
		}
	}
	if (p != -1) {
		printf("%05d", p);
	} else {
		printf("-1");
	}
	return 0;
}
