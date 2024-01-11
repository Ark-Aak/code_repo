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

int n, m, a, b;
const int MAXN = 2e5 + 5, B = 774;
set <int> s[MAXN];
set <int> big;
int id[MAXN], ans[B + 5][B + 5], tans[B + 5][B + 5], cnt;
bool vis[B + 5][MAXN];

void updateAns(int id, int v) {
	if (vis[id][v]) return;
	vis[id][v] = 1;
	for (auto i : big) {
		if (i == id || !vis[i][v]) continue;
		ans[id][i] += v;
		ans[i][id] += v;
		tans[id][i]++;
		tans[i][id]++;
	}
}

void insert(int id, int v) {
	s[id].insert(v);
	if (::id[id]) updateAns(::id[id], v);
	else if (s[id].size() > B) {
		::id[id] = ++cnt;
		big.insert(cnt);
		for (auto j : s[id]) updateAns(cnt, j);
	}
}

void merge(int x, int y) {
	if (id[x] && id[y]) {
		if (s[x].size() < s[y].size()) s[x].swap(s[y]), swap(id[x], id[y]);
		big.erase(id[y]);
	}
	else if (id[y]) s[x].swap(s[y]), id[x] = id[y];
	for (auto v : s[y]) insert(x, v);
}

int query(int x, int y) {
	if (id[x] && id[y]) {
		return a ? ans[id[x]][id[y]] : tans[id[x]][id[y]];
	}
	else if (id[x] || id[y]) {
		if (id[x]) swap(x, y);
		int res = 0;
		for (auto v : s[x]) if (vis[id[y]][v]) res += a ? v : 1;
		return res;
	}
	if (s[x].size() > s[y].size()) swap(x, y);
	int res = 0;
	for (auto v : s[x]) if (s[y].count(v)) res += a ? v : 1;
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("plasticmemories.in", "r", stdin);
	freopen("plasticmemories.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), a = read(), b = read();
	rep (i, 1, n) {
		int c = read();
		insert(i, c);
	}
	while (m --> 0) {
		int k = read(), x = read(), y = read();
		if (k == 1) insert(x, y);
		else if (k == 2) merge(x, y);
		else {
			int res = query(x, y);
			if (!b && res) puts("1");
			else print(res), putchar(10);
		}
	}
	return 0;
}
