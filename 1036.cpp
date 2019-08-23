#include <cstdio>

struct student {
	char name[15];
	char gender;
	char id[15];
	int grade;
} a[1000];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %c %s %d", a[i].name, &a[i].gender, a[i].id, &a[i].grade);
	}
	int max = -1, min = 101, diff, flag1, flag2;
	for (int i = 0; i < N; i++) {
		if (a[i].gender == 'F') {
			if (a[i].grade > max) {
				max = a[i].grade;
				flag1 = i;
			}
		} else if (a[i].gender == 'M') {
			if (a[i].grade < min) {
				min = a[i].grade;
				flag2 = i;
			}
		}
	}
	diff = max - min;
	if (max == -1) {
		printf("Absent\n");
	} else {
		printf("%s %s\n", a[flag1].name, a[flag1].id);
	}
	if (min == 101) {
		printf("Absent\n");
	} else {
		printf("%s %s\n", a[flag2].name, a[flag2].id);
	}
	if (max == -1 || min == 101) {
		printf("NA");
	} else {
		printf("%d", diff);
	}
	return 0;
}
