#include <cstdio>
int main() {
	int r, g, b;
	char arr[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
	scanf("%d", &r);
	scanf("%d", &g);
	scanf("%d", &b);
	printf("#");
	printf("%c%c", arr[r/13], arr[r%13]);
	printf("%c%c", arr[g/13], arr[g%13]);
	printf("%c%c", arr[b/13], arr[b%13]);
	return 0;
} 
