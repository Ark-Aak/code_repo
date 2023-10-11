/*
    Program: elevator.cpp
    Author: 1l6suj7
    DateTime: 2023-10-10 08:01:56
    Description: 
*/

#include <bits/stdc++.h>
#define int __int128
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

const int N = 2000010;

int n, K, trs[N], tot, m, a[N], b[N], s[N], f[N], d[N];

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

int getdx(int x1, int x2) { return (s[x2] - s[x1]); }

int getdy(int x1, int x2) { return (f[x2] + (int)2 * s[x2] - f[x1] - (int)2 * s[x1]); }

int q[N], l = 1, r;
void solve() {
    q[++r] = 0;
    lp(i, 1, m) {
        while(l < r && (s[i] - s[q[l]] > K || getdy(q[l], q[l + 1]) <= ((int)2 * d[i]) * getdx(q[l], q[l + 1]))) ++l;
        int j = q[l]; f[i] = f[j] + (int)2 * (d[i] - (int)1) * (s[m] - s[j]);
        while(l < r && getdy(q[r - 1], q[r]) * getdx(q[r], i) >= getdy(q[r], i) * getdx(q[r - 1], q[r])) --r;
        q[++r] = i;
    }
}

void write(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    n = read(), K = read();
    lp(i, 1, n) trs[++tot] = read(), ++b[trs[tot]];
    sort(trs + 1, trs + 1 + tot);
    tot = unique(trs + 1, trs + 1 + tot) - trs - 1;
    lp(i, 1, tot) while(b[trs[i]]) a[++m] = 1, d[m] = trs[i], --b[trs[i]];
    lp(i, 1, m) s[i] = s[i - 1] + a[i];
    if(m <= 1000) {
        mst(f, 0x3f), f[0] = 0;
        lp(i, 1, m) lp(j, 0, i - 1) if(s[i] - s[j] <= K) f[i] = min(f[i], f[j] + 2ll * (d[i] - 1ll) * (s[m] - s[j]));
    }else solve();
    write(f[m]);
    return 0;
}
/*
f[i] = min{ f[j] + 2 * (s[i] - s[j]) * (i - 1) + 2 * (s[m] - s[i]) * (i - 1) }
f[i] = min{ f[j] + 2 * (i - 1) * (s[m] - s[j]) }
f[i] = f[j] + 2 * (i - 1) * s[m] - 2 * i * s[j] + 2 * s[j]
f[j] + 2 * s[j] = 2 * i * s[j] - 2 * (i - 1) * s[m] + f[i]

t = ((s[i] - s[j]) / K + 1) * 2
s[i] = s[i - 1] + a[i]
r[i] = r[i - 1] + i * a[i]
1 <= j <= i - 1
j + 1 <= k <= i
s[i] - s[j] <= K
*/
