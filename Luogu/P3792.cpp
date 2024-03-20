#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define _rep(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f*=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

#define blockId(x) (x / BLOCK_SIZE)

const int MAXN = 5e5 + 5;
int BLOCK_SIZE, qcnt;

struct Query {
	int l, r, id, t, cnt;
	bool operator < (const Query &T) const {
		return blockId(l) == blockId(T.l) ? 
			blockId(r) == blockId(T.r) ?
			t < T.t : r < T.r : l < T.l;
	}
} query[MAXN];

struct Modify {
	int x, val, t;
} mfy[MAXN];

#define mid ((L + R) >> 1)
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)

int mx[MAXN << 2], mn[MAXN << 2];
int a[MAXN];

inline void pushup(int x) {
	mx[x] = max(mx[ls(x)], mx[rs(x)]);
	mn[x] = min(mn[ls(x)], mn[rs(x)]);
}

inline void build(int x, int L, int R) {
	if (L == R) return (void) (mx[x] = mn[x] = a[L]);
	build(ls(x), L, mid);
	build(rs(x), mid + 1, R);
	pushup(x);
}

inline void modify(int x, int L, int R, int p, int val) {
	if (p < L || p > R) return;
	if (L == p && R == p) return (void) (mx[x] = mn[x] = val);
	if (p <= mid) modify(ls(x), L, mid, p, val);
	else modify(rs(x), mid + 1, R, p, val);
	pushup(x);
}

inline int queryMax(int x, int L, int R, int l, int r) {
	if (l <= L && R <= r) return mx[x];
	int res = 0;
	if (l <= mid) res = max(res, queryMax(ls(x), L, mid, l, r));
	if (r > mid) res = max(res, queryMax(rs(x), mid + 1, R, l, r));
	return res;
}

inline int queryMin(int x, int L, int R, int l, int r) {
	if (l <= L && R <= r) return mn[x];
	int res = INT_MAX;
	if (l <= mid) res = min(res, queryMin(ls(x), L, mid, l, r));
	if (r > mid) res = min(res, queryMin(rs(x), mid + 1, R, l, r));
	return res;
}

int cnt[MAXN * 50];
int repeat_cnt;

inline void add(int x) {
	++cnt[x];
	if (cnt[x] == 1) repeat_cnt++;
}

inline void del(int x) {
	--cnt[x];
	if (cnt[x] == 0) repeat_cnt--;
}

int n, m, fans[MAXN], rcnt;

signed main() {
	n = read(), m = read();
	BLOCK_SIZE = sqrt(n);
	rep (i, 1, n) a[i] = read();
	build(1, 1, n);
	rep (i, 1, m) {
		int op, x, y;
		op = read(), x = read(), y = read();
		if (op == 1) {
			mfy[++rcnt].x = x;
			mfy[rcnt].val = y;
			mfy[rcnt].t = i;
			modify(1, 1, n, x, y);
		}
		else query[++qcnt] = (Query) {x, y, qcnt, rcnt, queryMax(1, 1, n, x, y) - queryMin(1, 1, n, x, y)};
	}
	sort(query + 1, query + 1 + qcnt);
	int L = 1, R = 0, T = 0;
	rep (i, 1, qcnt) {
        int l = query[i].l, r = query[i].r, _id = query[i].id, t = query[i].t, cnt = query[i].cnt;
		while (L < l) del(a[L++]);
		while (L > l) add(a[--L]);
		while (R < r) add(a[++R]);
		while (R > r) del(a[R--]);
		while (T < t) {
			T++;
			if (mfy[T].x >= L && mfy[T].x <= R) del(a[mfy[T].x]);
			swap(mfy[T].val, a[mfy[T].x]);
			if (mfy[T].x >= L && mfy[T].x <= R) add(a[mfy[T].x]);
		}
		while (T > t) {
			if (mfy[T].x >= L && mfy[T].x <= R) del(a[mfy[T].x]);
			swap(mfy[T].val, a[mfy[T].x]);
			if (mfy[T].x >= L && mfy[T].x <= R) add(a[mfy[T].x]);
			T--;
		}
		fans[_id] = (repeat_cnt == R - L + 1);
		if (cnt != R - L) fans[_id] = 0;
	}
	rep (i, 1, qcnt) printf("%s", (fans[i] ? "damushen\n" : "yuanxing\n"));
	return 0; 
}
