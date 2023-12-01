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

const int MAXN = 200 + 5;
int n, p[MAXN], ans;

bitset <MAXN> vis;

function <void (int)> dfs = [](int step) {
	if (step > n) {
		vector <int> a, b;
		rep (i, 1, n) {
			if (vis[i]) a.emplace_back(p[i]);
			else b.emplace_back(p[i]);
		}
		int pmax[MAXN] = {0};
		int pmin[MAXN] = {INT_MAX};
		rep (i, 0, ((int) a.size()) - 1) {
			pmax[i + 1] = max(pmax[i], a[i]);
		}
		rep (i, 0, ((int) b.size()) - 1) {
			pmin[i + 1] = min(pmin[i], b[i]);
		}
		int cnt = 0;
		rep (i, 1, (int) a.size()) {
			if (pmax[i] != pmax[i - 1]) cnt++;
		}
		rep (i, 1,(int) b.size()) {
			if (pmin[i] != pmin[i - 1]) cnt++;
		}
		ans = max(ans, cnt);
		return;
	}
	vis[step] = 1;
	dfs(step + 1);
	vis[step] = 0;
	dfs(step + 1);
};

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
#endif
#endif
	cerr << "sb";
	read(n);
	rep (i, 1, n) read(p[i]);
	dfs(1);
	print(ans);
	return 0;
}