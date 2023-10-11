#include<bits/stdc++.h>
#define N 5010
#define int long long
using namespace std;
int n, q;
int x[N], y[N], sum[N][N];
int find(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
signed main() {
    freopen("ds.in", "r", stdin);
    freopen("ds.out", "w", stdout);
    scanf("%lld %lld", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%lld", &x[i]);
    for(int i = 1; i <= n; i++) scanf("%lld", &y[i]);
    for(int i = 1; i <= n; i++) sum[x[i]][y[i]]++;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    while(q--) {
    	int U, R, D, L, ans = 0;
    	scanf("%lld %lld %lld %lld", &U, &R, &D, &L);
    	for(int i = 1; i <= n; i++) {
    		if(D <= x[i] && x[i] <= U && L <= y[i] && y[i] <= R && find(x[i] + 1, y[i] + 1, U, R) == 0)
			    ans++; 
		}
		printf("%lld\n", ans);
    }
	return 0;
}

