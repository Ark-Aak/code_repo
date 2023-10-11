//#pragma GCC optimize(2)
#include<bits/stdc++.h>
//#include<cmath>
#define Sig signed
#define uSig unsigned
typedef long long ll;
#define int ll
//#define double long double
#define Fix fixed
#define Spcs(x) setprecision(x)
#define Il inline
#define pii pair<int,int>
#define re register
#define Mul multiset
#define Vt vector
#define Stk stack
#define Que queue
#define Itt iterator
#define PQ priority_queue
#define umap unordered_map
#define uset unordered_set
#define mpr make_pair
#define ft first
#define sd second
#define pb push_back
#define Bset bitset
#define Ins insert
#define Ers erase
#define Clr clear
#define lowbit(x) x&(-x)
#define Mset(x,y) memset(x,y,sizeof x)
#define Mcpy(x,y) memcpy(x,y,sizeof y)
#define Unq unique
#define rp(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define lp(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define rpt(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define lpt(i,a,b) for(int (i)=(a);(i)>(b);(i)--)
using namespace std;
//--------------------------------------------------------------------
const int N = 2e5 + 10;
//--------------------------------------------------------------------
Il int read() {
	int p = 0, q = 1;
	char ch = getchar();
	while (!isdigit(ch)) q = (ch == '-') ? -1 : 1, ch = getchar();
	while (isdigit(ch)) p = (p << 3) + (p << 1) + (ch ^ 48), ch = getchar();
	return p * q;
}
//--------------------------------------------------------------------
int n, m;
int x[N], y[N];
struct edge {
	int line, val;
};
Vt<edge> G[N];
int A[N];
//--------------------------------------------------------------------
Il void dfs(int u, int val, int now) {
	for (auto d : G[u]) {
		if (d.val > val) {
			dfs(d.line, d.val, now + 1);
			x[u] = max(y[d.line] + 1, x[u]);
			y[u] = min(x[d.line] + 1, y[u]);
			if (!x[u]) x[u] = y[d.line] + 1;
			if (!y[u]) y[u] = x[d.line] + 1;
		}
		A[u] = max(A[u], x[u]);
	}
}
Sig main(void) {
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	n = read(), m = read();
	rp(i, 1, m) {
		int u = read(), v = read(), w = read();
		G[u].pb({v, w});
		G[v].pb({u, w});
	}
	rp(i, 1, n) G[0].pb({i, 0});

	dfs(1, INT_MIN, 1);
	rp(i, 1, n) printf("%lld ", A[i]);
	return 0;
}
