#include <bits/stdc++.h>
#define modelo(x) (((x) % mod + mod) % mod)
using namespace std;

const int mod = 998244353;
int n, m;
int a[100005];
long long dp[505][505][505]; //dp[i][j]=sum[i-a[i]][j]+...+sum[i-1][j]
long long ans;

int main() {
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d", a + i);
    for (int i = 1; i <= m; i++) dp[1][i][1] = 1;
    for (int i = 2; i <= n; i++) {
        long long sum = 0;
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= min(a[j], i); k++) sum = modelo(sum + dp[i - 1][j][k]);
        for (int j = 1; j <= m; j++) {
            long long sum1 = 0;
            for (int k = 1; k <= min(a[j], i); k++) sum1 = modelo(sum1 + dp[i - 1][j][k]);
            dp[i][j][1] = modelo(sum - sum1);
            for (int k = 2; k <= min(a[j], i); k++) dp[i][j][k] = dp[i - 1][j][k - 1];
        }
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= min(n, a[i]); j++)
            ans = modelo(ans + dp[n][i][j]);
    printf("%lld", ans);
    return 0;
}
