#include <bits/stdc++.h>
#ifdef dbg
#define D(...) fprintf(stderr, __VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ " = "), debug_helper::debug(__VA_ARGS__), D("\n")
#include "C:\Users\wsyear\Desktop\OI\templates\debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

const int N = 1010;
const int M = 1000010;

struct node {
  int l, r, s, t;
} que[M];

int n, m, q, dis[N][N], ans[M];
pii ed[M];
vector<int> vec[M];

int main() {
  freopen("journey.in", "r", stdin);
  freopen("journey.out", "w", stdout);
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  cin >> n >> m >> q;
  rep (i, 1, m) cin >> ed[i].fi >> ed[i].se;
  rep (i, 1, q) cin >> que[i].l >> que[i].r >> que[i].s >> que[i].t;
  rep (i, 1, q) ans[i] |= (que[i].s == que[i].t);
  rep (i, 1, q) vec[que[i].l].emplace_back(i);
  rep (i, 1, n) rep (j, 1, n) dis[i][j] = m + 1;
  per (i, m, 1) {
    int u = ed[i].fi, v = ed[i].se;
    dis[u][v] = dis[v][u] = i;
    rep (w, 1, n) dis[u][w] = dis[v][w] = min(dis[u][w], dis[v][w]);
    for (int x : vec[i]) ans[x] |= (dis[que[x].s][que[x].t] <= que[x].r);
  }
  rep (i, 1, q) cout << (ans[i] ? "Yes" : "No") << '\n';
}
