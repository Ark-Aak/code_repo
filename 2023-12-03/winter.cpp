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

#define int ll

const int MAXN = 2e5 + 5;
vector <pair <int, int> > edges;
int n, a[MAXN];
bool s[MAXN];

int ans = 0, fans;

void calc(int o, int now, int fa) {
	if (now != o) ans += a[o] * a[now];
	rep (i, 1, n) {
		int u, v;
		u = edges[i].first, v = edges[i].second;
		if (s[i]) swap(u, v);
		if (u != now) continue;
		if (v == fa) continue;
		calc(o, v, now);
	}
}

void dfs(int step) {
	if (step >= n) {
		ans = 0;
		rep (i, 1, n) {
			ans += (a[i]) * (a[i] - 1);
			calc(i, i, 0);
		}
		fans = max(fans, ans);
		return;
	}
	s[step] = 1;
	dfs(step + 1);
	s[step] = 0;
	dfs(step + 1);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("winter.in", "r", stdin);
	freopen("winter.out", "w", stdout);
#endif
#endif
	edges.emplace_back(make_pair(0, 0));
	read(n);
	rep (i, 1, n) read(a[i]);
	rep (i, 1, n - 1) {
		int v;
		read(v);
		edges.push_back({i + 1, v});
	}
	dfs(1);
	print(fans);
	return 0;
}
