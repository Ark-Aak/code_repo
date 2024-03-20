#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 10;

int n;
int a[N];
int x[N];

int main(int argc, char** argv) {
    registerTestlibCmd(argc, argv);
    n = inf.readInt();
    for (int i = 1; i <= 2 * n - 1; ++i) {
        a[i] = inf.readInt();
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        x[i] = ouf.readInt();
        sum = (sum + a[x[i]]) % n;
    }
    if (sum) {
        quitf(_wa, "yiw?/kk");
    }
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (x[i] == x[i - 1]) {
            quitf(_wa, "/qd");
        }
        if (x[i] < 1 || x[i] > 2 * n - 1) quitf(_wa, "/cf");
    }
    quitf(_ok, "AC");
    return 0;
}