#include <bits/stdc++.h>
using namespace std;

int n, k;
int dis[1005];
int mp[1005][1005];
vector<int> vec[1005];

int Dijkstra() {
    bool vis[1005];
    priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int, int> > > q;
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    q.push(make_pair(dis[1], 1));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 1; i <= n; i++)
            if (mp[u][i] && dis[i] > dis[u] + mp[u][i]) {
                dis[i] = dis[u] + mp[u][i];
                q.push(make_pair(dis[i], i));
            }
    }
    return dis[n] == 0x3f3f3f3f ? -1 : dis[n];
}

int main() {
    freopen("tower.in", "r", stdin);
    freopen("tower.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        vec[x].push_back(i);
    }
    for (int i = 1; i <= k; i++) {
        char ch[1005];
        scanf("%s", ch + 1);
        for (int j = 1; j <= k; j++)
            if  (ch[j] == 49) {
                for (int it: vec[i])
                    for (int it1: vec[j])
                        mp[it][it1] = abs(it - it1);
            }
    }
    printf("%d", Dijkstra());
    return 0;
}
