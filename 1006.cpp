#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct person {
	char id[20];
	int sign_in;
	int sign_out;
} a[1000];

int main() {
	int M;
	scanf("%d", &M);
	int hh, mm, ss;
	for (int i = 0; i < M; i++) {
		scanf("%s %d:%d:%d",a[i].id, &hh, &mm, &ss);
		a[i].sign_in = 3600 * hh + 60 * mm + ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		a[i].sign_out = 3600 * hh + 60 * mm + ss;
	}
	int flag1, flag2, min = 100000, max = 0;
	for (int i = 0; i < M; i++) {
		if (a[i].sign_in < min) {
			min = a[i].sign_in;
			flag1 = i;
		}
		if (a[i].sign_out > max) {
			max = a[i].sign_out;
			flag2 = i;
		}
	}
	printf("%s %s", a[flag1].id, a[flag2].id);
	return 0;
} 
