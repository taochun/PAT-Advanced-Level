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
		ll d = gcd(abs(r.up), abs(r.down));
		r.up /= d;
		r.down /= d;
	}
	return r;
}
Fraction add(Fraction f1, Fraction f2) {
	Fraction r;
	r.up = f1.up * f2.down + f2.up * f1.down;
	r.down = f1.down * f2.down;
	return reduction(r);
}
Fraction sub(Fraction f1, Fraction f2) {
	Fraction r;
	r.up = f1.up * f2.down - f2.up * f1.down;
	r.down = f1.down * f2.down;
	return reduction(r);
}
Fraction mul(Fraction f1, Fraction f2) {
	Fraction r;
	r.up = f1.up * f2.up;
	r.down = f1.down * f2.down;
	return reduction(r);
}
Fraction div(Fraction f1, Fraction f2) {
	Fraction r;
	r.up = f1.up * f2.down;
	r.down = f2.up * f1.down;
	return reduction(r);
}
void showResult(Fraction r) {
	r = reduction(r);
	if (r.up < 0) {
		printf("(");
	}//(
	if (r.down == 1) {
		printf("%lld", r.up);
	} else if (abs(r.up) > r.down) {
		printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
	} else {
		printf("%lld/%lld", r.up, r.down);
	}
	if (r.up < 0) {
		printf(")");
	}//)
}
int main() {
	Fraction a1, a2;
	scanf("%lld/%lld %lld/%lld", &a1.up, &a1.down, &a2.up, &a2.down);
	showResult(a1);//add
	printf(" + ");
	showResult(a2);
	printf(" = ");
	showResult(add(a1, a2));
	printf("\n");//end
	showResult(a1);//sub
	printf(" - ");
	showResult(a2);
	printf(" = ");
	showResult(sub(a1, a2));
	printf("\n");//end
	showResult(a1);//mul
	printf(" * ");
	showResult(a2);
	printf(" = ");
	showResult(mul(a1, a2));
	printf("\n");//end
	showResult(a1);//div
	printf(" / ");
	showResult(a2);
	printf(" = ");
	if (a2.up == 0) {
		printf("Inf");
	} else {
		showResult(div(a1, a2));	
	}
	printf("\n");//end
	return 0;
}
