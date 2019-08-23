#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;
map<string, int> cnt;
int main() {
	string str;
	getline(cin, str);
	int i = 0;
	while (i < str.length()) {
		string word;
		while (i < str.length() && isalnum(str[i])) {
			if (isupper(str[i])) {
				str[i] = tolower(str[i]);
			}
			word += str[i] ;
			i++;
		}
		if (cnt.find(word) != cnt.end()) {
			cnt[word]++;
		} else {
			cnt[word] = 1;
		}
		while (i < str.length() && !isalnum(str[i])) {
			i++;
		}
	}
	string ans;
	int max = -1;
	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		if (it->second > max) {
			ans = it->first;
			max = it->second;
		}
	}
	cout << ans << " " << max << endl;
	return 0;
}
