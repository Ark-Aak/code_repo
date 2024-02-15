#include <bits/stdc++.h>
using namespace std;
#define debug(fmt, ...) \
  fprintf(stderr, "[%d] : " fmt "\n", __LINE__, ##__VA_ARGS__)
template <class _Tp>
inline _Tp& read(_Tp& x) {
  bool sign = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) sign |= (ch == '-');
  for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
  return sign ? (x = -x) : x;
}
template <class _Tp>
inline void write(_Tp x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar((x % 10) ^ 48);
}
using ll = long long;
const int N = 2e5 + 10;
int n, m, a[N], mp[N], sz[N], mx[N], dep[N], ans[N];
bool vis[N];
vector<int> g[N], dp[N];
int get_root(int u, int f, int num) {
  int ret = 0; sz[u] = 1, mx[u] = 0;
  for (auto v : g[u]) {
    if (v == f || vis[v]) continue;
    int tmp = get_root(v, u, num);
    sz[u] += sz[v], mx[u] = max(mx[u], sz[v]);
    if (!ret || mx[tmp] < mx[ret]) ret = tmp;
  }
  mx[u] = max(mx[u], num - sz[u]);
  if (!ret || mx[u] < mx[ret]) ret = u;
  return ret;
}
int bound1(const vector<int>& vec, int k) {
  int l = 0, r = vec.size() - 1, res = vec.size();
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (vec[mid] <= k) {
      r = mid - 1, res = mid;
    } else {
      l = mid + 1;
    }
  }
  return res;
}
int bound2(const vector<int>& vec, int k) {
  int l = 0, r = vec.size() - 1, res = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (vec[mid] >= k) {
      l = mid + 1, res = mid;
    } else {
      r = mid - 1;
    }
  }
  return res;
}
void dfs1(int u, int f) {
  dp[u].clear();
  for (auto v : g[u]) {
    if (v == f || vis[v]) continue;
    dfs1(v, u);
    if (dp[u].size() < dp[v].size())
      swap(dp[u], dp[v]);
    for (int i = 0; i < (int)dp[v].size(); ++i)
      dp[u][i] = max(dp[u][i], dp[v][i]);
  }
  int p = bound1(dp[u], a[u]);
  if (p >= (int)dp[u].size()) {
    dp[u].push_back(a[u]);
  } else {
    dp[u][p] = max(dp[u][p], a[u]);
  }
}
int getans(const vector<int>& dp, int k) {
  return bound2(dp, k) + 1;
}
void dfs2(int u, int f, vector<int>& dp) {
  int p = bound1(dp, a[u]), cur = -1;
  if (p >= (int)dp.size()) {
    dp.push_back(a[u]), cur = -1;
  } else {
    cur = dp[p], dp[p] = max(dp[p], a[u]);
  }
  ans[u] = max(ans[u], getans(dp, a[u]));
  for (auto v : g[u])
    if (v != f && !vis[v]) dfs2(v, u, dp);
  if (cur == -1) {
    dp.pop_back();
  } else {
    dp[p] = cur;
  }
}
void solve(int rt, int num) {
  vis[rt] = 1;
  int tot = g[rt].size();
  dp[rt].clear(), dp[rt].push_back(a[rt]);
  for (int i = 0; i < tot; ++i) {
    int v = g[rt][i];
    if (vis[v]) continue;
    dfs2(v, rt, dp[rt]), dfs1(v, rt);
    if (dp[rt].size() < dp[v].size())
      swap(dp[rt], dp[v]);
    for (int j = 0; j < (int)dp[v].size(); ++j)
      dp[rt][j] = max(dp[rt][j], dp[v][j]);
    int p = bound1(dp[rt], a[rt]);
    if (p >= (int)dp[rt].size()) {
      dp[rt].push_back(a[rt]);
    } else {
      dp[rt][p] = max(dp[rt][p], a[rt]);
    }
  }
  dp[rt].clear(), dp[rt].push_back(a[rt]);
  for (int i = tot - 1; ~i; --i) {
    int v = g[rt][i];
    if (vis[v]) continue;
    dfs2(v, rt, dp[rt]), dfs1(v, rt);
    if (dp[rt].size() < dp[v].size())
      swap(dp[rt], dp[v]);
    for (int j = 0; j < (int)dp[v].size(); ++j)
      dp[rt][j] = max(dp[rt][j], dp[v][j]);
    int p = bound1(dp[rt], a[rt]);
    if (p >= (int)dp[rt].size()) {
      dp[rt].push_back(a[rt]);
    } else {
      dp[rt][p] = max(dp[rt][p], a[rt]);
    }
  }
  ans[rt] = max(ans[rt], getans(dp[rt], a[rt]));
  for (auto v : g[rt]) {
    if (vis[v]) continue;
    int nsz = sz[rt] > sz[v] ? sz[v] : num - sz[rt];
    solve(get_root(v, rt, nsz), nsz);
  }
}
int main() {
  freopen("lot.in", "r", stdin);
  freopen("lot.out", "w", stdout);
  read(n), m = 0;
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1, u, v; i < n; ++i)
    read(u), read(v), g[u].push_back(v), g[v].push_back(u);
  for (int i = 1; i <= n; ++i) mp[++m] = a[i];
  sort(mp + 1, mp + m + 1), m = unique(mp + 1, mp + m + 1) - mp - 1;
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(mp + 1, mp + m + 1, a[i]) - mp;
  fill(vis + 1, vis + n + 1, 0);
  fill(ans + 1, ans + n + 1, 0);
  solve(get_root(1, 0, n), n);
  for (int i = 1; i <= n; ++i)
    write(ans[i]), putchar('\n');
  return 0;
}