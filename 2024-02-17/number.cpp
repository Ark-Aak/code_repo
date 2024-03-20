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

int n, P, ans;
int val[15];
map <vector <int>, int> mp;

void dfs(int x, int y) {
	if (x > n) {
		vector <int> g;
		rep (i, 1, n) {
			int val = i;
			rep (i, 1, n - 1) {
				val = ::val[val];
			}
			if (val > n || val < 1) return;
			g.push_back(val);
		}
		if (mp[g] == 0) ans++, mp[g] = 1;
		ans = (ans + P) % P;
		return;
	}
	rep(i, 1, n) {
		val[x] = i;
		dfs(x + 1, i);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
#endif
#endif
	n = read(), P = read();
	dfs(1, n);
	print(ans);
	return 0;
}
