#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Student {
	long long id;
	int t;//talent
	int v;//virtue
	int total;
};
bool cmp(Student a, Student b) {
	if (a.total != b.total) {
		return a.total > b.total;
	} else if (a.v != b.v) {
		return a.v > b.v;
	} else {
		return a.id < b.id;
	}
}
int main() {
	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	vector<Student> v1, v2, v3, v4;
	while (N--) {
		Student stu;
		scanf("%lld %d %d", &stu.id, &stu.v, &stu.t);
		stu.total = stu.v + stu.t;
		if (stu.v >= L && stu.t >= L) {
			if (stu.v >= H && stu.t >= H) {
				v1.push_back(stu);
			} else if (stu.v >= H && stu.t < H) {
				v2.push_back(stu);
			} else if (stu.v < H && stu.t < H && stu.v >= stu.t) {
				v3.push_back(stu);
			} else {
				v4.push_back(stu);
			}
		}
	}
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	sort(v3.begin(), v3.end(), cmp);
	sort(v4.begin(), v4.end(), cmp);
	printf("%d\n", v1.size() + v2.size() + v3.size() + v4.size());
	for (int i = 0; i < v1.size(); i++) {
		printf("%lld %d %d\n", v1[i].id, v1[i].v, v1[i].t);
	}
	for (int i = 0; i < v2.size(); i++) {
		printf("%lld %d %d\n", v2[i].id, v2[i].v, v2[i].t);
	}
	for (int i = 0; i < v3.size(); i++) {
		printf("%lld %d %d\n", v3[i].id, v3[i].v, v3[i].t);
	}
	for (int i = 0; i < v4.size(); i++) {
		printf("%lld %d %d\n", v4[i].id, v4[i].v, v4[i].t);
	}
	return 0;
} 
