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
int n, T, seed1, seed2, p;

bitset <50> vis;

vector <pii> S;

void dfs(int step, int cnt) {
	if (step > cnt) {

		return;
	}
	vis[step] = 1;
	dfs(step + 1, cnt);
	vis[step] = 0;
	dfs(step + 1, cnt);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("mex.in", "r", stdin);
	freopen("mex.out", "w", stdout);
#endif
#endif
	read(n), read(T), read(seed1), read(seed2), read(p);
	return 0;
}