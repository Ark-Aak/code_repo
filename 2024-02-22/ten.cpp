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

const int MAXN = 2e5 + 5;
int n, l[MAXN], r[MAXN], ans;
const int MOD = 998244353;
bool ch[MAXN];

void dfs(int step) {
	if (step > n) {
		int cnt = 0;
		rep (i, 1, n) {
			if (!ch[i]) continue;
			++cnt;
			rep (j, 1, n) {
				if (!ch[j]) continue;
				if (!(l[i] <= j && j <= r[i] && l[j] <= i && i <= r[j])) {
					return;
				}
			}
		}
		if (cnt == 0) return;
		ans++;
		ans %= MOD;
		return;
	}
	ch[step] = 1;
	dfs(step + 1);
	ch[step] = 0;
	dfs(step + 1);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ten.in", "r", stdin);
	freopen("ten.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) l[i] = read();
	rep (i, 1, n) r[i] = read();
	dfs(1);
	print(ans);
	return 0;
}
