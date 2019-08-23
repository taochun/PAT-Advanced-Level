#include <cstdio>
int num[100010];
int hashtable[10010];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
		hashtable[num[i]]++;
	}
	int flag = 0;
	for (int i = 0; i < N; i++) {
		if (hashtable[num[i]] == 1) {
			printf("%d", num[i]);
			flag = 1;
			break;
		}
	} 
	if (flag == 0) {
		printf("None");
	}
	return 0;
}
