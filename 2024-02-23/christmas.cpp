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

const int MAXN = 25;
int n, m, p, ans;
int l[MAXN], ch[MAXN][MAXN];

void dfs(int cnt, int step) {
	/* cout << cnt << " " << step << endl; */
	if (step > l[cnt]) {
		int lst = -1;
		if (cnt == n) {
			rep (i, 1, n) {
				int sta = 0;
				rep (j, 1, l[i]) {
					sta |= (1 << ch[i][j]);
					/* cout << ch[i][j] << " "; */
					if (j > 1 && ch[i][j] == ch[i][j - 1]) return;
				}
				if (sta == lst) return;
				lst = sta;
				/* cout << "sta = " << sta << endl; */
			}
			/* cout << endl; */
			ans++;
			ans %= p;
		}
		else dfs(cnt + 1, 1);
		return;
	}
	rep (i, 1, m) {
		ch[cnt][step] = i;
		dfs(cnt, step + 1);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("christmas.in", "r", stdin);
	freopen("christmas.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), p = read();
	rep (i, 1, n) l[i] = read();
	dfs(1, 1);
	print(ans);
	return 0;
}
