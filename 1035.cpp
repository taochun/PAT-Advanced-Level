#include <cstdio>
#include <cstring>
int main() {
	int N;
	char user[1010][20], pwd[1010][20]; //数组开大点 
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s%s", user[i], pwd[i]);
	}
	int a[1010];
	int num = 0;
	for (int i = 0; i < N; i++) {
		int flag = 0;
		for (int j = 0; j < strlen(pwd[i]); j++) {
			if (pwd[i][j] == '1') {
				pwd[i][j] = '@';
				flag = 1;
			} else if (pwd[i][j] == '0') {
				pwd[i][j] = '%';
				flag = 1;
			} else if (pwd[i][j] == 'l') {
				pwd[i][j] = 'L';
				flag = 1;
			} else if (pwd[i][j] == 'O') {
				pwd[i][j] = 'o';
				flag = 1;
			}
		}
		if (flag == 1) { //modified
			a[num++] = i;
		}
	}
	if (num == 0) {
		if (N == 1) {
			printf("There is 1 account and no account is modified");
		} else {
			printf("There are %d accounts and no account is modified", N);
		}
	} else {
		printf("%d\n", num);
		for (int i = 0; i < num; i++) {
			printf("%s %s", user[a[i]], pwd[a[i]]);
			if (i < num - 1) {
				printf("\n");
			}
		}		
	}
	return 0;
}
