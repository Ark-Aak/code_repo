#include <bits/stdc++.h>
using namespace std;

int n, ans;
int a[15], b[15];

void dfs(int cur) {
    if (cur > n) {
        bool vis[15];
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++) vis[b[i]] = 1;
        for (int i = 0; i <= 10; i++)
            if (!vis[i]) {
                ans += i;
                break;
            }
        return;
    }
    for (int i = 0; i <= a[cur]; i++) {
        b[cur] = i;
        dfs(cur + 1);
    }
}

int main() {
    freopen("mex.in", "r", stdin);
    freopen("mex.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    dfs(1);
    printf("%d", ans);
    return 0;
}
