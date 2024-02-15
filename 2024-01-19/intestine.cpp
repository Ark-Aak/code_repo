#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,sse2,sse3,sse4")

#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll read() {
	ll x = 0, f = 1;
	char c = getchar();
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
	if (x < 0)
		x = (~x + 1), putchar('-');
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 505;
const int MOD = 998244353;

int n, cnt;
vector <int> p[MAXN];
int dfn[MAXN], b[MAXN], siz[MAXN], f[MAXN][MAXN][MAXN];
int B[MAXN][MAXN], w[MAXN], c[MAXN], P[MAXN], V[MAXN], tot; 
int fac[MAXN], DP[MAXN][MAXN];

void dp(int M, int No, int x) {
	for(int i = 0; i <= tot - 1; i++)
	for(int j = 0; j <= M; j++) DP[i][j] = B[i][j];
	for(int j = 1; j <= tot; j++)
	for(int k = w[No]; k <= siz[x]; k++) DP[j][k] = (DP[j][k] - DP[j - 1][k - w[No]] + MOD) % MOD;
	for(int j = 0; j <= M; j++) V[j] = 0;
	for(int i = 0; i <= tot - 1; i++)
	for(int j = 0; j <= M; j++) V[j] = (V[j] + 1ll * DP[i][j] * fac[i] % MOD * fac[tot - 1 - i] % MOD) % MOD; 
}

void dfs(int x) {
	siz[x] = 1;
	dfn[x] = ++cnt;
	b[dfn[x]] = x;
	P[x] = 1;
	for(auto y : p[x]) {
		dfs(y);
		siz[x] += siz[y];
		P[x] = 1ll * P[x] * P[y] % MOD;
	}
	P[x] = 1ll * P[x] * fac[p[x].size()] % MOD;
	f[x][x][1] = P[x];                                                                                                                                                                                                                                                                                              
	tot = 0;
	for(int j = 0; j < p[x].size(); j++) {
		tot++;
		w[tot] = siz[p[x][j]];
	}
	memset(B, 0, sizeof(B));
	B[0][0] = 1;
	for(int i = 1; i <= tot; i++)
	for(int j = i; j >= 1; j--)
	for(int k = siz[x]; k >= w[i]; k--)
		B[j][k] = (B[j][k] + B[j - 1][k - w[i]]) % MOD;
	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i], S = 1;
		for(int j = 0; j < p[x].size(); j++) {
			if(j == i) continue; 
			S = 1ll * S * P[p[x][j]] % MOD;
		}
		dp(siz[x], i + 1, x);
		for(int Z = dfn[y]; Z <= dfn[y] + siz[y] - 1; Z++) {
			int z = b[Z];
			for(int p = 1; p <= siz[y]; p++) {
				if(f[y][z][p] == 0) continue;
				int ttt = min(siz[x] - p - 1, siz[x] - 1 - siz[y]);
				for(int k = 0; k <= ttt; k++) {
					f[x][z][p + k + 1] = (f[x][z][p + k + 1] + 1ll * f[y][z][p] * V[k] % MOD * S % MOD) % MOD;
				}
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 2, fa; i <= n; i++) {
		cin >> fa;
		p[fa].push_back(i);
	}
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
	dfs(1);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) cout << f[1][i][j] << " ";
		cout << endl;
	}
	return 0;
}