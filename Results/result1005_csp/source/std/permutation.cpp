#include <bits/stdc++.h>

#define eb emplace_back
#define ep emplace
#define fi first
#define se second
#define in read<int>()
#define lin read<ll>()
#define rep(i, x, y) for(int i = (x); i <= (y); i++)
#define per(i, x, y) for(int i = (x); i >= (y); i--)

using namespace std;

using ll = long long;
using db = double;
using pii = pair < int, int >;
using vec = vector < int >;
using veg = vector < pii >;

template < typename T > T read() {
	T x = 0; bool f = 0; char ch = getchar();
	while(!isdigit(ch)) f |= ch == '-', ch = getchar();
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

template < typename T > void chkmax(T &x, const T &y) { x = x > y ? x : y; }
template < typename T > void chkmin(T &x, const T &y) { x = x < y ? x : y; }

const int N = 1e5 + 10;

int n, K;

struct perm {
	int a[N];
	perm() { rep(i, 1, n) a[i] = i; }
	int &operator [] (int x) { return a[x]; }
	const int &operator [] (int x) const { return a[x]; }
	friend perm operator * (perm a, perm b) { perm c; rep(i, 1, n) c[i] = b[a[i]]; return c; }
	perm inv() { perm c; rep(i, 1, n) c[a[i]] = i; return c; }
} ans, A, p, q, pinv, qinv, Ainv;

template < typename T > T qp(T x, int t) { T ret; for(; t; t >>= 1, x = x * x) if(t & 1) ret = ret * x; return ret; }

int main() {
    freopen("permutation.in", "r", stdin), freopen("permutation.out", "w", stdout);
	n = in, K = in;
	rep(i, 1, n) p[i] = in; rep(i, 1, n) q[i] = in;
	pinv = p.inv(), qinv = q.inv(), A = p * qinv * pinv * q, Ainv = A.inv();
	if(K % 6 == 0) ans = p;
	else if(K % 6 == 1) ans = q;
	else if(K % 6 == 2) ans = pinv * q;
	else if(K % 6 == 3) ans = qinv * pinv * q;
	else if(K % 6 == 4) ans = qinv * A;
	else ans = qinv * p * A;
	ans = qp(Ainv, K / 6) * ans * qp(A, K / 6);
	rep(i, 1, n) printf("%d ", ans[i]); puts("");
	return 0;
}