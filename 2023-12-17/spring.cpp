#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(auto i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 4e6 + 5;
int n, m, k, h[MAXN], rnk[MAXN], id[MAXN];
vector <int> pos[MAXN];
vector <int> qs[MAXN];

#define all(x) x.begin(), x.end()
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)
#define cmx(x, L, R)  mx[x] = (Q[mx[L]].r >= Q[mx[R]].r ? mx[L] : mx[R])
#define rmx(L, R) (Q[L].r >= Q[R].r ? L : R)

struct Query {
	int l, r;

	bool operator < (const Query &t) const {
		return l == t.l ? r < t.r : l < t.l;
	}
} Q[MAXN];

namespace Qseg {
	int mx[MAXN];

	void build(int x, int L, int R) {
		if (L == R) {
			if (qs[L].size()) mx[x] = *qs[L].rbegin();
			//Maintain the rightmost intervals
			return;
		}
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		//push up
		cmx(x, ls(x), rs(x));
	}

	int query(int x, int L, int R, int val) {
		if (R <= val) return mx[x];
		//Query the the rightmost interval which at the left
		//of the value
		int idL = query(ls(x), L, mid, val), idR = 0;
		if (mid < val) idR = query(rs(x), mid + 1, R, val);
		return rmx(idL, idR);
	}

	void pop(int x, int L, int R, int val) {
		if (L == R) {
			qs[L].pop_back();
			mx[x] = 0;
			if (qs[L].size()) mx[x] = *qs[L].rbegin();
			//pop the tail element
			return;
		}
		if (mid >= val) pop(ls(x), L, mid, val);
		else pop(rs(x), mid + 1, R, val);
		cmx(x, ls(x), rs(x));
	}
} // namespace Qseg

namespace Aseg {
	int mx[MAXN], lazy[MAXN], minr[MAXN], maxl[MAXN];

	void init() {
		memset(minr, 0x3f, sizeof minr);
		memset(maxl, 0xc0, sizeof maxl);
		memset(mx, 0xc0, sizeof mx);
	}

	void pushdown(int x) {
		mx[ls(x)] += lazy[x];
		mx[rs(x)] += lazy[x];
		lazy[ls(x)] += lazy[x];
		lazy[rs(x)] += lazy[x];
		lazy[x] = 0;
		//push down the lazy tag
	}

	void pushup(int x) {
		mx[x] = max(mx[ls(x)], mx[rs(x)]);
		maxl[x] = max(maxl[ls(x)], maxl[rs(x)]);
		minr[x] = min(minr[ls(x)], minr[rs(x)]);
	}

	void update(int x, int L, int R, int pos, int val) {
		if (L == R) {
			mx[x] = val;
			//remove the interval
			if (val < 0) maxl[x] = -1e9, minr[x] = 1e9;
			else maxl[x] = Q[id[L]].l + 1, minr[x] = Q[id[L]].r;
			return;
		}
		pushdown(x);
		if (pos <= mid) update(ls(x), L, mid, pos, val);
		else update(rs(x), mid + 1, R, pos, val);
		pushup(x);
	}

	int queryL(int x, int L, int R, int val) {
		//find the leftmost interval which
		//left endpoint is to the right of val
		if (L == R) return L + (maxl[x] <= val);
		if (maxl[ls(x)] <= val) return queryL(rs(x), mid + 1, R, val);
		else return queryL(ls(x), L, mid, val);
	}

	int queryR(int x, int L, int R, int val) {
		//find the rightmost interval which
		//right endpoint is to the left of val
		if (L == R) return L - (minr[x] >= val);
		if (minr[rs(x)] >= val) return queryR(ls(x), L, mid, val);
		else return queryR(rs(x), mid + 1, R, val);
	}

	void modify(int x, int L, int R, int l, int r, int val) {
		//Modify the answer
		if (l <= L && R <= r) {
			lazy[x] += val;
			mx[x] += val;
			return;
		}
		pushdown(x);
		if (l <= mid) modify(ls(x), L, mid, l, r, val);
		if (r > mid) modify(rs(x), mid + 1, R, l, r, val);
		pushup(x);
	}

	int query(int x, int L, int R) {
		//Query the point satisfies the conditions
		if (L == R) return L;
		pushdown(x);
		int res = 0;
		if (k <= mx[ls(x)]) res = query(ls(x), L, mid);
		else if (k <= mx[rs(x)]) res = query(rs(x), mid + 1, R);
		pushup(x);
		return res;
	}
} // namespace Aseg

