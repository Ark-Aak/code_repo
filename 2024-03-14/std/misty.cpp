#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
using u128 = __uint128_t;
struct FastMod {
    u64 p;
    u128 m;
    FastMod(u64 P = 2) : p(P), m((u128(1) << 64) / p) {}
    inline int reduce(u64 x) {
        u64 y = (x * m) >> 64;
        u64 r = x - y * p;
        return r >= p ? (r - p) : r;
    }
} F;
int n, k, K , P, C[1005][1005], dp[1005][12][3], sum[1005][12][3];
inline void add(int &x, int y) { 
    (x += y) >= P && (x -= P); 
}
inline int Add(int x, int y) { 
    return add(x, y), x; 
}
inline void mul(int &x, int y) {
    x = F.reduce(1ull * x * y);
}
inline int Mul(int x, int y) {
    return F.reduce(1ull * x * y);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("misty.in", "r", stdin);
    freopen("misty.out", "w", stdout);
    cin >> n >> k >> P; 
    F = FastMod(P);
    if (k > 10) {
        cout << "0\n";
        return 0;
    }
    K = k ; k = 11;
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
        }
    }
    dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 1;
    for (int p = 1; p <= n; ++p) {
        for (int x = 0; x <= k + 1; ++x) {
            for (int t = 0; t < 3; ++t) {
                sum[p - 1][x][t] = Add(x == 0 ? 0 : sum[p - 1][x - 1][t], dp[p - 1][x][t]);
            }
        }
        for (int i = 0; i < p; ++i) {
            int j = p - 1 - i;
            int coef = C[i + j][j];
            for (int x = 1; x <= k + 1; ++x) {
                {
                    int val = Add(Mul(dp[i][x - 1][1], sum[j][x - 1][1]), Mul((x == 1) ? 0 : sum[i][x - 2][1], dp[j][x - 1][1]));
                    add(dp[p][x][0], Mul(val, coef));
                }
                {
                    int val = Add(Mul(dp[i][x - 1][2], sum[j][x][1]), Mul((x == 1) ? 0 : sum[i][x - 2][2], dp[j][x][1]));
                    add(dp[p][x][1], Mul(val, coef));
                }
                {
                    int val = Add(Mul(dp[i][x][2], sum[j][x - 1][2]), Mul(sum[i][x - 1][2], dp[j][x][2]));
                    add(val, Mul(dp[i][x - 1][2], dp[j][x - 1][2]));
                    add(dp[p][x][2], Mul(val, coef));
                }
            }
        }
    }
    int ans = 0;
    for(int i = K + 1 ; i < 12 ; ++i)
        add(ans , dp[n][i][0]);
    cout << ans << "\n";
    return 0;
}