#include <cstdio>
#include <string.h> 
#include <algorithm>
using namespace std;
struct Person {
	char name[10];
	int age;
	int worth;
} ps[100010];
bool cmp(Person a, Person b) {
	if (a.worth != b.worth) {
		return a.worth > b.worth;
	} else if (a.age != b.age) {
		return a.age < b.age;
	} else {
		return strcmp(a.name, b.name) < 0;
	}
}
int main() {
	int N, K;//N is 人数, K is 测试组数 
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s%d%d", ps[i].name, &ps[i].age, &ps[i].worth);
	}
	sort(ps, ps + N, cmp);
	int M, Amin, Amax;
	for (int i = 0; i < K; i++) {
		scanf("%d%d%d", &M, &Amin, &Amax);
		printf("Case #%d:\n", i + 1);
		int num = 0;
		for (int j = 0; j < N && num < M; j++) {			
			if (ps[j].age >= Amin && ps[j].age <= Amax) {
				printf("%s %d %d\n", ps[j].name, ps[j].age, ps[j].worth);
				num++;
			}
		}
		if (num == 0) {
			printf("None\n");
		}
	}
	return 0;
}
