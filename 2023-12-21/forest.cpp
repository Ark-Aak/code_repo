#include <bits/stdc++.h>

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

const int MAXN = 2e7 + 5;

struct node {
	int v, lazy;
};

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

namespace seg1 {
    node tr[MAXN];

    void pushdown(int x) {
        tr[ls(x)].v += tr[x].lazy;
        tr[rs(x)].v += tr[x].lazy;
        tr[ls(x)].lazy += tr[x].lazy;
        tr[rs(x)].lazy += tr[x].lazy;
        tr[x].lazy = 0;
    }

    void pushup(int x) {
        tr[x].v = max(tr[ls(x)].v, tr[rs(x)].v);
    }

    void build(int x, int L, int R) {
        if (L == R) {
            tr[x].v = L;
            return;
        }
        build(ls(x), L, mid);
        build(rs(x), mid + 1, R);
        pushup(x);
    }

    void update(int x, int L, int R, int l, int r, int k) {
        if (l <= L && R <= r) {
            tr[x].v += k;
            tr[x].lazy += k;
            return;
        }
        pushdown(x);
        if (l <= mid) update(ls(x), L, mid, l, r, k);
        if (r > mid) update(rs(x), mid + 1, R, l, r, k);
        pushup(x);
    }

    int query(int x, int L, int R) {
        if (L == R) return L;
        pushdown(x);
        if (tr[ls(x)].v >= 0) return query(ls(x), L, mid);
        return query(rs(x), mid + 1, R);
    }
}

namespace seg2 {
    node tr[MAXN];

    void pushdown(int x) {
        tr[ls(x)].v += tr[x].lazy;
        tr[rs(x)].v += tr[x].lazy;
        tr[ls(x)].lazy += tr[x].lazy;
        tr[rs(x)].lazy += tr[x].lazy;
        tr[x].lazy = 0;
    }

    void pushup(int x) {
        tr[x].v = min(tr[ls(x)].v, tr[rs(x)].v);
    }

    void build(int x, int L, int R) {
        if (L == R) {
            tr[x].v = L;
            return;
        }
        build(ls(x), L, mid);
        build(rs(x), mid + 1, R);
        pushup(x);
    }

    void update(int x, int L, int R, int l, int r, int k) {
        if (l <= L && R <= r) {
            tr[x].v += k;
            tr[x].lazy += k;
            return;
        }
        pushdown(x);
        if (l <= mid) update(ls(x), L, mid, l, r, k);
        if (r > mid) update(rs(x), mid + 1, R, l, r, k);
        pushup(x);
    }

    int query(int x, int L, int R, int l, int r) {
        if (l <= L && R <= r) return tr[x].v;
        int mn = 1e9;
        pushdown(x);
        if (l <= mid) mn = min(mn, query(ls(x), L, mid, l, r));
        if (r > mid) mn = min(mn, query(rs(x), mid + 1, R, l, r));
        return mn;
    }
}

int n;

signed main() {
    n = read();
	seg1::build(1, -2e6, 0);
	seg2::build(1, -2e6, 2e6);
	rep (i, 1, n) {
        int x = read();
        if (x < 0) seg1::update(1, -2e6, 0, x, 0, 1);
        seg2::update(1, -2e6, 2e6, -2e6, x - 1, 1);
        print(seg2::query(1, -2e6, 2e6, seg1::query(1, -2e6, 0), 2e6)), putchar(10);
    }
    return 0;
}
