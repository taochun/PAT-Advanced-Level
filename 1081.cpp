#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Fraction {
	ll up;
	ll down;
};
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
Fraction reduction(Fraction r) {
	if (r.down < 0) {
		r.up = -r.up;
		r.down = -r.down;
	}
	if (r.up == 0) {
		r.down = 1;
	} else {
		ll d = gcd(r.up, r.down);
		r.up /= d;
		r.down /= d; 
	}
	return r;
}
Fraction add(Fraction a, Fraction b) {
	Fraction result;
	result.up = a.up * b.down + b.up * a.down;
	result.down = a.down * b.down;
	return reduction(result);
}
void showFraction(Fraction r) {
	if (r.down == 1) {
		printf("%lld", r.up);
	} else if (abs(r.up) > r.down) {
		printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
	} else {
		printf("%lld/%lld", r.up, r.down);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	Fraction sum, temp;
	sum.up = 0, sum.down = 1;
	for (int i = 0; i < n; i++) {
		scanf("%lld/%lld", &temp.up, &temp.down);
		sum = add(sum, temp);
	} 
	showFraction(sum);
	return 0;
}
