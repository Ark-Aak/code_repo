#include <bits/stdc++.h>

//#pragma GCC optimize(2)
#define For(x, y, z) for (int x = y; x <= z; ++x)
#define Rof(x, y, z) for (int x = y; x >= z; --x)
#define Eor(u) for (int i = head[u]; i; i = nxt[i])
#define SZ(x) (int(x.size()))
#define pb push_back

using namespace std;
using i64 = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

// char buf[(1<<21)+5],*p1,*p2;
// #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

inline int read() {
	int x = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}
int __stk[128], __tp;
inline void put(i64 x) {
	if (x < 0) putchar('-'), x = -x;
	do { __stk[++__tp] = x % 10, x /= 10; } while (x);
	while (__tp) putchar(__stk[__tp--] + '0');
}

const int mod = 998244353;
inline int ksm(int x, int y, int res = 1) {
	for ( ; y; y >>= 1, x = 1ll * x * x % mod)
		(y & 1) && (res = 1ll * res * x % mod);
	return res;
}
inline int inv(int x) { return ksm(x, mod - 2); }
inline int gcd(int a, int b) { if (b) while ((a %= b) && (b %= a)); return a | b; }
inline void add(int &x, int y) { (x += y) >= mod && (x -= mod); }
inline void Min(int &x, int y) { (y < x) && (x = y); }
inline void Max(int &x, int y) { (y > x) && (x = y); }

const int N = 5e5 + 1000;
int n, m, tot, a[N], tmp[N];
bool s[N];
struct Ask { 
    int l, r;
    bool operator<(const Ask &b) const {
        return l != b.l ? l < b.l : r < b.r;
    }
}q[N];

namespace part1{
    void solve() {
        while (m--) {
            int ans = 0; For(i, 0, n) s[i] = 0;
            tot = read(); For(i, 1, tot) s[read()] ^= 1;
            For(i, 1, n) s[i] ^= s[i - 1];
            For(i, 1, n) ans += s[q[i].r] ^ s[q[i].l - 1];
            cout << ans << '\n';
        }
    }
} 


#define ls(x) (t[x].ls)
#define rs(x) (t[x].rs)
#define mid ((l + r) >> 1)

struct node {
    int ls, rs, w;
}t[N << 5];

int num, root[N];
int New(int x) { return t[++num] = t[x], num; }

void insert(int &x, int p, int l = 1, int r = n) {
    x = New(x), ++t[x].w; if (l == r) return;
    if (mid >= p) insert(ls(x), p, l, mid);
    else insert(rs(x), p, mid + 1, r);
}
void modify(int &x, int p, int l = 1, int r = n) {
    x = New(x); if (l == r) return t[x].w = 0, void();
    if (mid >= p) modify(ls(x), p, l, mid);
    else modify(rs(x), p, mid + 1, r);
    t[x].w = t[ls(x)].w + t[rs(x)].w;
}

int ask(int x, int p, int l = 1, int r = n) {
    if (r <= p) return t[x].w; ; int res = 0; 
    if (mid < p) res += ask(rs(x), p, mid + 1, r);
    return res + ask(ls(x), p, l, mid);
}

using arr = array<int, 2>;
deque<arr> dq;

void solve() {
    tot = read(); For(i, 1, tot) tmp[i] = read(); sort(tmp + 1, tmp + tot + 1); int op = 0;    
    For(i, 1, tot) { a[++op] = tmp[i]; if (op >= 2 && a[op] == a[op - 1]) op -= 2; }
    if (!op) { puts("0"); return; }
    int ans = 0; bool flag = 0; dq.clear();
    dq.push_back({1, n});
    For(i, 1, op) {
        while (dq.front()[1] < a[i]) {
            if (flag) ans += ask(root[dq.front()[0]], dq.front()[1]);
            dq.pop_front();
        }
        if (dq.front()[0] < a[i]) {
            if (flag) ans += ask(root[dq.front()[0]], a[i] - 1);
            dq.front()[0] = a[i];
        } flag ^= 1;
    }
    if (flag) for (auto x : dq) ans += ask(x[0], x[1]); 
    cout << ans << '\n';
}

signed main() {
	freopen("badge.in", "r", stdin);
	freopen("badge.out", "w", stdout);
    n = read(), m = read();
	For(i, 1, n) q[i] = {read(), read()};
    if (n <= 3000 && m <= 3000) part1::solve(), exit(0);
    sort(q + 1, q + n + 1); int p = 0;
	For(i, 1, n) {
        root[i] = root[i - 1];
        if (i - 1) modify(root[i], i - 1);
        while (p < n && q[p + 1].l == i) 
            insert(root[i], q[++p].r);
    }
    while (m--) solve();
    return 0;
}