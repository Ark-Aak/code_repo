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

const int MAXN = 2005;
int n, m, k;

struct query {
	int l, r;
} q[MAXN];

auto comp = [](query a, query b) {
	return a.l == b.l ? a.r > b.r : a.l < b.l;
};

auto comp2 = [](query a, query b) {
	return a.l == b.l ? a.r < b.r : a.l < b.l;
};

auto calc = [](int a, int b, int c) {
	if (a < b) return c - b + 1;
	else return c - b + 1 - (a - b + 1);
};

vector <query> rg;
int f[MAXN][MAXN];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
#endif
#endif
	cin >> n >> m >> k;
	rep (i, 1, m) cin >> q[i].l >> q[i].r;
	sort(q + 1, q + 1 + m, comp);
	rg.emplace_back((query) {0, 0});
	rg.emplace_back(q[1]);
	rep (i, 2, m) {
		query lst = rg[rg.size() - 1];
		if (q[i].r <= lst.r) continue;
		rg.emplace_back(q[i]);
	}
	sort(rg.begin(), rg.end(), comp2);
	m = rg.size() - 1;
	rep (i, 1, m) {
		rep (j, 1, k) {
			rep (l, 0, rg[i].r - 1) {
				f[rg[i].r][j] = max(f[rg[i].r][j], f[l][j - 1] + calc(l, rg[i].l, rg[i].r));
			}
		}
	}
	int ans = 0;
	rep (i, 0, n) {
		rep (j, 1, k) {
			ans = max(ans, f[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}
