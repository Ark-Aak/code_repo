#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

#define int ll

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2e5 + 5;
int n, m, ans[MAXN][2];

struct edge {
	int from, to, val;

	edge(int from, int to, int val) {
		this -> from = from, this -> to = to, this -> val = val;
	}

	bool operator < (const edge &t) const {
		return val > t.val;
	}
};

vector <edge> e;
int mn[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("increase.in", "r", stdin);
	freopen("increase.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, m) {
		int u, v, w;
		read(u), read(v), read(w);
		e.emplace_back(edge(u, v, w));
	}
	sort(e.begin(), e.end());
	memset(mn, 0x3f, sizeof mn);
	for (auto v : e) {
		int from = v.from, to = v.to;
		int val1 = ans[from][0], val2 = ans[from][1];
		int val3 = ans[to][0], val4 = ans[to][1];
		if (mn[from] > val3 + 1) ans[from][1] = val3 + 1, mn[from] = val3 + 1;
		else ans[from][1] = mn[from];
		if (mn[to] > val1 + 1) ans[to][1] = val1 + 1, mn[to] = val1 + 1;
		else ans[to][1] = mn[to];
		ans[from][0] = max(ans[from][0], val4 + 1);
		ans[to][0] = max(ans[to][0], val2 + 1);
	}
	rep (i, 1, n) cout << ans[i][0] << " ";
	return 0; 
}
