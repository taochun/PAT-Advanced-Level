#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
string a1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string a2[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string numToString[170];
map<string, int> stringToNum;
void init() {
	// for (int i = 0; i < 13; i++) {
	// 	numToString[i] = a1[i];
	// 	stringToNum[a1[i]] = i;
	// 	numToString[i * 13] = a2[i];
	// 	stringToNum[a2[i]] = i * 13;
	// }
	for (int i = 0; i < 13; i++) {
		string str = a1[i];
		numToString[i] = str;
		stringToNum[str] = i;
	}
	for (int i = 1; i < 13; i++) {
		string str = a2[i];
		numToString[i * 13] = str;
		stringToNum[str] = i * 13;
	}
	for (int i = 1; i < 13; i++) {
		for (int j = 1; j < 13; j++) {
			string str = a2[i] + " " + a1[j];
			numToString[i * 13 + j] = str;
			stringToNum[str] = i * 13 + j;
		}
	}
}
int main() {
	init();
	int n;
	scanf("%d%*c", &n);
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		if (str[0] >= '0' && str[0] <= '9') {
			int num = 0;
			for (int j = 0; j < str.length(); j++) {
				num = num * 10 + (str[j] - '0');
			}
			cout << numToString[num] << endl;
		} else {
			cout << stringToNum[str] << endl;
		}
	}
	return 0;
}
