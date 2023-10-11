# include <bits/stdc++.h>

using namespace std;

namespace kh {
  ifstream cin("triple.in");
  ofstream cout("triple.out");
  template <typename T>
    constexpr T& cmin(T& a, T const& b)
    { return a = std::min(a, b); }
  template <typename T>
    constexpr T& cmax(T& a, T const& b)
    { return a = std::max(a, b); }
  constexpr bool chk(long a, long b) { return a ? !(b % a) : !b; }
  void main() {
    long p, q, r;
    long a, b, c;
    cin >> p >> q >> r;
    cin >> a >> b >> c;
    int ans(3);
    for (int i(0); i != 4; ++i)
      for (int j(0); j != 4; ++j)
        for (int k(0); k != 4; ++k)
          for (int o(0); o != 4; ++o) {
            if (__builtin_popcount(i | j | k) > ans) continue;
            int const ab(a - b), pq(p - q);
            int const bc(b - c), qr(q - r);
            int const ca(c - a), rp(r - p);
            int const x(o >> 0 & 1);
            int const y(o >> 1 & 1);
            long dx(0); bool ix(false);
            long dy(0); bool iy(false);
            if (i == 1 && x == 0) dx = a - p, ix = true;
            if (j == 1 && x == 0) dx = b - q, ix = true;
            if (k == 1 && x == 0) dx = c - r, ix = true;
            if (i == 2 && y == 0) dy = a - p, iy = true;
            if (j == 2 && y == 0) dy = b - q, iy = true;
            if (k == 2 && y == 0) dy = c - r, iy = true;
            if (i == 1 && x == 1 && p) dx = a / p, ix = true;
            if (j == 1 && x == 1 && q) dx = b / q, ix = true;
            if (k == 1 && x == 1 && r) dx = c / r, ix = true;
            if (i == 2 && y == 1 && p) dy = a / p, iy = true;
            if (j == 2 && y == 1 && q) dy = b / q, iy = true;
            if (k == 2 && y == 1 && r) dy = c / r, iy = true;
            if (i == 3 && j == 3 && o == 1 && pq) dx = ab / pq, ix = true;
            if (j == 3 && k == 3 && o == 1 && qr) dx = bc / qr, ix = true;
            if (k == 3 && i == 3 && o == 1 && rp) dx = ca / rp, ix = true;
            if (i == 3 && j == 3 && o == 2 && pq) dy = ab / pq, iy = true;
            if (j == 3 && k == 3 && o == 2 && qr) dy = bc / qr, iy = true;
            if (k == 3 && i == 3 && o == 2 && rp) dy = ca / rp, iy = true;
            if (i == 3 && o == 0 && ix) dy = a - p - dx, iy = true;
            if (j == 3 && o == 0 && ix) dy = b - q - dx, iy = true;
            if (k == 3 && o == 0 && ix) dy = c - r - dx, iy = true;
            if (i == 3 && o == 0 && iy) dx = a - p - dy, ix = true;
            if (j == 3 && o == 0 && iy) dx = b - q - dy, ix = true;
            if (k == 3 && o == 0 && iy) dx = c - r - dy, ix = true;
            if (i == 3 && o == 1 && ix) dy = a - p * dx, iy = true;
            if (j == 3 && o == 1 && ix) dy = b - q * dx, iy = true;
            if (k == 3 && o == 1 && ix) dy = c - r * dx, iy = true;
            if (i == 3 && o == 1 && iy && p) dx = (a - dy) / p, ix = true;
            if (j == 3 && o == 1 && iy && q) dx = (b - dy) / q, ix = true;
            if (k == 3 && o == 1 && iy && r) dx = (c - dy) / r, ix = true;
            if (i == 3 && o == 2 && ix && p + dx) dy = a / (p + dx), iy = true;
            if (j == 3 && o == 2 && ix && q + dx) dy = b / (q + dx), iy = true;
            if (k == 3 && o == 2 && ix && r + dx) dy = c / (r + dx), iy = true;
            if (i == 3 && o == 2 && dy) dx = a / dy - p, ix = true;
            if (j == 3 && o == 2 && dy) dx = b / dy - q, ix = true;
            if (k == 3 && o == 2 && dy) dx = c / dy - r, ix = true;
            if (i == 3 && o == 3 && dx && p) dy = a / p / dx, iy = true;
            if (j == 3 && o == 3 && dx && q) dy = b / q / dx, iy = true;
            if (k == 3 && o == 3 && dx && r) dy = c / r / dx, iy = true;
            if (i == 3 && o == 3 && dy && p) dx = a / p / dy, ix = true;
            if (j == 3 && o == 3 && dy && q) dx = b / q / dy, ix = true;
            if (k == 3 && o == 3 && dy && r) dx = c / r / dy, ix = true;
            int _p(p), _q(q), _r(r);
            x ? _p *= i & 1 ? dx : 1 : _p += i & 1 ? dx : 0;
            x ? _q *= j & 1 ? dx : 1 : _q += j & 1 ? dx : 0;
            x ? _r *= k & 1 ? dx : 1 : _r += k & 1 ? dx : 0;
            y ? _p *= i & 2 ? dy : 1 : _p += i & 2 ? dy : 0;
            y ? _q *= j & 2 ? dy : 1 : _q += j & 2 ? dy : 0;
            y ? _r *= k & 2 ? dy : 1 : _r += k & 2 ? dy : 0;
            if (_p == a && _q == b && _r == c)
              cmin(ans, __builtin_popcount(i | j | k));
          }
    cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  kh::cin.tie(nullptr);
  int t(true ? kh::cin >> t, t : 1);
  for (int i(1); i <= t; ++i) kh::main();
}
