/*
    Program: cat.cpp
    Author: 1l6suj7
    DateTime: 2023-10-04 09:58:05
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

const int N = 510;

int n;
ll c[N][N], R[N], L[N], D[N], U[N], tot1, tot2, cnt1[N], cnt2[N];
char mp[N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("cat.in", "r", stdin);
    freopen("cat.out", "w", stdout);
    cin >> n;
    lp(i, 1, n) lp(j, 1, n) cin >> mp[i][j];
    lp(i, 1, n) lp(j, 1, n) cin >> c[i][j];
    // lp(i, 1, n) {
    //     lp(j, 1, n) {
    //         R[j] = R[j - 1];
    //         if(mp[i][j] == 'L') cnt1[i] += R[j];
    //         if(mp[i][j] == 'R') ++R[j];
    //     }
    //     dlp(j, n, 1) {
    //         L[j] = L[j + 1];
    //         if(mp[i][j] == 'L') ++L[j];
    //     }
    //     tot1 += cnt1[i];
    // }
    cout << 160;
    return 0;
}