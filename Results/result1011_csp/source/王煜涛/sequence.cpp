/*
    Program: sequence.cpp
    Author: 1l6suj7
    DateTime: 2023-10-11 09:16:56
    Description: 
*/

#include <bits/stdc++.h>
#define int long long
#define lp(i, j, n) for(int i = j; i <= n; ++i)
#define dlp(i, n, j) for(int i = n; i >= j; --i)
#define lft(n) ((n) << 1)
#define rt(n) ((n) >> 1)
#define mst(n, v) memset(n, v, sizeof(n))
#define mcy(n, v) memcpy(n, v, sizeof(v))
#define INF 1e18
#define MAX4 0x3f3f3f3f
#define MAX8 0x3f3f3f3f3f3f3f3f
#define lc(x) (x << 1)
#define rc(x) ((x << 1) ^ 1)

using namespace std;

const int N = 2010, M = 100010, MOD = 998244353;

int n, m, f[2][M], g[2][M], sum[N], ans;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    cin >> n >> m;
    sum[0] = 1;
    lp(i, 1, n) {
        f[i & 1][1] = sum[i] = 1;
        lp(j, 2, m) f[i & 1][j] = (sum[i - 1] - g[(i & 1) ^ 1][j]) % MOD, sum[i] = (sum[i] + f[i & 1][j]) % MOD;
        lp(j, 2, m) {
            g[i & 1][j] = 0;
            lp(k, 2, m) {
                if(j * k > m) break;
                g[i & 1][j] = (g[i & 1][j] + f[i & 1][j * k]) % MOD;
            }
        }
    }
    lp(i, 1, m) ans = (ans + f[n & 1][i]) % MOD;
    cout << (ans % MOD + MOD) % MOD;
    return 0;
}
/*
f[i][j] = sum { f[i - 1][j * k + l] }
1 <= l <= k - 1

3:  1 2
4:  1 1 2
5:  1 1 3
6:  1 1 1 3
7:  1 1 1 4
8:  1 1 1 4
9:  1 1 1 1 5
10: 1 1 1 1 1 5
11: 1 1 1 1 1 6
*/