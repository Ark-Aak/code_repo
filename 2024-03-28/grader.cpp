#include <bits/stdc++.h>

#include "tree.h"
using namespace std;

int Q, T, n, f[2010];

int query(int a, int b, int c, int d) {
  int g1 = 0, g2 = 0;
  for (int i = a; i <= b; i++) g1 = __gcd(g1, f[i]);
  for (int i = c; i <= d; i++) g2 = __gcd(g2, f[i]);
  return g1 == g2;
}

int main() {
  cin >> Q >> T;
  for (int cas = 1; cas <= T; cas++) {
    cin >> n;
    for (int j = 0; j < n; j++) cin >> f[j];
    vector<int> Left(n);
    vector<int> Right(n);
    int rt = solve(n, Left, Right);
    cout << rt << endl;
    for (int j = 0; j < n; j++)
      cout << Left[j] << " " << Right[j] << endl;
  }
  return 0;
}