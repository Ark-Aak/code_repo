// Author: wsyear
// Problem: G. XOR Segments
// Contest: Codeforces - Hunan University 2023 the 19th Programming Contest
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

template <int P>
class mod_int {
  using Z = mod_int;

private:
  static int mo(int x) { return x < 0 ? x + P : x; }

public:
  int x;
  int val() const { return x; }
  mod_int() : x(0) {}
  template <class T>
  mod_int(const T &x_) : x(x_ >= 0 && x_ < P ? static_cast<int>(x_) : mo(static_cast<int>(x_ % P))) {}
  bool operator==(const Z &rhs) const { return x == rhs.x; }
  bool operator!=(const Z &rhs) const { return x != rhs.x; }
  Z operator-() const { return Z(x ? P - x : 0); }
  Z pow(long long k) const {
    Z res = 1, t = *this;
    while (k) {
      if (k & 1) res *= t;
      if (k >>= 1) t *= t;
    }
    return res;
  }
  Z &operator++() {
    x < P - 1 ? ++x : x = 0;
    return *this;
  }
  Z &operator--() {
    x ? --x : x = P - 1;
    return *this;
  }
  Z operator++(int) {
    Z ret = x;
    x < P - 1 ? ++x : x = 0;
    return ret;
  }
  Z operator--(int) {
    Z ret = x;
    x ? --x : x = P - 1;
    return ret;
  }
  Z inv() const { return pow(P - 2); }
  Z &operator+=(const Z &rhs) {
    (x += rhs.x) >= P && (x -= P);
    return *this;
  }
  Z &operator-=(const Z &rhs) {
    (x -= rhs.x) < 0 && (x += P);
    return *this;
  }
  Z &operator*=(const Z &rhs) {
    x = 1ULL * x * rhs.x % P;
    return *this;
  }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
#define setO(T, o)                                 \
  friend T operator o(const Z &lhs, const Z &rhs) {\
    Z res = lhs;                                   \
    return res o## = rhs;                          \
  }
  setO(Z, +) setO(Z, -) setO(Z, *) setO(Z, /)
#undef setO
};
const int P = 998244353;
using Z = mod_int<P>;

const int N = 1000010;

int n, m, k, vis[N], dis[N];
vector<pii> e[N];

void dfs(int u) {
  vis[u] = 1;
  for (auto [v, w] : e[u]) {
    if (!vis[v]) dis[v] = dis[u] ^ w, dfs(v);
    else if (dis[v] != (dis[u] ^ w)) cout << "0\n", exit(0);
  }
}

int main() {
  freopen("travel.in", "r", stdin);
  freopen("travel.out", "w", stdout);
  cin.tie(nullptr) -> ios::sync_with_stdio(false);
  cin >> n >> k >> m;
  rep (i, 1, m) {
    int l, r, x;
    cin >> l >> r >> x;
    e[l - 1].emplace_back(r, x);
    e[r].emplace_back(l - 1, x);
  }
  Z ans = 1, e = Z(2).pow(k);
  rep (i, 0, n) if (!vis[i]) dfs(i), ans *= e;
  cout << (ans / e).val() << '\n';
}