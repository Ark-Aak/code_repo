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

const int MAXN = 1e6 + 5;

int n, q, opt, l, r, x, y, cnt[MAXN], nw[MAXN], idx, f[MAXN], to[MAXN];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

struct node {
    int l, r, val;
    inline bool operator<(const node y) const { return l < y.l; }
};

set<node> S;

struct node2 {
    int cnt, val;
    inline bool operator<(const node2 y) const { return cnt == y.cnt ? val < y.val : cnt > y.cnt; }
};

set<node2> T;

inline void add(int x, int y) {
    T.erase((node2){ cnt[x], to[x] });
    T.insert((node2){ cnt[x] += y, to[x] });
}

inline auto split(int x) {
    auto It = S.lower_bound((node){ x, 0, 0 });
    if ((*It).l == x)
        return It;
    node it = *(--It);
    S.erase(It);
    if (it.l < x)
        S.insert((node){ it.l, x - 1, it.val });
    return S.insert((node){ x, it.r, it.val }).first;
}

inline void change(int l, int r, int x) {
    auto rt = split(r + 1), lt = split(l);
    node j;
    for (auto i = lt; i != rt; ++i) {
        j = *i;
        add(find(j.val), -(j.r - j.l + 1));
    }
    S.erase(lt, rt);
    add(x, r - l + 1);
    S.insert((node){ l, r, x });
}

signed main() {
    freopen("major.in", "r", stdin);
    freopen("major.out", "w", stdout);
	n = read(), q = read();
    S.insert((node){ 1, n, 0 });
    idx = 3e5;
    cnt[0] = n;
    for (int i = 0; i <= idx; ++i) {
        nw[i] = to[i] = f[i] = i;
        T.insert((node2){ cnt[i], i });
    }
    while (q--) {
		opt = read();
        if (opt == 1) {
			l = read(), r = read(), x = read();
            change(l, r, nw[x]);
        }
        if (opt == 2) {
			x = read(), y = read();
            if (x == y)
                continue;
            y = nw[y];
            f[nw[x]] = y;
            T.erase((node2){ cnt[nw[x]], x });
            add(y, cnt[nw[x]]);
            to[nw[x] = ++idx] = x;
            f[idx] = idx;
            T.insert((node2){ 0, x });
        }
        if (opt == 3) {
			x = read(), y = read();
            if (x == y)
                continue;
            T.erase((node2){ cnt[nw[x]], x });
            T.erase((node2){ cnt[nw[y]], y });
            swap(to[nw[x]], to[nw[y]]);
            swap(nw[x], nw[y]);
            T.insert((node2){ cnt[nw[x]], x });
            T.insert((node2){ cnt[nw[y]], y });
        }
        if (opt == 4) {
			x = read();
            print(cnt[nw[x]]), putchar(10);
        }
        if (opt == 5) {
            print((*T.begin()).val), putchar(10);
        }
    }
    return 0;
}
