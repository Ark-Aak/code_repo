#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n, m;
int fact[2005][505];
long long dp[2][2005];
long long ans, sum;

int main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) dp[n & 1][i] = 1;
    sum = m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j < i; j++)
            if (i % j == 0) fact[i][++fact[i][0]] = j;
    for (int i = n - 1; i; i--) {
        int p = i & 1;
        fill(dp[p] + 1, dp[p] + m + 1, sum);
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= fact[j][0]; k++) dp[p][j] -= dp[p ^ 1][fact[j][k]];
        for (int j = 1; j <= m; j++) dp[p][j] = (dp[p][j] % mod + mod) % mod;
        sum = 0;
        for (int j = 1; j <= m; j++) sum += dp[p][j];
        sum %= mod;
    }
    for (int i = 1; i <= m; i++) ans = (ans + dp[1][i]) % mod;
    printf("%lld", ans);
    return 0;
}