namespace BIT {
	//Binary indexed tree
	int sum[MAXN];

	int query(int x, int res = 0) {
		for (int o = x; o; o -= o & -o)
			res += sum[o];
		return res;
	}

	void add(int x, int val) {
		if (!x) return;
		for (int o = x; o <= n; o += o & -o)
			sum[o] += val;
	}
}

int pre[MAXN], nxt[MAXN], wh[MAXN], H;

bool insert(int id) {
	if (Q[id].l <= 1) return 0;
	int x = Qseg::query(1, 1, n, Q[id].l - 1);
	//cout << "de:" << id << " " << x << " " << Q[id].l << endl;
	if (x == 0) return 0;
	if (Q[x].l <= Q[pre[id]].l || Q[x].r <= Q[pre[id]].r) return 0;
	Qseg::pop(1, 1, n, Q[x].l);
	int newAns = BIT::query(Q[x].r) - BIT::query(Q[x].l) + (h[Q[x].r] >= H);
	//cout << "newAns:" << newAns << endl;
	//update answer
	//we have put the answer into the binary indexed tree
	//to get the answer, we only need to subtract their prefix sum.
	Aseg::update(1, 1, n, rnk[x], newAns);
	pre[x] = pre[id], nxt[pre[x]] = x;
	pre[id] = x, nxt[x] = id;
	wh[Q[x].r] = x;
	return 1;
}

void init() {
	//initalization
	pre[0] = 0, nxt[0] = n + 1;
	pre[m + 1] = 0, nxt[m + 1] = n + 1;
	Q[m + 1].l = Q[m + 1].r = n + 1;
	int ptr = m + 1;
	while (insert(ptr)) ptr = pre[ptr];
	//cout << "finish init" << endl;
}

vector <pair <int, int> > op[MAXN];
int ans[MAXN];

void solve() {
	rep (i, 2, n) {
		if (h[i - 1] > h[i]) {
			op[h[i - 1]].push_back({i, 1});
			op[h[i]].push_back({i, -1});
			//we should update answer when H reach these values
			//cout << "id:" << i << endl;
		}
	}
	for (H = n; H; H--) {
		for (auto [x, v] : op[H]) {
			int invL = Aseg::queryL(1, 1, n, x);
			int invR = Aseg::queryR(1, 1, n, x);
			//intervals from invL to n are invalid
			//intervals from 1 to invR are invalid
			//cout << "info:" << x << " " << v << endl;
			//cout << "inv:" << invL << " " << invR << endl;
			if (invR + 1 <= invL - 1)
				Aseg::modify(1, 1, n, invR + 1, invL - 1, v);
			BIT::add(x, v);
			//put answer into binary indexed tree
		}
		for (int x : pos[H]) {
			if (wh[x]) {
				//cout << "wh:" << x << endl;
				Aseg::modify(1, 1, n, rnk[wh[x]], rnk[wh[x]], 1);
			}
			//modify the singel points
		}
		//cout << "mx:" << Aseg::mx[1] << endl;
		while (Aseg::mx[1] >= k) {
			//cout << "mx:" << Aseg::mx[1] << endl;
			int x = Aseg::query(1, 1, n);
			Aseg::update(1, 1, n, x, -1e9);
			//remove the intervals which has been caculated
			x = id[x];
			ans[x] = H;
			nxt[pre[x]] = nxt[x];
			pre[nxt[x]] = pre[x];
			wh[Q[x].r] = 0;
			int ptr = nxt[x];
			while (insert(ptr)) ptr = pre[ptr];
		}
	}
}

int main() {
	n = read(), m = read(), k = read();
	H = n + 1;
	rep (i, 1, n) pos[h[i] = read()].emplace_back(i);
	rep (i, 1, m) {
		qs[Q[i].l = read()].emplace_back(i);
		Q[i].r = read();
		id[i] = i;
	}
	sort(id + 1, id + 1 + m, [=](int x, int y) {
		return Q[x] < Q[y];
	});
	rep (i, 1, m) rnk[id[i]] = i;
	rep (i, 1, n) sort(all(qs[i]), [=](int x, int y) {
		return Q[x].r < Q[y].r;
	});
	Qseg::build(1, 1, n);
	Aseg::init();
	init();
	solve();
	rep (i, 1, m) print(ans[i] ? ans[i] : -1), putchar(10);
	return 0;
}
