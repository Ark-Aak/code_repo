/*
    Program: milky.cpp
    Author: 1l6suj7
    DateTime: 2023-09-28 08:04:26
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

const ll N = 1000010, MOD = (1ll << 32);

string s;
int n, L[N];
ll f[N][6][6];

int read() {
    int x = 0;
    char c;
    int f = 1;
    c = getchar();
    while((c < '0' || c > '9') && c != '-') c = getchar();
    if(c == '-') f = -f, c = getchar();
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}


ll solve(int l, int r, int ql, int qr) {
    ll res = f[r][ql][qr] - f[l - 1][ql][qr];
    //cout << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << res << endl;
    lp(i, ql, qr - 1) {
        res -= f[l - 1][ql][i] * solve(l, r, i + 1, qr) % MOD;
        //if(ql == 1 && qr == 5) cout << f[l - 1][ql][i] << ' ' << t << endl;
    }
    return (res % MOD + MOD) % MOD;
}

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("milky.in", "r", stdin);
    freopen("milky.out", "w", stdout);
    cin >> s, n = read();
    L['m'] = 1, L['i'] = 2, L['l'] = 3, L['k'] = 4, L['y'] = 5;
    f[0][1][0] = f[0][2][1] = f[0][3][2] = f[0][4][3] = f[0][5][4] = 1;
    lp(i, 1, s.size()) {
        lp(j, 0, 5) lp(k, 0, 5) f[i][j][k] = f[i - 1][j][k] % MOD;
        lp(j, 1, 5) if(L[s[i - 1]] >= j) f[i][j][L[s[i - 1]]] += f[i - 1][j][L[s[i - 1]] - 1];
    }
    int l, r;
    lp(i, 1, n) {
        l = read(), r = read();
        printf("%lld", solve(l, r, 1, 5) % MOD);
    }
    return 0;
}
/*
f[L[s[j]]] += f[L[s[j] - 1]]
*/