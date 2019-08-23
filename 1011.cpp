#include <cstdio>
int main() {
	double a[3][3], max[3];
	int flag[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%lf", &a[i][j]);
			if (a[i][j] > max[i]) {
				max[i] = a[i][j];
				flag[i] = j;
			}
		} 
	}
	for (int i = 0; i < 3; i++) {
		if (flag[i] == 0) {
			printf("W ");
		} else if (flag[i] == 1) {
			printf("T ");
		} else if (flag[i] == 2) {
			printf("L ");
		}
	}
	printf("%.2lf", (max[0]*max[1]*max[2]*0.65-1)*2);
	return 0;
}
