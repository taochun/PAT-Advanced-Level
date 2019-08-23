#include <iostream>
#include <cstring>
using namespace std;
string str1, str2;
bool hashtable[128] = {false};
int main() {
	getline(cin, str1);
	getline(cin, str2);
	int len1 = str1.length();
	int len2 = str2.length();
	for (int i = 0; i < len2; i++) {
		hashtable[str2[i]] = true;
	} 
	for (int i = 0; i < len1; i++){
		if (hashtable[str1[i]] == false) {
			cout << str1[i];
		}
	}
	return 0;
}
