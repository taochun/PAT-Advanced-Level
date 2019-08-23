#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int N, p;
	scanf("%d%d", &N, &p);
	long long num[100010];
	for (int i = 0; i < N; i++) {
		scanf("%lld", &num[i]);
	} 
	sort(num, num + N);
	int i = 0, j = 0;
	int max = 0;
	while (i < N && j < N) {
		while (num[j] <= num[i] * p && j < N) {
			if (j - i + 1 > max) {
				max = j - i + 1;
			}			
			j++;
		}
		i++;
	}
	printf("%d", max);
	return 0;
}
