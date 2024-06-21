#include <bits/stdc++.h>

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

const int MAXN = 1e3 + 5;
int ch[MAXN];
int n, m, u[MAXN], v[MAXN];
int ans[MAXN];

void dfs(int step) {
	if (step > m) {
		int l = n + 1, r = -1;
		rep (i, 1, n)  if (ch[i] == 1) l = min(l, i), r = max(r, i);
		rep (i, l, r) if(ch[i]==0) return;
		if (~r) {
			int ls = 0, rs = 0;
			int len = r - l + 1;
			while (ch[l - 1] == 2) l--, ls++;
			while (ch[r + 1] == 2) r++, rs++;
			rep (i, 0, ls) rep (j, 0, rs) ans[i + j + len] = (ans[i + j + len] + 1) & 1;
		}
		else {
			int len = 0;
			rep (i, 1, n + 1) {
				if (ch[i] == 2) len++;
				else {
					rep (i, 1, len) ans[i] = (ans[i] + len - i + 1) & 1;
					len = 0;
				}
			}
		}
		return;
	}
	int L = u[step], R = v[step];
	int l = ch[L], r = ch[R];
	if (l == 2 && r == 2) {
		ch[L] = ch[R] = 1;
		dfs(step + 1);
		ch[L] = ch[R] = 0;
		dfs(step + 1);
		ch[L] = ch[R] = 2;
	}
	else if (l == 1 && r == 2) {
		ch[L] = 2, ch[R] = 1;
		dfs(step + 1);
		ch[L] = 1, ch[R] = 2;
	}
	else if ((l == 0 && r == 2) || (l == 2 && r == 1)) {
		dfs(step + 1);
	}
	else if (l == 2 && r == 0) {
		ch[L] = 0, ch[R] = 2;
		dfs(step + 1);
		ch[L] = 2, ch[R] = 0;
	}
	else {
		if (l == 1 && r == 0) {
			swap(ch[L], ch[R]);
			dfs(step + 1);
			swap(ch[L], ch[R]);
		}
		else dfs(step + 1);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, m) u[i] = read(), v[i] = read();
	rep (i, 1, n) ch[i] = 2;
	dfs(1);
	rep (i, 1, n) print(ans[i]), putchar(32);
	return 0;
}
