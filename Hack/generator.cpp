#include <bits/stdc++.h>
#include "datalib.h"

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;
using namespace Rand;

typedef long long ll;
typedef pair <int, int> pii;

int n, m;

int main() {
	n = rand_int(1, 200);
	m = rand_int(1, 200);
	printf("%d %d", n, m);
	return 0;
}
