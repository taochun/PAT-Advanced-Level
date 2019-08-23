#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> stu[400010];
int hash[26 * 26 * 26 + 10 + 1];
int getID(char name[]) {
	int id;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int courseID, num;
	char name[5];
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &courseID, &num);
		for (int j = 0; j < num; j++) {
			scanf("%s", name);
			int id = getID(name);
			stu[id].push_back(courseID);
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", name);
		int id = getID(name);
		sort(stu[id].begin(), stu[id].end());
		printf("%s %lu", name, stu[id].size());
		for (int j = 0; j < stu[id].size(); j++) {
			printf(" %d", stu[id][j]);
		}
		printf("\n");
	}
	return 0;
}
