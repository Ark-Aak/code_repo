/*
    Program: flip.cpp
    Author: 1l6suj7
    DateTime: 2023-10-03 11:38:11
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

const ll N = 1010, MOD = 998244353;

ll n, k, f[N], ans;
ll mp[N];

void dfs(int rst) {
    if(rst == 0) ++ans;
    for(int i = 1; i <= n; ++i) {
        if(!mp[i]) continue;
        int j;
        for(j = i; j <= n; j += 2) {
            if(j > i && (mp[j - 1] || !mp[j])) break;
            mp[j] = 0;
            if(j > i) mp[j - 1] = 1;
            dfs(rst - 1);
        }
        for(int k = i; k < j; k += 2) {
            mp[k] = 1;
            if(k > i) mp[k - 1] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("flip.in", "r", stdin);
    freopen("flip.out", "w", stdout);
    cin >> n >> k;
    if(n != k) {
        n = n * 2 - 1;
        for(int i = 1; i <= n; i += 2) mp[i] = 1;
        dfs(k);
        cout << ans;
    }else {
        ans = 1;
        for(ll i = 3; i <= 2 * n - 1; i += 2) {
            ans = ans * i % MOD;
        }
        cout << ans % MOD;
    }
    
    return 0;
}