#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

mt19937 rnd(147744151);

ll d, n, w[20];
ll bel[20], cnt[20];

typedef long double ld;

#define double ld

const double eps = 1e-10;
int cmp(double a, double b) {
	if (a - b > eps) return 1;
	if (b - a > eps) return -1;
	return 0;
}

int main() {
	read(n), read(d);
	int sum = 0;
	double avg = 0;
	rep (i, 1, n) read(w[i]), sum += w[i];
	sort(w + 1, w + 1 + n);
	avg = (double) sum / (double) d;
	double ans = 1e12;
	do {
		memset(cnt, 0, sizeof cnt);
		rep (i, 1, n) bel[i] = rnd() % d + 1;
		rep (i, 1, n) cnt[bel[i]] += w[i];
		double vi = 0;
		rep (i, 1, d) vi += ((double) cnt[i] - avg) * ((double) cnt[i] - avg);
		vi /= d;
		if (cmp(ans, vi) == 1) ans = vi;
	} while ((clock() * 1.0 / CLOCKS_PER_SEC) < 1.995);
	printf("%.10Lf", ans);
	return 0;
}
