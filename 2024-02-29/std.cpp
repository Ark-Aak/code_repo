
// ubsan: undefined
// accoders
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn = 500010, Maxm = 2010, mod = 1e9 + 7;
map<int, int> e[Maxn];
int n, m, a[Maxm][Maxm], f[Maxn], g[Maxn], du[Maxn], pl[Maxm][Maxm], id[Maxm][Maxm], tot;
int to_x[8] = { 1, 0, -1, 0, -1, 1, 1, -1 };
int to_y[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int s = 0, t;
int find(int x) {
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
void dfs(int x, int y) {
    id[x][y] = tot;
    for (int i = 0; i < 8; i++) {
        int nx = x + to_x[i], ny = y + to_y[i];
        if (nx <= n && ny <= m && nx && ny && a[nx][ny] && !id[nx][ny])
            dfs(nx, ny);
    }
}
void bfs(int x, int y, int s) {
    pl[x][y] += s;
    if (s == 1) {
        for (int i = 0; i < 2; i++) {
            int nx = x + to_x[i], ny = y + to_y[i];
            if (nx <= n && ny <= m && nx && ny && pl[nx][ny] < s && !a[nx][ny])
                bfs(nx, ny, s);
        }
    } else {
        for (int i = 2; i < 4; i++) {
            int nx = x + to_x[i], ny = y + to_y[i];
            if (nx <= n && ny <= m && nx && ny && pl[nx][ny] < s && !a[nx][ny])
                bfs(nx, ny, s);
        }
    }
}
int ksm(int x, int y) {
    int s = 1;
    while (y) {
        if (y & 1)
            s = s * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return s;
}
void topf() {
    queue<int> Q;
    Q.push(s);
    for (int i = 0; i <= tot; i++) {
        for (auto j : e[i]) du[j.first]++;
    }
    g[s] = 1;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (auto i : e[x]) {
            du[i.first]--;
            g[i.first] = (g[i.first] + g[x]) % mod;
            if (!du[i.first])
                Q.push(i.first);
        }
    }
}
void Cleann() {
    for (int i = 1; i <= tot; i++) e[i].clear();
    tot = 0;
    memset(du, 0, sizeof du);
    memset(g, 0, sizeof g);
    memset(id, 0, sizeof id);
    memset(pl, 0, sizeof pl);
}
signed main() {
    /* freopen("b.in", "r", stdin); */
    /* freopen("b.out", "w", stdout); */
    int T;
    cin >> T;
    while (T--) {
        Cleann();
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c;
                cin >> c;
                if (c == '-')
                    a[i][j] = 0;
                else
                    a[i][j] = 1;
            }
        }
        bfs(1, 1, 1);
        bfs(n, m, 2);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!a[i][j] && pl[i][j] < 3)
                    a[i][j] = 1, cnt++;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!a[i][j])
                    id[i][j] = ++tot;
                else if (!id[i][j]) {
                    ++tot;
                    dfs(i, j);
                }
            }
        }
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << pl[i][j] << " ";
			}
			cout << endl;
		}
        s = ++tot, t = ++tot;
        for (int i = 1; i <= m; i++) e[s][id[1][i]]++;
        for (int i = 2; i <= n; i++) e[s][id[i][m]]++;
        for (int i = 1; i <= m; i++) e[id[n][i]][t]++;
        for (int i = 1; i < n; i++) e[id[i][1]][t]++;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j]) {
                    if (i != n && j != m && !a[i + 1][j])
                        e[id[i][j]][id[i + 1][j]]++;
                    if (i != 1 && j != 1 && !a[i][j - 1])
                        e[id[i][j]][id[i][j - 1]]++;
                    if (i != n && j != 1 && !a[i + 1][j - 1])
                        e[id[i][j]][id[i + 1][j - 1]]++;
                } else {
                    int fl = 0;
                    if (i != n && j != 1 && a[i + 1][j])
                        e[id[i][j]][id[i + 1][j]]++, fl = 1;
                    if (i != n && j != 1 && a[i][j - 1])
                        e[id[i][j]][id[i][j - 1]]++, fl = 1;
                    if (i != n && j != 1 && !fl)
                        e[id[i][j]][id[i + 1][j - 1]]++;
                }
            }
        }
        topf();
        cout << g[t] * ksm(2, cnt) % mod << '\n';
    }
    return 0;
}
