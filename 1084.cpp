#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main() {
	char str1[100], str2[100];
	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int hashTable[128] = {0};
	for (int i = 0; i < len1; i++) {
		char c1, c2;//A-Z,a-z,0-9,_;
		int j;
		for (j = 0; j < len2; j++) {
			c1 = str1[i];
			if (isalpha(c1)) {
				c1 = toupper(c1);
			}
			c2 = str2[j];
			if (isalpha(c2)) {
				c2 = toupper(c2);
			}
			if (c1 == c2) {
				break;
			}
		}
		if (j == len2 && hashTable[c1] == 0) {
			printf("%c", c1);
			hashTable[c1] = 1;
		}
	} 
	return 0;
}
