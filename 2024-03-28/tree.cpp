#include "tree.h"

#include <bits/stdc++.h>

namespace aak {
	const int MAXN = 1e3 + 5;
	int stk[MAXN], tp;
}

int solve(int N, std::vector<int> &Left, std::vector<int> &Right) {
	aak::tp = 0;
	for (int i = 0; i < N; i++) {
		Left[i] = Right[i] = -1;
		if (aak::tp == 0) aak::stk[++aak::tp] = i;
		else {
			while (aak::tp) {
				if (query(i, i, aak::stk[aak::tp], i)) Left[i] = aak::stk[aak::tp--];
				else break;
			}
			if (aak::tp) Right[aak::stk[aak::tp]] = i;
			aak::stk[++aak::tp] = i;
		}
	}
	return aak::stk[1];
}
