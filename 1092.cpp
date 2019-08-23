#include <cstdio>
#include <cstring>
using namespace std;
int change(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 10;
	}
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 36;
	}
}
int main() {
	int hashTable[80];
	for (int i = 0; i < 80; i++) {
		hashTable[i] = 0;
	} 
	char str1[1010], str2[1010];
	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len1; i++) {
		int temp = change(str1[i]);
		hashTable[temp]++;
	}
	int flag = 1;
	int missing = 0;
	for (int i = 0; i < len2; i++) {
		int temp = change(str2[i]);
		if (hashTable[temp] != 0) {
			hashTable[temp]--;
		} else {
			missing++;
			flag = 0;
		}
	}
	if (flag == 1) {
		printf("Yes %d\n", len1 - len2);
	} else {
		printf("No %d\n", missing);
	}
	return 0;
}
