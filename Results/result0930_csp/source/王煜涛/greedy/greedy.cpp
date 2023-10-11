/*
    Program: greedy.cpp
    Author: 1l6suj7
    DateTime: 2023-09-30 09:33:09
    Description: 
*/

#include <bits/stdc++.h>
#define ll long long
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

const ll MOD = 147744151, N = 10010;

ll n, k, f[N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("greedy.in", "r", stdin);
    freopen("greedy.out", "w", stdout);
    cin >> n >> k;
    if(k == 1) cout << (n - 1) % MOD;
    else if(k == 2) {
        ll l = 1, r = 1000000000l;
        while(l < r) {
            ll mid = l + r >> 1;
            if(4 + (3 + mid) * (mid - 2) / 2l < n) l = mid + 1;
            else r = mid;
        }
        cout << l % MOD;
    }
    else if(ceil(log2((double)n)) <= k) cout << ceil(log2((double)n));
    else {
        f[1][1] = 1, f[1][2] = 4;
        lp(i, 3, n) f[1][i] = f[1][i - 1] + i;
        lp(i, 2, k) {
            f[i][i] = (1 << i);
            lp(j, k + 1, n) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
                if(f[i][j] > n) break;
            }
        }
        lp(i, k + 1, n) if(f[k][i] >= n) { cout << i; return 0; }
    }
    return 0;
}