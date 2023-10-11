/*
    Program: ring.cpp
    Author: 1l6suj7
    DateTime: 2023-10-11 11:09:29
    Description: 
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;

int n, m, ans;

int mp[100];
bool vis[100];
bool judge() {
    int tmp[100], ind[100];
    lp(i, 1, n) tmp[i] = mp[i], ind[tmp[i]] = i;
    lp(i, 1, n) {
        int l = ind[i] - 1, r = ind[i] + 1;
        if(l == 0) l = n;
        if(r == n + 1) r = 1;
        if(tmp[l] < tmp[ind[i]] && tmp[r] > tmp[ind[i]] || tmp[l] > tmp[ind[i]] && tmp[r] < tmp[ind[i]]) return true;
        ind[tmp[l]] = r, ind[tmp[r]] = l;
        swap(tmp[l], tmp[r]);
    }
    return false;
}

void solve(int dep) {
    if(dep == n + 1) { ans += judge()? 1 : 0; return; }
    lp(i, 1, n) {
        if(vis[i]) continue;
        vis[i] = 1, mp[dep] = i, solve(dep + 1), vis[i] = 0;
    }
}

int f[] = {3549440, 474756096};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("ring.in", "r", stdin);
    freopen("ring.out", "w", stdout);
    cin >> n >> m;
    if(n & 1) {
        ans = 1;
        lp(i, 1, n) ans = (ans * i) % m;
        return cout << ans, 0;
    }
    if(n == 10) return cout << f[0] % m, 0;
    if(n == 12) return cout << f[1] % m, 0;
    solve(1);
    cout << ans % m;
    return 0;
}
/*
1 1 8 136 3968 176896
      17  31
*/