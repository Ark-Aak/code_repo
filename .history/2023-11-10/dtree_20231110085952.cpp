#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

#define int ll

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

const int MAXN = 1e6 + 5;
int n, p;
int ord[MAXN];

int calc(int l, int r) {
	if (l > r) return 0;
	if (l == r) return 0;
	int mx = 0, pos = 0;
	rep (i, l, r) {
		if (ord[i] > mx) mx = ord[i], pos = i;
	}
	int posl = 0, posr = 0;
	mx = 0;
	rep (i, l, pos - 1) if (ord[i] > mx) mx = ord[i], posl = i;
	mx = 0;
	rep (i, pos + 1, r) if (ord[i] > mx) mx = ord[i], posr = i;
	int val = posr - posl;
	if (posr == 0 || posl == 0) val = 0;
	return calc(l, pos - 1) + calc(pos + 1, r) + val;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("dtree.in", "r", stdin);
    freopen("dtree.out", "w", stdout);
#endif
#endif
    read(n), read(p);
	rep (i, 1, n) ord[i] = i;
	int ans = 0;
	do {
		ans += calc(1, n);
		ans %= p;
	} while (next_permutation(ord + 1, ord + 1 + n));
	print(ans);
	return 0;
}