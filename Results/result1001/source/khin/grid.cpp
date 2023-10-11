# include <bits/stdc++.h>

using namespace std;

namespace kh {
  ifstream cin("grid.in");
  ofstream cout("grid.out");
  inline void writeln(__int128_t x) {
    static char stk[CHAR_BIT * sizeof(__int128_t)], *top(stk);
    while (*top++ = x % 10 + '0', x /= 10);
    while (cout.put(*--top), top != stk);
    cout.put('\n'), cout.flush();
  }
  constexpr long N(1'000'005);
  long n, m;
  __int128_t f[N], sum;
  void main() {
    cin >> n >> m, --n, --m;
    for (long i(max(n, m)); i; --i) {
      __int128_t s(0), t(0);
      for (long j(1); i * j <= n; ++j) s += n - i * j + 1;
      for (long j(1); i * j <= m; ++j) t += m - i * j + 1;
      f[i] = 2 * s * t;
      for (long j(1); i * j <= n; ++j) f[i] += (n - i * j + 1) * (m + 1);
      for (long j(1); i * j <= m; ++j) f[i] += (m - i * j + 1) * (n + 1);
      for (long j(2 * i); j <= max(n, m); j += i) f[i] -= f[j];
      sum += f[i] * ((n + 1) * (m + 1) - 2 * i) * i;
    }
    writeln(sum), sum = 0, memset(f, 0, sizeof f);
  }
}

int main() {
  int t((kh::cin >> t, t));
  for (int i(1); i <= t; ++i) kh::main();
}
