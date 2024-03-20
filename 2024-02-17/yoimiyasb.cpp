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

const int MAXN = 2005;
int T, n, a[MAXN], _l[MAXN], _r[MAXN], l[MAXN], r[MAXN];
const int MOD = 998244353;
int fa[MAXN];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) { fa[find(x)] = find(y); }

void solve() {
	n = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) _l[i] = read(), _r[i] = read();
	rep (k, 1, n / 2) {
		rep (i, 1, n) l[i] = _l[i], r[i] = _r[i];
		rep (i, 1, n) fa[i] = i;
		int ans = 1;
		rep (i, 1, n) {
			rep (j, i, n) {
				if ((j - i + 1) & 1) continue;
				if (j - i + 1 > k * 2) break;
				int mid = (i + j) >> 1;
				bool flg = 0;
				rep (i, 1, mid) {
					if (a[i] != a[i + mid]) {
						flg = 1;
						break;
					}
				}
				if (flg) continue;
				rep (i, 1, mid) {
					l[i] = max(l[i], l[i + mid]);
					r[i] = min(r[i], r[i + mid]);
					l[i + mid] = max(l[i + mid], l[i]);
					r[i + mid] = min(r[i + mid], r[i]);
					if (find(i) != find(i + mid)) merge(i, i + mid);
				}
			}
		}
		rep (i, 1, n) if (find(i) == i) {
			if (l[i] > r[i]) {
				ans = 0;
				break;
			}
			ans = ans * (r[i] - l[i] + 1) % MOD;
		}
		print(ans), putchar(32);
	}
	putchar(10);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("yoimiya.in", "r", stdin);
	freopen("yoimiya.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
