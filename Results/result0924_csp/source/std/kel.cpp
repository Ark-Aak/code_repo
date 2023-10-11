#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 1e6 + 10;
int n, l, r, cnt, res[N];

namespace fast_io {
  int it, ed, c, f, ot;
  char t, stk[20], bf[N + 50], ob[N + 50];
  #define gc (it == ed && (ed = (it = 0) + fread(bf, 1, N, stdin), it == ed)) ? EOF : bf[it++]
  template <typename T> inline void read(T &x) {
    for (c = gc; c < 48; c = gc);
    for (x = 0; c > 47; x = x * 10 + (48 ^ c), c = gc); return ;
  } inline void fls() { fwrite(ob, 1, ot, stdout), ot = 0; }
  inline void write(int x) {
    while (x > 9) stk[++t] = 48 ^ (x % 10), x /= 10;
    for (ob[ot++] = 48 ^ x; t; ob[ot++] = stk[t--]);
    ob[ot++] = '\n'; if (ot > N) fls(); return ;
  }
} using fast_io::read; using fast_io::write;

int main() {
  freopen("kel.in", "r", stdin);
  freopen("kel.out", "w", stdout);
  read(n), read(l), read(r);
  if (n <= 3) {
    for (int i = 1; i <= n; ++i) write(l);
    fast_io::fls(); return 0;
  }
  ll Max = (ll) (r - l + 1) * (r - l + 2) + 1;
  if (Max < (ll)n) {
    puts("Shinomiya");
    return 0;
  }
  int lef = l, rig = l;
  for (int i = 1; i <= n / 2; ++i) {
    if (lef > r) continue;
    res[++cnt] = lef, res[++cnt] = rig;
    ++rig; if (rig > r) rig = ++lef;
  }
  if (cnt < n) res[++cnt] = lef;
  if (res[n - 1] == r) res[n] = l;
  for (int i = 1; i <= n; ++i) write(res[i]);
  fast_io::fls(); return 0;
}
