#include <bits/stdc++.h>
#include "datalib.h"

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;
using namespace Rand;

typedef long long ll;
typedef pair <int, int> pii;

int n, m;
int T;

int main() {
	T = 2e6;
	IO::print(T);
	while (T --> 0) {
		n = rand_int(1, 5e7);
		m = rand_int(1, 5e7);
		IO::print(min(n, m), max(n, m)), putchar(10);
	}
	return 0;
}
