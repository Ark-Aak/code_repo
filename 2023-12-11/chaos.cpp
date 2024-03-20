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

const int MAXN = 3e5 + 5;
int n, Q;
#define blk(x) ((x) >> 9)
typedef tuple <int, int, int> tp;
const int BLK = blk(MAXN);
vector <pii> sR[MAXN];
const int inf = 1e9 + 7;

int s[MAXN], k, l[MAXN], r[MAXN], w[MAXN], cnt;

#define fi first
#define se second

namespace bp {
	namespace BLOCK {
		int shift = 0;
		ll w1[MAXN], w2[MAXN];
		void init() {
			memset(w1, 0x3f, sizeof w1);
			memset(w2, 0x3f, sizeof w2);
			shift = 1;
			while ((1 << (shift << 1)) < k) shift++;
		}
		void modify(int x, ll val) {
			for (int i = (x >> shift) - 1; ~i; i--) w2[i] = min(w2[i], val);
			for (int i = x >> shift << shift; i <= x; i++) w1[i] = min(w1[i], val);
		}
		int query(int x) {
			return min(w1[x], w2[x >> shift]);
		}
	}
	int pos[MAXN];
	ll query() {
		BLOCK::init(), BLOCK::modify(1, 0);
		pos[n + 1] = k + 1;
		for (int i = n, j = k; i >= 1; i--)
			if (s[j] == i) pos[i] = j, j--;
			else pos[i] = pos[i + 1];
		for (int i = 1, j = s[1]; i <= k; i++) {
			ll sum = 1e15;
			while (j <= n && (i == k || j < s[i + 1])) {
				for (auto it : sR[j]) sum = min(sum, BLOCK::query(pos[it.fi]) + it.se);
				j++;
			}
			if (i == k) return sum;
			if (sum <= 9e14) BLOCK::modify(i + 1, sum);
		}
		return -1;
	}
}

namespace sp {
	int calc[BLK + 5][BLK + 5];
	vector <tp> qL[BLK + 5], qR[BLK + 5];
	void update(int t) {
		int lp = blk(l[t]), rp = blk(r[t]);
		qL[lp].insert(lower_bound(qL[lp].begin(), qL[lp].end(), tp{l[t], r[t], w[t]},
					[](tp a, tp b) {return get <1> (a) > get <1> (b);}), tp{l[t], r[t], w[t]});
		qR[rp].insert(lower_bound(qR[rp].begin(), qR[rp].end(), tp{l[t], r[t], w[t]},
					[](tp a, tp b) {return get <0> (a) < get <0> (b);}), tp{l[t], r[t], w[t]});
		_rep (i, rp, lp) calc[i][lp] = min(calc[i][lp], w[t]);
	}
	int f[MAXN];
	int dis[BLK + 5][BLK + 5];
	ll query() {
		rep (i, 1, k) rep (j, 1, i) dis[i][j] = inf;
		s[k + 1] = n + 1;
		rep (i, 1, k) {
			int now = inf;
			int j = k;
			for (auto t : qL[blk(s[i])]) {
				int l, r, w;
				tie(l, r, w) = t;
				while (s[j] > r) dis[j][i] = now, --j;
				if (j < i) break;
				if (l <= s[i] && w < now) now = w;
			}
			while (j >= i) dis[j][i] = now, --j;
			now = inf, j = 1;
			for (auto t : qR[blk(s[i])]) {
				int l, r, w;
				tie(l, r, w) = t;
				while (s[j] < l) dis[i][j] = min(dis[i][j], now), ++j;
				if (j > i) break;
				if (r >= s[i] && w < now) now = w;
			}
			while (j <= i) dis[i][j] = min(dis[i][j], now), ++j;
		}
		f[0] = 0;
		rep (i, 1, k) {
			f[i] = 1e15;
			int rp = blk(s[i]) + 1;
			int t = 0, now = inf;
			rep (j, 1, i) {
				while (blk(s[j]) > t) now = min(now, calc[rp][t]), ++t;
				now = min(now, dis[i][j]);
				if (now <= 1e9) f[i] = min(f[i], f[j - 1] + now);
			}
		}
		return f[k];
	}
}

signed main() {
	read(n), read(Q);
	rep (i, 0, BLK + 1) rep (j, 0, BLK + 1) sp::calc[i][j] = inf;
	int lstans = 0;
while (Q --> 0) {
	int op;
	read(op);
	lstans %= inf;
	if (op == 1) {
		++cnt;
		read(l[cnt]), read(r[cnt]), read(w[cnt]);
		l[cnt] ^= lstans, r[cnt] ^= lstans;
		sR[r[cnt]].push_back({l[cnt], w[cnt]});
		sp::update(cnt);
	}
	else {
		read(k);
		rep (i, 1, k) read(s[i]), s[i] ^= lstans;
		sort(s + 1, s + 1 + k);
		if (k > 570) lstans = bp::query();
		else lstans = sp::query();
		if (lstans > 9e14) lstans = 0;
		print(lstans), putchar(10);
	}
}
	return 0;
}
