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

const int MAXN = 2e5 + 5;
int n, m, root, sum, cnt;
vector <pair <int, int> > G[MAXN];
int siz[MAXN], p[MAXN];
bool vis[MAXN];
pair <int, int> r[MAXN];

void update_root(int u, int fa) {
	cout << "update_root: " << u << endl;
	siz[u] = 1, p[u] = 0;
	for (auto v : G[u]) {
		if (v.first == fa || vis[v.first]) continue;
		update_root(v.first, u);
		siz[u] += siz[v.first];
		p[u] = max(p[u], siz[v.first]);
	}
	p[u] = max(p[u], sum - siz[u]);
	if (p[u] < p[root]) root = u;
}

void get_dis(int u, int fa, int mx, int mn) {
	cout << "get_dis: " << u << endl;
	r[++cnt] = make_pair(mx, mn);
	cout << mx << " " << mn << endl;
	siz[u] = 1;
	for (auto v : G[u]) {
		if (v.first == fa || vis[v.first]) continue;
		get_dis(v.first, u, max(v.second, mx), min(mn, v.second));
		siz[u] += siz[v.first];
	}
}

int s[MAXN], ans;

int lowbit(int x) {
	return x & -x;
}

void add(int x, int val) {
	if (!x) return;
	while (x <= n) {
		cout << "add: " << x << endl;
		system("pause");
		s[x] += val;
		x += lowbit(x);
	}
}

int query(int x) {
	int res = 0;
	while (x) {
		cout << "query: " << x << endl;
		res += s[x];
		x -= lowbit(x);
	}
	return res;
}

int calc(int u, int mn, int mx) {
	cout << "calc: " << u << endl;
	cnt = 0;
	get_dis(u, 0, mx, mn);
	sort(r + 1, r + cnt + 1);
	ll ans = 0;
	rep (i, 1, cnt) {
		if (r[i].first > m) ans += query(r[i].first - m) - query(r[i].first - m - 1);
		else if (r[i].first - r[i].second <= m) {
			ans += query(n) - query(r[i].second - 1);
		}
		add(r[i].second, 1);
	}
	rep (i, 1, cnt) add(r[i].second, -1);
	return ans;
}

void solve(int u) {
	cout << "solve: " << u << endl;
	vis[u] = 1;
	ans += calc(u, -n, n);
	for (auto x : G[u]) {
		int v = x.first;
		if (vis[v]) continue;
		ans -= calc(v, x.second, x.second);
		sum = siz[v];
		p[root = 0] = 1e9;
		update_root(v, 0);
		solve(root);
	}
}

int main() {
	read(n), read(m);
	rep (i, 1, n - 1) {
		int u, v, w;
		read(u), read(v), read(w);
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	p[root] = sum = n;
	update_root(1, 0);
	update_root(root, 0);
	solve(root);
	cout << ans << endl;
	return 0;
}