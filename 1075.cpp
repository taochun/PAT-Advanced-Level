#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student {
	int id;
	int s[6];
	int total;
	int rank;
	int perfect;
	int flag;
} stu[10010];
int N, K, M;
int full[6];
bool cmp(Student a, Student b) {
	if (a.total != b.total) {
		return a.total > b.total;
	} else if (a.perfect != b.perfect) {
		return a.perfect > b.perfect;
	} else {
		return a.id < b.id;
	}
}
void init() {
	for (int i = 1; i <= N; i++) {
		stu[i].id = i;
		stu[i].total = 0;
		stu[i].perfect = 0;
		stu[i].flag = 0;
		memset(stu[i].s, -1, sizeof(stu[i].s));
	}
}
int main() {
	scanf("%d%d%d", &N, &K, &M);
	init();
	for (int i = 1; i <= K; i++) {
		scanf("%d", &full[i]);
	}
	int id, idx, score;
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", &id, &idx, &score);
		if (score == full[idx] && stu[id].s[idx] < full[idx]) {//bug
			stu[id].perfect++;
		}
		if (score > stu[id].s[idx]) {
			stu[id].s[idx] = score;
		}
		if (score == -1 && stu[id].s[idx] == -1) {
			stu[id].s[idx] = 0;
		}
		if (score != -1) {
			stu[id].flag = 1;
		}
	}	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (stu[i].s[j] != -1) {
				stu[i].total += stu[i].s[j];
			}
		}
	}
	sort(stu + 1, stu + 1 + N, cmp);
	stu[1].rank = 1;
	for (int i = 2; i <= N; i++) {
		if (stu[i].total == stu[i-1].total) {
			stu[i].rank = stu[i-1].rank;
		} else {
			stu[i].rank = i;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (stu[i].flag == 1) {
			printf("%d %05d %d", stu[i].rank, stu[i].id, stu[i].total);
			for (int j = 1; j <= K; j++) {
				if (stu[i].s[j] != -1) {
					printf(" %d", stu[i].s[j]);
				} else if (stu[i].s[j] == -1) {
					printf(" -");
				}
			}
			printf("\n");
		}
	}
	return 0;
} 
