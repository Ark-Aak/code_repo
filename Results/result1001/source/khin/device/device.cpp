# include <bits/stdc++.h>

using namespace std;

namespace kh {
  ifstream cin("device.in");
  ofstream cout("device.out");
  void main() {
    int k, n;
    cin >> k >> n;
    int d0(k % 10); k /= 10;
    int d1(k % 10); k /= 10;
    int d2(k % 10); k /= 10;
    switch (n) {
      case 0:
        cout << 1 << '\n';
        break;
      case 1:
        if (d0 == d1 && d1 == d2 && d2 == d0)
        { cout <<  1 << '\n'; break; }
        if (d0 == d1 || d1 == d2 || d2 == d0)
        { cout <<  7 << '\n'; break; }
        if (d0 != d1 && d1 != d2 && d2 != d0)
        { cout << 24 << '\n'; break; }
        break;
      default:
        if (d0 == d1 && d1 == d2 && d2 == d0)
        { cout <<  1 << '\n'; break; }
        if (d0 == d1 || d1 == d2 || d2 == d0)
        { cout <<  8 << '\n'; break; }
        if (d0 != d1 && d1 != d2 && d2 != d0)
        { cout << 27 << '\n'; break; }
        break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  kh::cin.tie(nullptr);
  int t((kh::cin >> t, t));
  for (int i(1); i <= t; ++i) kh::main();
}
