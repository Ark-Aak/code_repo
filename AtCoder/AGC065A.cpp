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

const int MAXN = 2e5 + 5;
int n, a[MAXN], k;
vector <int> seq;

mt19937 rnd(998244353);

int main() {
	read(n); read(k);
	rep (i, 1, n) read(a[i]);
	sort(a + 1, a + 1 + n, [](int a, int b) {return a > b;});
	int lp = 1, rp = n;
	while (lp <= rp) {
		if (seq.size() & 1) seq.push_back(a[rp--]);
		else seq.push_back(a[lp++]);
	}
	ll ans = 0;
	rep (i, 2, n) {
		ans += ((a[i] - a[i - 1]) + k) % k;
	}
	do {
		shuffle(a + 1, a + 1 + n, rnd);
		ll tans = 0;
		rep (i, 2, n) tans += ((a[i] - a[i - 1] + k) % k);
		ans = max(ans, tans);
	} while (clock() * 1.0 / CLOCKS_PER_SEC < 1.995);
	print(ans);
	return 0;
}
