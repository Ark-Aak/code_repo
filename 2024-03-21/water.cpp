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
void print(_Tp val) {
	if (val < 0) val = (~val + 1), putchar('-');
	if (val > 9) print(val / 10);
	putchar(val % 10 + '0');
}

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

int n;
int qpow(int a, int b) {
	int res = 1;
	for(; b; b >>= 1, a = 1ll * a * a % MOD)
		if(b & 1) res = 1ll * res * a % MOD;
	return res;
}

int sum[MAXN << 2], tag[MAXN << 2];

void pushdown(int x) {
	if(!tag[x]) return;
	sum[ls(x)] = tag[x];
	tag[ls(x)] = tag[x];
	sum[rs(x)] = tag[x];
	tag[rs(x)] = tag[x];
	tag[x] = 0;
}

void modify(int x, int L, int R, int l, int r, int val) {
	if(R < l || r < L) return;
	if(l <= L && R <= r) {
		sum[x] = val;
		tag[x] = val;
		return;
	}
	pushdown(x);
	modify(ls(x), L, mid, l, r, val);
	modify(rs(x), mid + 1, R, l, r, val);
}

int query(int x, int L, int R, int val) {
	if(L == R) return sum[x];
	pushdown(x);
	if(val <= mid) return query(ls(x), L, mid, val);
	else return query(rs(x), mid + 1, R, val);
}

int t[MAXN];

int lowbit(int val) {
	return val & (-val);
}

void add(int val, int y) {
	for(int i = val; i <= 2 * n; i += lowbit(i))
		t[i] += y;
}

int query(int val) {
	int res = 0;
	for(int i = val; i; i -= lowbit(i))
		res += t[i];
	return res;
}

int ask(int L, int R) {
	if(L > R) return 0;
	return query(R) - query(L - 1);
}

int ans, l[MAXN], r[MAXN], to[MAXN];
int l1[MAXN], r1[MAXN];
int l2[MAXN], r2[MAXN];
int L[MAXN][22], R[MAXN][22], sl[MAXN][22], sr[MAXN][22];

struct node {
	int tl, tr, h;
} a[MAXN];

bool cmp(node val, node y) {
	return val.tr < y.tr;
}

bool cmp2(node val, node y) {
	return val.tl < y.tl;
}

void init() {
	rep (i, 1, n) {
		l1[i] = query(1, 1, 2 * n, l[i]);
		r1[i] = query(1, 1, 2 * n, r[i]);
		modify(1, 1, 2 * n, l[i], r[i], i);
	}
	_rep (i, n, 1) {
		to[l1[i]] = max(to[l1[i]], to[i]);
		to[r1[i]] = max(to[r1[i]], to[i]);
	}
	modify(1, 1, 2 * n, 1, 2 * n, n + 1);
	_rep (i, n, 1) {
		L[i][0] = l2[i] = query(1, 1, 2 * n, l[i]);
		R[i][0] = r2[i] = query(1, 1, 2 * n, r[i]);
		modify(1, 1, 2 * n, l[i], r[i], i);
	}
	sort(a + 1, a + n + 1, cmp);
	rep (i, 1, n) {
		add(a[i].h, 1);
		sr[a[i].h][0] = ask(a[i].h, R[a[i].h][0]);
	}
	sort(a + 1, a + n + 1, cmp2);
	memset(t, 0, sizeof t);
	rep (i, 1, n) {
		add(a[i].h, 1);
		sl[a[i].h][0] = ask(a[i].h + 1, L[a[i].h][0] - 1);
	}
}

signed main() {
	cin >> n;
	rep (i, 1, n) {
		cin >> l[i] >> r[i];
		to[i] = i;
		a[i].tl = l[i];
		a[i].tr = r[i];
		a[i].h = i;
	}
	init();
	rep (j, 1, 20) {
		rep (i, 1, n) {
			L[i][j] = L[L[i][j - 1]][j - 1];
			R[i][j] = R[R[i][j - 1]][j - 1];
			sl[i][j] = sl[i][j - 1] + sl[L[i][j - 1]][j - 1];
			sr[i][j] = sr[i][j - 1] + sr[R[i][j - 1]][j - 1];
		}
	}
	rep (i, 1, n) {
		int cnt = 0, val = i;
		_rep (j, 20, 0) {
			if(R[val][j] != 0 && R[val][j] <= L[to[i]][0]) {
				cnt += sr[val][j];
				val = R[val][j];
			}
		}
		val = i;
		_rep (j, 20, 0) {
			if(L[val][j] != 0 && L[val][j] <= L[to[i]][0]) {
				cnt -= sl[val][j];
				val = L[val][j];
			}
		}
		ans = (ans + qpow(cnt, MOD - 2)) % MOD;
	}
	cout << ans;
	return 0;
}
