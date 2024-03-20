#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

int n, m;
int ord[20], svash[20];
pair <int, int> aak[20];
pair <pair <int, int>, pair <int, int> > rt[50];
map <pair <int, int>, int> vig;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("perm.in", "r", stdin);
	freopen("perm.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, m) {
		int a, b, c, d;
		a = read(), b = read(), c = read(), d = read();
		rt[i] = dl(dl(a, b), dl(c, d));
	}
	int cnt = 0;
	rep (i, 1, n) {
		rep (j, i + 1, n) {
			aak[++cnt] = dl(i, j);
			vig[dl(i, j)] = cnt;
		}
	}
	rep (i, 1, cnt) ord[i] = i;
	int ans = 0;
	do {
		rep (i, 1, cnt) svash[ord[i]] = i;
		bool flg = 0;
		rep (i, 1, n) {
			rep (j, i + 1, n) {
				rep (k, j + 1, n) {
					int ca = svash[vig[dl(i, j)]];
					int cb = svash[vig[dl(j, k)]];
					int cc = svash[vig[dl(i, k)]];
					if (!(ca <= cc && cc <= cb) &&
						!(cb <= cc && cc <= ca)
					) {
						flg = 1;
						break;
					}
				}
				if (flg) break;
			}
			if (flg) break;
		}
		if (flg) continue;
		rep (i, 1, m) {
			auto F = rt[i].ec, G = rt[i].fb;
			if (svash[vig[F]] > svash[vig[G]]) {
				flg = 1;
				break;
			}
		}
		if (!flg) ans++;
	} while (next_permutation(ord + 1, ord + 1 + cnt));
	print(ans);
	return 0;
}
