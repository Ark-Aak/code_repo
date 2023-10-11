# include <bits/stdc++.h>

using namespace std;

namespace kh {
  void main() {
    default_random_engine rng(0x4e7e'6a83);
    uniform_int_distribution<unsigned long> randlong;
    vector<unsigned long> arr(1 << 20);
    for (auto& v : arr) v = randlong(rng);
    uniform_int_distribution<size_t> rid(0, arr.size() - 1);
    unsigned long ans(randlong(rng));
    for (int i(0); i != 1 << 10; ++i) {
      arr.front() = randlong(rng);
      for (auto j(next(arr.begin())); j != arr.end(); advance(j, 1))
        *j = *prev(j) + (*prev(j) >> 2) + (*prev(j) << 3);
      ans += arr[rid(rng)];
      ans += ans >> 2, ans += ans << 3;
      ans += ans >> 5, ans += ans << 7;
    }
    cout << ans << '\n';
  }
}

int main() { kh::main(); }
