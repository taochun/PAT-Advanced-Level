#include <cstdio>
#include <map>
using namespace std;
map<int, int> cnt;
int n, m, color;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &color);
			if (cnt.find(color) != cnt.end()) {
				cnt[color]++;
			} else {
				cnt[color] = 1;
			}
		}
	}
	int k, max = -1;
	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		if (it->second > max) {
			k = it->first;
			max = it->second;
		}
	}
	printf("%d\n", k);
	return 0;
}
