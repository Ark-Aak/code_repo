#include <stdio.h>
const int N = 5001, M = 998244353;
int s[N][N], sum[N], g[N];
int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	register int n, m, i, j, f;
	scanf("%d%d", &n, &m);
	while(m--) scanf("%d", &i), ++g[i];
	for(i = 1; i <= n; ++i) {
		for(j = 1; j < i; ++j) if(g[j]) {
			s[i][j] = ((sum[i-1] - sum[i-j-1] + s[i-j-1][j]) % M + M) % M;
		}
		for(; j <= n; ++j) if(g[j]) {
			s[i][j] = (sum[i-1] + 1) % M;
		}
		for(j = 1; j <= n; ++j) sum[i] = (sum[i] + (long long)g[j] * s[i][j]) % M;
	}
	printf("%d\n", (sum[n] - sum[n-1] + M) % M);
	return 0;
}
