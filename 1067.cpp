#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];
int main() {
	int n;
	scanf("%d", &n);
	int left = 0;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		pos[num] = i;
		if (num != i && i > 0) {
			left++;
		}
	}
	int cnt = 0, k = 1;
	while (left > 0) {
		if (pos[0] == 0){
			while (k < n) {
				if (pos[k] != k) {
					swap(pos[0], pos[k]);
					cnt++;
					break;
				}
				k++;
			}
			// for (int k = 1; k < n; k++) {
			// 	if (pos[k] != k) {
			// 		swap(pos[0], pos[k]);
			// 		cnt++;
			// 		break;
			// 	}
			// }
		}
		while (pos[0] != 0) {
			swap(pos[0], pos[pos[0]]);
			cnt++;
			left--;
		}
	}
	// while (left > 0) {
	// 	if (pos[0] != 0) {//0在位置k，交换k的位置和0的位置
	// 		swap(pos[0], pos[pos[0]]);
	// 		left--;
	// 	} else {
	// 		int k;
	// 		for (k = 1; k < n; k++) {
	// 			if (pos[k] != k) {
	// 				swap(pos[0], pos[k]);
	// 				break;
	// 			}
	// 		}
	// 	}
	// 	cnt++;
	// }
	printf("%d", cnt);
	return 0;
}
