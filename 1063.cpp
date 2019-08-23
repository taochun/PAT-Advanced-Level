#include <cstdio>
#include <set>
using namespace std;
set<int> st[60];
//set<int> st1;
void compare(int s1, int s2) {
	int same = 0, total = st[s2].size();
	for (auto it = st[s1].begin(); it != st[s1].end(); it++) {
		if (st[s2].find(*it) != st[s2].end()) {
			same++;
		} else {
			total++;
		}
	}
	printf("%.1f%%\n", same * 100.0 / total);
	// int same = 0;
	// for (auto it = st[s1].begin(); it != st[s1].end(); it++) {
	// 	if (st[s2].find(*it) != st[s2].end()) {
	// 		same++;
	// 	}
	// }
	// st1.clear();
	// for (auto it = st[s1].begin(); it != st[s1].end(); it++) {
	// 	st1.insert(*it);
	// }
	// for (auto it = st[s2].begin(); it != st[s2].end(); it++) {
	// 	st1.insert(*it);
	// }
	// printf("%.1f%\n", same * 100.0 / st1.size());
}
int main() {
	int n, n1, n2;
	scanf("%d", &n);
	int m, e;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &e);
			st[i].insert(e);
		}
	}
	int k, s1, s2;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &s1, &s2);
		compare(s1, s2);
	}
	return 0;
}
