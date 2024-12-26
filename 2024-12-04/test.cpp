#include <bits/stdc++.h>
#include "graph.h"
#define endl '\n'
#define si inline
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef __int128 li;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef const int ci;
typedef const ll cl;
ci iinf = 1e9;
cl linf = LLONG_MAX;
template<typename T>si bool gmax(T &x, const T y) {
    if (x < y)
        return x = y, 1;

    return 0;
}
template<typename T>si bool gmin(T &x, const T y) {
    if (y < x)
        return x = y, 1;

    return 0;
}

ci N = 205;

int d[N];
int e[N][N], fid[N];
int p[N][N];
vector<pii> g[N];

int cnt;

void dfs(int x, int fa) {
    d[x] = NumberOfRoads();
    int las = LastRoad();

    if (~las)
        e[x][fid[x] = las] = fa;

    for (int i = 1; i <= d[x]; i++) {
        if (i != las) {
            Move(i, 3);
            int k = Color();

            if (k == 1) {
                e[x][i] = ++cnt;
                g[x].emplace_back(cnt, i);
                dfs(cnt, x);
            } else {
                int id = LastRoad();

                if (k == 3)
                    p[x][i] = id;

                Move(id, k);
            }
        }
    }

    if (fid[x] != 0)
        Move(fid[x], 2);
}

int f[N][N];
int ans[N];

int cur;
void work(int x) {
    int c = (x % (cur * 3)) / cur + 1;

    for (int i = 1; i <= d[x]; i++) {
        if (p[x][i] != 0) {
            Move(i, 1);
            int k = Color();
            e[x][i] += cur * (k - 1);
            Move(LastRoad(), k);
        }
    }

    for (pii i : g[x])
        Move(i.se, c), work(i.fi);

    if (fid[x] != 0)
        Move(fid[x], c);
}

void Inspect(int R) {
    cnt = 1, dfs(1, 0);

    cur = 1;

    for (int i = 1; i <= 5; i++, cur *= 3)
        work(1);

	cerr << "de:" << endl;

	for (int i = 1; i <= cnt; i++) {
		cerr << i << ":";
		for (int j = 1; j <= d[i]; j++) {
			cerr << e[i][j] << " ";
		}
		cerr << endl;
	}

    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j <= d[i]; j++)
            if (p[i][j] != 0)
                e[e[i][j]][p[i][j]] = i;

    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j <= cnt; j++)
            f[i][j] = (i != j) * iinf;

    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j <= d[i]; j++)
            f[i][e[i][j]] = 1;

    for (int k = 1; k <= cnt; k++)
        for (int i = 1; i <= cnt; i++)
            for (int j = 1; j <= cnt; j++)
                gmin(f[i][j], f[i][k] + f[k][j]);

    for (int i = 1; i <= cnt; i++)
        for (int j = i + 1; j <= cnt; j++)
            if (f[i][j] <= cnt)
                ans[f[i][j]]++;

    for (int i = 1; i <= R; i++)
        Answer(i, ans[i]);
}
