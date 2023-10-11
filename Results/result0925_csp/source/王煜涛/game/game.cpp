/*
    Program: game.cpp
    Author: 1l6suj7
    DateTime: 2023-09-25 11:14:03
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

const int N = 100010;

int T, n, k, a[N], S[N];

bool judge() {
    lp(i, 1, n - k + 1) {
        int j = i + k - 1;
        if(S[i - 1] + S[n] - S[j - 1] == n - k || S[i - 1] + S[n] - S[j - 1] == 0) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> T;
    while(T--) {
        mst(S, 0);
        cin >> n >> k;
        char c;
        lp(i, 1, n) {
            cin >> c;
            if(c == '0') a[i] = 0;
            else a[i] = 1;
            S[i] = S[i - 1] + a[i];
        }
        if(judge()) cout << "win" << endl;
        else cout << "tie" << endl;
    }
    return 0;
}