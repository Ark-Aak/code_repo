/*
    Program: graph.cpp
    Author: 1l6suj7
    DateTime: 2023-09-28 08:53:30
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

struct node {
    int a, b;
}nd[N];

int tot;
int n;

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

bool cmp(node t1, node t2) { return t1.b < t2.b; }

priority_queue<int, vector<int>, greater<int> > q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    n = read();
    lp(i, 1, n) nd[i].a = read(), nd[i].b = read();
    sort(nd + 1, nd + 1 + n, cmp);
    lp(i, 1, n) {
        if(q.empty()) { q.push(nd[i].a); continue; }
        int tp = q.top();
        while(!q.empty()) {
            int t = q.top();
            if(t > nd[i].a) break;
            q.pop();
        }
        if(tp <= nd[i].a) q.push(tp);
        else q.push(nd[i].a);
    }
    cout << q.size();
    return 0;
}