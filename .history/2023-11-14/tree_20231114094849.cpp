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

const int MAXN = 5e5 + 5;
int T, n;
vector <int> G[MAXN];

vector <int> dfs(int u, int fa) {
	vector <int> res;
	vector <vector <int> > V;
	for (auto v : G[u]) {
		if (v == fa) continue;
		V.emplace_back(dfs(v, u));
	}
	sort(V.begin(), V.end(), [](vector <int> a, vector <int> b) {
		return (*a.begin()) < (*b.begin());
	});
	for (auto v : V) {
		for (auto x : v) res.emplace_back(x);
	res.emplace_back(u);
}

vector <vector <int> > ans;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
#endif
	read(T);
	while (T --> 0) {
		read(n);
		rep (i, 1, n) G[i].clear();
		ans.clear();
		rep (i, 1, n) {
			int u, v;
			read(u), read(v);
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}
		rep (i, 1, n) ans.emplace_back(dfs(i, i));
		sort(ans.begin(), ans.end(), [](vector <int> a, vector <int> b) {
			return (*a.begin()) < (*b.begin());
		});
		for (auto v : (*ans.begin())) print(v), putchar(10);
	}
	return 0;
}