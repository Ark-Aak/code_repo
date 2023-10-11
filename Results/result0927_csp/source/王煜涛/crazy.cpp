/*
    Program: crazy.cpp
    Author: 1l6suj7
    DateTime: 2023-09-27 11:12:02
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

using namespace std;

const int N = 10010, M = 100000;

int K, a[N], s[N], prm[M + 10], tot, ans;
bool isp[M + 10];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crazy.in", "r", stdin);
    freopen("crazy.out", "w", stdout);
    cin >> K;
    lp(i, 1, K) cin >> a[i];
    lp(i, 2, M) {
        if(!isp[i]) prm[++tot] = i;
        lp(j, 1, tot) {
            if(i * prm[j] > M) break;
            isp[i * prm[j]] = 1;
            if(i % prm[j] == 0) break;
        }
    }
    sort(a + 1, a + 1 + K);
    int cnt = 0;
    a[0] = -2;
    lp(i, 1, K) {
        if(a[i] != a[i - 1] + 1) ++cnt;
        ++s[cnt];
    }
    isp[1] = isp[2] = 1;
    lp(i, 1, cnt) {
        if(!isp[s[i]]) { ++ans; continue; }
        bool f = 0;
        lp(j, 1, s[i] - 1) {
            if(!isp[j] && !isp[s[i] - j]) { ans += 2, f = 1; break; }
        }
        if(f) continue;
        lp(j, 1, s[i] - 2) {
            lp(l, j + 1, s[i] - 1) {
                if(!isp[j] && !isp[l - j] && !isp[s[i] - l]) { ans += 3, f = 1; break; };
            }
            if(f) break;
        }
    }
    cout << ans;
    return 0;
}