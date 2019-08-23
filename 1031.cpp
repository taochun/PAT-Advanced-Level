#include <cstdio>
#include <cstring>
int main() {
	char str[1000];
	char a[100][100];
	scanf("%s", str);
	int N = strlen(str);
	int n1 = (N + 2) / 3;
	int n3 = (N + 2) / 3;
	int n2 = N + 2 - n1 - n3;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			a[i][j] = ' ';
		}
	}
	for (int i = 0; i < n1; i++) {
		a[i][0] = str[i];
	}
	for (int j = 0; j < n2; j++) {
		a[n1-1][j] = str[j+n1-1];
	}
	for (int i = n3 - 1; i >= 0; i--) {
		a[i][n2-1] = str[n1+n2+n3-3-i];
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
