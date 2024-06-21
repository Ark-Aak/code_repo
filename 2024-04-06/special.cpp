#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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

const int MAXN = 5e5 + 5;
int n, p[MAXN], q[MAXN], cnt[MAXN][2], fa[MAXN];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

struct node {
	int id, cnt0, cnt1;

	bool operator < (const node &t) const {
		if (cnt0 * t.cnt1 == cnt1 * t.cnt0) {
			if (cnt0 == t.cnt0) {
				if (cnt1 == t.cnt1) return id < t.id;
				else return cnt1 < t.cnt1;
			}
			else return cnt0 < t.cnt0;
		}
		else return cnt0 * t.cnt1 < cnt1 * t.cnt0;
	}
};

map <node, bool> mp;

priority_queue <node> Q;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("special.in", "r", stdin);
	freopen("special.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 2, n) p[i] = read();
	rep (i, 1, n) q[i] = read();
	rep (i, 1, n) cnt[i][q[i]] = 1;
	rep (i, 2, n) Q.push((node) {i, cnt[i][0], cnt[i][1]});
	rep (i, 1, n) fa[i] = i;
	int ans = 0;
	rep (i, 2, n) {
		while (Q.size() && mp[Q.top()]) Q.pop();
		node t = Q.top(); Q.pop();
		int id = t.id;
		int f = find(p[id]);
		mp[(node) {f, cnt[f][0], cnt[f][1]}] = 1;
		if (f > 1) Q.push((node) {f, cnt[f][0] + cnt[id][0], cnt[f][1] + cnt[id][1]});
		ans += cnt[f][1] * cnt[id][0];
		/* cout << cnt[f][1] << " " << cnt[id][0] << endl; */
		cnt[f][0] += cnt[id][0];
		cnt[f][1] += cnt[id][1];
		fa[id] = f;
	}
	print(ans);
	return 0;
}
