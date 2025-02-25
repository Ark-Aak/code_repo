#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 2e5 + 5, V = 1e9;
int n, q, a[MAXN], root[MAXN], cnt;

struct node {
    int ls, rs, sum;
} t[MAXN * 50];

#define ls(x) t[x].ls
#define rs(x) t[x].rs
#define mid ((L + R) >> 1)

void change(int &x, int y, int L, int R, int d, int p) {
    x = ++cnt;
	t[x] = t[y];
	t[x].sum = max(t[x].sum, p);
	if (L == R) return;
    if (mid >= d) change(ls(x), ls(y), L, mid, d, p);
    else change(rs(x), rs(y), mid + 1, R, d, p);
}

int query(int x, int L, int R, int l, int r) {
	if (l > r) return 0;
	if (l <= L && R <= r) return t[x].sum;
    int res = 0;
    if (mid >= l) res = query(ls(x), L, mid, l, r);
    if (mid < r) res = max(res, query(rs(x), mid + 1, R, l, r));
    return res;
}

signed main(){
	cin >> n >> q;
	rep (i, 1, n) {
		cin >> a[i];
        change(root[i], root[i - 1], 1, V, a[i], query(root[i - 1], 1, V, 1, a[i] - 1) + 1);
    }
	while (q --> 0) {
		int r, x;
		cin >> r >> x;
        cout << query(root[r], 1, V, 1, x) << endl;
    }
    return 0;
}
