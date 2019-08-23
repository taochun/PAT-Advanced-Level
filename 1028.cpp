#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
struct Student {
	char id[10];
	char name[10];
	int grade;
} stu[100010];
int C;
bool cmp(Student a, Student b) {
	if (C == 1) {
		return strcmp(a.id, b.id) < 0;
	} else if (C == 2) {
		return (strcmp(a.name, b.name) == 0) ? (strcmp(a.id, b.id) < 0) : (strcmp(a.name, b.name) < 0);
	} else if (C == 3) {
		return (a.grade == b.grade) ? (strcmp(a.id, b.id) < 0) : a.grade < b.grade;
	}
}
int main() {
	int N;
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; i++) {
		scanf("%s %s %d", stu[i].id, stu[i].name, &stu[i].grade);
	}
	sort(stu, stu + N, cmp);
	for (int i = 0; i < N; i++) {
		printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}
