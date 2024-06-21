#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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

int n, k, m;
int perm[25], d[25], ans[25], pos[25];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("inv.in", "r", stdin);
	freopen("inv.out", "w", stdout);
#endif
#endif
	n = read(), k = read(), m = read();
	rep (i, 1, n) perm[i] = i;
	do {
		int cnt = 0;
		rep (i, 1, n) rep (j, i + 1, n) if (perm[i] > perm[j]) cnt++;
		if (cnt == k) {
			/* rep (i, 1, n) cerr << perm[i] << " "; */
			/* cerr << endl; */
			rep (i, 1, n) pos[perm[i]] = i;
			rep (_i, 1, n) {
				int i = pos[_i];
				if (perm[i] == 1) {
					d[i] = 1;
					continue;
				}
				int l = -1, r = 1e9;
				rep (j, 1, i - 1) {
					if (perm[j] < perm[i]) l = max(l, j);
				}
				rep (j, i + 1, n) {
					if (perm[j] < perm[i]) r = min(r, j);
				}
				if (r == 1e9 || (l != -1 && perm[l] > perm[r])) d[i] = d[l] + 1;
				else d[i] = d[r] + 1;
			}
			rep (i, 1, n) ans[i] += d[i] % m, ans[i] %= m;
		}
	} while (next_permutation(perm + 1, perm + n + 1));
	rep (i, 1, n) print(ans[i]), putchar(' ');
	puts("");
	return 0;
}
