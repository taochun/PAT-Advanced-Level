#include <cstdio>
int hashtable[1010];
int main() {
	int N, M, num;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		hashtable[num]++;
	} 
	for (int i = 1; i < M; i++) {
		if (hashtable[i] && hashtable[M - i]) {
			if (i == M - i && hashtable[i] <= 1) {
				continue;
			}
			printf("%d %d", i, M - i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}
