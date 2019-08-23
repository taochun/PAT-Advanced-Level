#include <cstdio>
#include <cstring>//strcmp
#include <vector>//vector
#include <algorithm>//sort
using namespace std;
char name[40010][5];
vector<int> course[2510];
bool cmp(int a, int b) {
	return strcmp(name[a], name[b]) < 0;
}
int main() {
	int n, k;//人数，课程数
	scanf("%d%d", &n, &k);
	int num, courseID;
	for (int i = 0; i < n; i++) {
		scanf("%s%d", name[i], &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &courseID);
			course[courseID].push_back(i);
		}
	}
	for (int i = 1; i <= k; i++) {
		printf("%d %lu\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for (int j = 0; j < course[i].size(); j++) {
			printf("%s\n", name[course[i][j]]);
		}
	}
	return 0;
}
