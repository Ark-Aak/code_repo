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
int n, m, a[MAXN];
int l[MAXN], r[MAXN], c[MAXN], t[MAXN];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("essence.in", "r", stdin);
	freopen("essence.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, n) read(a[i]);
	rep (i, 1, m) {
		read(l[i]), read(r[i]), read(c[i]), read(t[i]);
	}
	if (m == 1) {
		int L = l[1], R = r[1];
		if (t[1]) {
			rep (i, 1, n) {
				vector <int> a;
				rep (i, 1, a.size()) {

				}
			}
		}
		else {
			int tc = c[1];
			rep (i, 1, n) {
				tc -= a[i];
			}
			if (tc < 0) tc = 0;
			cout << c[1] - tc;
		}
	}
	return 0;
}