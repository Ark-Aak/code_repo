/*
    Program: reinforce.cpp
    Author: 1l6suj7
    DateTime: 2023-10-05 10:18:47
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

const int N = 1000010, M = 27;

struct edge {
    int v, nxt;
}e[N];

string s;
int tot, ans;
int head[M], en;
bool vis[M];

void add(int u, int v) { e[++en] = {v, head[u]}, head[u] = en; }

bool vis2[M];
bool judge(int s, int t) {
    mst(vis2, 0);
    queue<int> q;
    q.push(s), vis2[s] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if(v == t) return true;
            if(vis2[v]) continue;
            vis2[v] = 1, q.push(v);
        }
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("reinforce.in", "r", stdin);
    freopen("reinforce.out", "w", stdout);
    cin >> s;
    if(s.size() == 0) return cout << 0, 0;
    vis[s[0] - 'a' + 1] = 1, ans = 1;
    for(int i = 1; i < s.size(); ++i) {
        int s1 = s[i - 1] - 'a' + 1, s2 = s[i] - 'a' + 1;
        if(!vis[s2]) { add(s1, s2), vis[s2] = 1; continue; }
        if(s1 == s2) { ++ans; continue; }
        int t1 = judge(s1, s2), t2 = judge(s2, s1);
        if(t2) ++ans;
        else if(!t1) add(s1, s2);
    }
    cout << ans;
    return 0;
}