# include <bits/stdc++.h>

using namespace std;

namespace kh {
  ifstream cin("badge.in");
  ofstream cout("badge.out");
  constexpr int N(500'005);
  constexpr int Q(500'005);
  int n, q, l[N], r[N], b;
  vector<int> p[N];
  vector<int> x[Q];
  vector<int> o[Q];
  int s[2][N];
  long ans[Q];
  void main() {
    cin >> n >> q, b = sqrt(n + 0.5);
    for (int i(1); i <= n; ++i) {
      cin >> l[i] >> r[i];
      p[r[i]].push_back(l[i]);
    }
    for (int i(1); i <= q; ++i) {
      int m((cin >> m, m));
      x[i].resize(m);
      for (int& x : x[i]) cin >> x;
      sort(x[i].begin(), x[i].end());
      vector<int> t;
      for (int j(0); j != m; ++j)
        if (!j || x[i][j] != x[i][j - 1]) t.push_back(x[i][j]);
        else t.pop_back(), x[i][j - 1] = x[i][j] = 0;
      x[i].swap(t);
      x[i].insert(x[i].begin(), 0);
      x[i].push_back(n + 1);
      m = x[i].size() - 1;
      if (1l * m * m <= n)
        for (int j(1); j <= m; ++j)
          o[x[i][j]].push_back(i);
      else {
        static int s[N];
        for (int j(1); j != m; ++j) s[x[i][j]] ^= 1;
        for (int j(1); j <= n; ++j) s[j] ^= s[j - 1];
        for (int j(1); j <= n; ++j) ans[i] += s[r[j]] ^ s[l[j] - 1];
        memset(s, 0, sizeof(int) * (n + 1));
      }
    }
    for (int i(1); i <= n + 1; ++i) {
      for (auto const j : o[i]) {
        int m(x[j].size() - 1), o(0);
        while (x[j][o] != i) ++o;
        for (int k(0); k != o; ++k) {
          int rat(0);
          rat += (o - k) % 2 == 0 && 0 <= k && o <= m;
          rat -= (o - k) % 2 == 1 && 0 != k && o <= m;
          rat -= (o - k) % 2 == 1 && 0 <= k && o != m;
          rat += (o - k) % 2 == 0 && 0 != k && o != m;
          ans[j] += rat * (s[0][x[j][k]] + s[1][x[j][k] / b]);
        }
      }
      for (auto const x : p[i]) {
        for (int i(1); i <= x % b; ++i) ++s[0][x - i];
        for (int i(x / b - 1); i >= 0; --i) ++s[1][i];
      }
    }
    for (int i(1); i <= q; ++i) cout << ans[i] << '\n';
    fill(p + 1, p + n + 1, vector<int>());
    fill(x + 1, x + q + 1, vector<int>());
    fill(o + 1, o + n + 2, vector<int>());
    memset(s[0], 0, sizeof(int) * (n + 1));
    memset(s[1], 0, sizeof(int) * (n + 1));
    memset(ans + 1, 0, sizeof(long) * q);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  kh::cin.tie(nullptr), kh::main();
}
