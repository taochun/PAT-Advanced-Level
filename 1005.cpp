#include <cstdio>
#include <cstring>
char dig[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int main() {
	char str[110];
	scanf("%s", str);
	int sum = 0;
	for (int i = 0; i < strlen(str); i++) {
		sum += str[i] - '0';
	}
	int num[10];
	int i;
	if (sum == 0) {
		printf("%s", dig[0]);
	}
	for (i = 0; sum != 0; i++) {
		num[i] = sum % 10;
		sum /= 10;
	}
	for (i--; i >= 0; i--) {
		printf("%s", dig[num[i]]);
		if (i > 0) {
			printf(" ");
		}
	}
	return 0;
}
