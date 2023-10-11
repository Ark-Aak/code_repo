#include<bits/stdc++.h>
using namespace std;
#define For(i, j, k) for ( int i = (j) ; i <= (k) ; i++ )
constexpr int mod = 1000000007;
int n, m, ans, u, v, d[200009], cnt[2000009], a[2000009], l;
inline int f(int x, int y) { return 1ll * ( x ^ y ) * ( x | y ) % mod * ( x & y ) % mod; }
int main()
{
	freopen("gen.in", "r", stdin), freopen("gen.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m;
	For(i, 1, m) cin >> u >> v, d[u]++, d[v]++;
	For(i, 1, n) cnt[d[i]]++;
	For(i, 0, m) if ( cnt[i] ) a[++l] = i;
	For(i, 1, l) For(j, i, l) ans = ( ans + 1ll * cnt[a[i]] * cnt[a[j]] % mod * f(a[i], a[j]) ) % mod;
	return cout << ans << '\n', 0;
}