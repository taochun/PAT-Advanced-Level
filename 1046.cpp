#include <cstdio> 
#include <algorithm>
using namespace std;
const int maxn = 100010;
int d[maxn], s[maxn];
int main() {
	int N, M;
	int sum = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &d[i]);
		s[i] = s[i - 1] + d[i - 1];
		sum += d[i];
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++)  {
		int a, b;
		scanf("%d%d", &a, &b);
		int dis1, dis2, dis;
		dis1 = abs(s[a] - s[b]);
		dis2 = sum - dis1;
		dis = min(dis1, dis2);
		printf("%d\n", dis);
	}
	return 0;
}
