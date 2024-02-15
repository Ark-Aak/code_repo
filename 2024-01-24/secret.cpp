#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 5e5 + 5;
int T, n;
int a[MAXN], b[MAXN], p[MAXN], q[MAXN];

void solve() {
	n = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n) b[i] = read();
	rep(i, 1, n) p[i] = read();
	rep(i, 1, n) q[i] = read();
	bool flg = 1;
	rep (i, 1, n) {
		if (!(p[i] == q[i] && p[i] == i)) {
			flg = 0;
			break;
		}
	}
	if (flg) return (void) puts("YES");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("serect.in", "r", stdin);
	freopen("serect.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
