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

const int MAXN = 605;
int f[MAXN][MAXN];
int n, m, q;
string s, t;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
#endif
	cin >> n >> m >> q;
	cin >> s >> t;
	while (q--) {
		int l1 = read(), r1 = read(), l2 = read(), r2 = read();
		memset(f, 0, sizeof f);
		rep(i, 1, n) rep(j, 1, m) {
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if (s[i - 1] == t[j - 1] && i >= l1 && i <= r1 && j >= l2 && j <= r2) {
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
			}
		}
		print(f[n][m]), putchar(10);
	}
	return 0;
}
