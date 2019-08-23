#include <cstdio>
#include <queue>
using namespace std;
struct Node {
	int x, y, z;
} node;
int matrix[1290][130][70];
bool inq[1290][130][70] = {false};
int n, m, l, t;
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};
bool judge(int x, int y, int z) {
	if (x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= l) {
		return false;
	}
	if (matrix[x][y][z] == 0 || inq[x][y][z] == true) {
		return false;
	}
	return true;
}
int BFS(int x, int y, int z) {
	queue<Node> q;
	node.x = x, node.y = y, node.z = z;
	q.push(node);
	inq[x][y][z] = true;
	int ans = 1;
	while (!q.empty()) {
		Node top = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if (judge(newX, newY, newZ)) {
				node.x = newX, node.y = newY, node.z = newZ;
				q.push(node);
				inq[newX][newY][newZ] = true;
				ans++;
			}
		}
	}
	if (ans >= t) {
		return ans;
	} else {
		return 0;
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &l, &t);//x,y,z数量，大小阈值
	for (int k = 0; k < l; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &matrix[i][j][k]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < l; k++) {
				if (matrix[i][j][k] == 1 && inq[i][j][k] == false) {
					ans += BFS(i, j, k);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
