#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n, m, tot;
long long now;
long long f[2010][2010];
int vis[100005];
inline long long g(int i, int y) {
	long long res = 0;
	for(int l = 2, r; l <= y; l = r + 1) {
		if(y / l == 0) break;
		r = y / (y / l);
		res = (res + (long long) f[i - 1][vis[y / l]] * (r - l + 1)) % mod;
	}
	return res;
}
signed main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    scanf("%d %d", &n, &m);
    long long sum = m;
	for(int i = 1; i <= m; i++) {
		f[1][i] = 1;
		if(vis[m / i]) continue;
		vis[m / i] = ++tot;
	}
	for(int i = 2; i <= n; i++) {
		now = 0;
		for(int l = 1, r; l <= m; l = r + 1) {
			if(m / l == 0) break;
			r = m / (m / l);
			int d = vis[m / l], o = m / l;
			f[i][d] = sum;
			f[i][d] = (f[i][d] - g(i, o) + mod) % mod;
			now = (now + (long long)(r - l + 1) * f[i][d] % mod) % mod;
		}
		sum = now;
	}
	printf("%lld", sum);
	return 0;
}

