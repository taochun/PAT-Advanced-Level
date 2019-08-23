#include <cstdio>
#include <algorithm>
using namespace std;
struct Student {
	char name[20];
	char id[20];
	int grade;
} stu[10010];
bool cmp(Student a, Student b) {
	return a.grade > b.grade;
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
	}
	sort(stu, stu + N, cmp);
	int l, h;
	scanf("%d%d", &l, &h);
	int flag = 0;
	for (int i = 0; i < N; i++) {
		if (stu[i].grade >= l && stu[i].grade <= h) {
			printf("%s %s\n", stu[i].name, stu[i].id);
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("NONE\n");
	}
	return 0;
}
