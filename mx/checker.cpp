#include "testlib.h"
#include <bits/stdc++.h>

signed main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);
	int n = inf.readInt(), q = inf.readInt();
	for (int i = 1; i <= q; i++) {
		double a1 = ouf.readDouble(), a2 = ans.readDouble();
		double err = fabs(a1 - a2) / fmax(1.0, a2);
		if (err > 1e-6) quitf(_wa, "Wrong Answer on query #%d", i);
	}
	quitf(_ok, "Accepted");
    return 0;
}
