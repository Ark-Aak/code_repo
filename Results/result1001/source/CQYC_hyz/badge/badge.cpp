#include<bits/stdc++.h>
#define ls (lr << 1)
#define rs (lr << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;

inline int read() {
	int x = 0, f = 0; char ch = getchar();
	while(ch < '0' or ch > '9') f |= (ch == '-'), ch = getchar();
	while(ch >= '0' and ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int __stk[128], __top;
inline void write(int x) {
    if(x < 0) putchar('-'), x = -x;
	do { __stk[++__top] = x % 10, x /= 10; } while(x);
	while (__top) putchar(__stk[__top--] + '0');
}
bool stmer;

const int N = 5e5 + 10;

struct node {
    int l, r;
} a[N];

int n, q, sq;
int bl[N];

bool cmp1(node x, node y) { return x.l == y.l ? x.r > y.r : x.l < y.l; }
bool cmp2(node x, node y) { return x.r < y.r; }

vector<node> v[N << 2];

void modify1(int l, int r, int L, int R, int x, int lr) {
    if(l >= L and r <= R) {
        if(v[lr].empty() or v[lr].back().r != x - 1) v[lr].push_back({ x, x });
        else v[lr].back().r++; return;
    }
    if(mid >= L) modify1(l, mid, L, R, x, ls);
    if(mid < R) modify1(mid + 1, r, L, R, x, rs);
}

struct tree {
    int a, b, tag;
} t[N << 2];

int tot;
int vis[N << 2];

void update(int l, int r, int x, int lr) {
    if(vis[lr] != tot) t[lr] = { r - l + 1, 0, 0 }, vis[lr] = tot;
    if(x) swap(t[lr].a, t[lr].b), t[lr].tag ^= 1;
}

void pushdown(int l, int r, int lr) {
    update(l, mid, t[lr].tag, ls), update(mid + 1, r, t[lr].tag, rs);
    t[lr].tag = 0;
}

void modify(int l, int r, int L, int R, int lr) {
    // if(lr == 1) cerr << l << ' ' << r << " " << L << " " << R << '\n';
    if(vis[lr] != tot) t[lr] = { r - l + 1, 0, 0 }, vis[lr] = tot;
    if(l >= L and r <= R) return update(l, r, 1, lr); pushdown(l, r, lr);
    if(mid >= L) modify(l, mid, L, R, ls);
    if(mid < R) modify(mid + 1, r, L, R, rs);
    t[lr].a = t[ls].a + t[rs].a, t[lr].b = t[ls].b + t[rs].b;
}

void modify2(int l, int r, int x, int lr) {
    for(node p : v[lr]) modify(1, n, p.l, p.r, 1);
    if(l ^ r) mid >= x ? modify2(l, mid, x, ls) : modify2(mid + 1, r, x, rs);
}

bool edmer;
signed main() {
	freopen("badge.in", "r", stdin);
	freopen("badge.out", "w", stdout);
	cerr << "[Memory] " << (&stmer - &edmer) / 1024 / 1024 << " MB\n";
	
    n = read(), q = read(), sq = sqrt(n);
    for(int i = 1; i <= n; i++) a[i] = { read(), read() }, bl[i] = i / sq;

    sort(a + 1, a + n + 1, cmp1);
    
    for(int i = 1; i <= n; i++) modify1(1, n, a[i].l, a[i].r, i, 1);

    while(q--) {
        int m = read(); tot++;
        for(int i = 1; i <= m; i++) {
            int x = read();
            modify2(1, n, x, 1);
        }
        write(vis[1] == tot ? t[1].b : 0), putchar('\n');
    }

    cerr << "[Runtime] " << (double) clock() / CLOCKS_PER_SEC << " seconds";
	return 0;
} 