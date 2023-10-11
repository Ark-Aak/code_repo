/*
    Program: chessboard.cpp
    Author: 1l6suj7
    DateTime: 2023-10-04 09:31:02
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

const int N = 4010;

int n, m, mp[N][N];

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

bool judge(int x, int y) {
    if(x == n || y == m || x < 1 || y < 1) return true;
    if(mp[x][y] == 0 && mp[x][y + 1] == 1 && mp[x + 1][y] == 1 && mp[x + 1][y + 1] == 0 ||
        mp[x][y] == 1 && mp[x][y + 1] == 0 && mp[x + 1][y] == 0 && mp[x + 1][y + 1] == 1) return false;
    return true;
}

bool solve() {
    lp(i, 1, n) {
        lp(j, 1, n) {
            if(mp[i][j] != 2) {
                if(!judge(i, j)) return false;
            }else {
                int t1 = 0, t2 = 0;
                mp[i][j] = 0;
                if(judge(i - 1, j - 1) && judge(i - 1, j) && judge(i, j - 1) && judge(i, j)) t1 = 1;
                mp[i][j] = 1;
                if(judge(i - 1, j - 1) && judge(i - 1, j) && judge(i, j - 1) && judge(i, j)) t2 = 1;
                if(!t1 && !t2) return false;
                if(t1) mp[i][j] = 0;
                else mp[i][j] = 1;
            }
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("chessboard.in", "r", stdin);
    freopen("chessboard.out", "w", stdout);
    n = read(), m = read(); char c;
    lp(i, 1, n) lp(j, 1, m) {
        c = getchar();
        while(c != '0' && c != '1' && c != '?') c = getchar();
        if(c == '1') mp[i][j] = 1;
        else if(c == '?') mp[i][j] = 2;
    }
    if(!solve()) return printf("No"), 0;
    printf("Yes\n");
    lp(i, 1, n) {
        lp(j, 1, m) printf("%d", mp[i][j]);
        putchar('\n');
    }
    return 0;
}