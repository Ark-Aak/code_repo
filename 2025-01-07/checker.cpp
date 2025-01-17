#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 5;
int c[MAXN], n, k, t, _ans[MAXN];

signed main(int argc, char** argv) {
	registerTestlibCmd(argc, argv);
	n = inf.readInt(), k = inf.readInt(), t = inf.readInt();
	for (int i = 0; i < n; i++) c[i] = inf.readInt();
	for (int i = 0; i < n; i++) _ans[i] = ouf.readInt();
	for (int i = 0; i < n; i++) {
		int tot = 0;
		for (int _j = i; _j < i + t; _j++) {
			int j = _j % n;
			tot += _ans[j];
			tot %= k;
		}
		if (tot != c[i]) quitf(_wa, "wrong answer");
	}
	quitf(_ok, "accepted");
}
