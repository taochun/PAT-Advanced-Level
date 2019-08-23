#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct Student {
	int id;
	int grade[4];
} stu[2010];
int now;
int Rank[1000000][4];
char str[4] = {'A', 'C', 'M', 'E'};
bool cmp(Student a, Student b) {
	return a.grade[now] > b.grade[now];
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0) + 0.5;
	}
	for (now = 0; now < 4; now++) {
		sort(stu, stu + N, cmp);
		Rank[stu[0].id][now] = 1;
		for (int i = 1; i < N; i++) {
			if (stu[i].grade[now] == stu[i-1].grade[now]) {
				Rank[stu[i].id][now] = Rank[stu[i-1].id][now];
			} else {
				Rank[stu[i].id][now] = i + 1;
			}
		}
	}
	int query;
	for (int i = 0; i < M; i++) {
		scanf("%d", &query);
		if (Rank[query][0] == 0) {
			printf("N/A\n");
		} else {
			int min = 0;
			for (int j = 1; j < 4; j++) {
				if (Rank[query][j] < Rank[query][min]) {
					min = j;
				}
			}
			printf("%d %c\n", Rank[query][min], str[min]);	
		}

	}
//	for (int i = 0; i < M; i++) {
//		scanf("%d", &query);
//		if (Rank[query][0] == 0) {
//			printf("N/A\n");
//			continue;//break和continue的区别！！！ 
//		}
//		int min = 0;
//		for (int j = 1; j < 4; j++) {
//			if (Rank[query][j] < Rank[query][min]) {
//				min = j;
//			}
//		}
//		printf("%d %c\n", Rank[query][min], str[min]);
//	}
	return 0;
}
