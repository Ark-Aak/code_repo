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

const int N = 110;
const int mod = 1e9 + 7;

int n, K;
int f[N][N * N], g[N][N * N];

void upd(int &x) { x += x >> 31 & mod; }

int main() {
	freopen("stone.in", "r", stdin), freopen("stone.out", "w", stdout);
	n = in, K = in;
	f[n + 1][0] = 1, g[n + 1][0] = 0;
	per(i, n, 1)
		rep(j, 0, (n - i) * K) if(f[i + 1][j]) {
			rep(t, 0, K) {
				int ret = t + j, add = 0;
				if(t <= i) add = ret / i, ret = ret % i;
				upd(f[i][j + add] += f[i + 1][j] - mod);
				upd(g[i][j + add] += (g[i + 1][j] + 1ll * f[i + 1][j] * ret % mod) % mod - mod);
			}
		}
	int ans = 0;
	rep(i, 0, n * K) upd(ans += g[1][i] - mod);
	cout << ans << endl;
	return 0;
}
