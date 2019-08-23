#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Student {
	long long id;
	int score;
	int loc_n;//考场号 
	int loc_r;//考场排名 
	int fin_r;//总排名 
};
bool cmp(Student a, Student b) {
	return a.score != b.score ? a.score > b.score : a.id < b.id;
}

int main() {
	int N, K;
	scanf("%d", &N);
	vector<Student> fin;
	for (int i = 1; i <= N; i++) {//N个考场 
		scanf("%d", &K);
		vector<Student> v(K);
		for (int j = 0; j < K; j++) {//K个考生 
			scanf("%lld %d", &v[j].id, &v[j].score);
			v[j].loc_n = i;
		}
		sort(v.begin(), v.end(), cmp);
		v[0].loc_r = 1;
		fin.push_back(v[0]);
		for (int i = 1; i < v.size(); i++) {
			v[i].loc_r = (v[i].score == v[i-1].score) ? v[i-1].loc_r : i + 1;
			fin.push_back(v[i]);
		}
	}
	sort(fin.begin(), fin.end(), cmp);
	fin[0].fin_r = 1;
	for (int i = 1; i < fin.size(); i++) {
		fin[i].fin_r = (fin[i].score == fin[i-1].score) ? fin[i-1].fin_r : i + 1;
	}
	printf("%d\n", fin.size());
	for (int i = 0; i < fin.size(); i++) {
		printf("%013lld %d %d %d", fin[i].id, fin[i].fin_r, fin[i].loc_n, fin[i].loc_r);
		if (i != fin.size() - 1) {
			printf("\n");
		}
	}
	return 0;
}
