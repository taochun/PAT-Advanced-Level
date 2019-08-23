#include <cstdio>
int main() {
	long long g1, s1, k1, g2, s2, k2, g, s, k;
	long long sum;
	scanf("%lld.%lld.%lld", &g1, &s1, &k1);
	scanf("%lld.%lld.%lld", &g2, &s2, &k2);
	sum = (g1 + g2) * 17 * 29 + (s1 + s2) * 29 + (k1 + k2);
	k = sum % 29;
	sum /= 29;
	s = sum % 17;
	g = sum / 17;
	printf("%lld.%lld.%lld", g, s, k);
	return 0;
}
