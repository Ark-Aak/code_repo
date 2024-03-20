#include <bits/stdc++.h>
#define rep(x,y,z) for (int x=y;x<=z;x++)
using namespace std;
typedef long long ll;
const int N = 1e5+5, inf = 1e9;

int n, a[N], buc[N], mi = inf;

void solve() {
	memset(buc, 0, sizeof buc);
	mi = inf;
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]), mi = min(mi, a[i]);
	if(n & 1) return cerr << "die on 1" << endl, puts("NO"), void();
	sort(a+1, a+1+n);
	rep(i, 2, n) if(a[i] - a[i-1] > 1) return cerr << "die on 2 with " << a[i] << " " << a[i - 1] << endl, puts("NO"), void();
	rep(i, 1, n) ++buc[a[i]-mi+1];
	int u = 1; --buc[1];
	while (true) {
		if(buc[u+1]) --buc[++u];
		else if(buc[u-1]) --buc[--u];
		else break;
	}
	if(u != 2) return cerr << "die on 3" << endl, puts("NO"), void();
	rep(i, 0, N-1) if(buc[i]) return cerr << "die on 4" << endl, puts("NO"), void();
	return cerr << "OK" << endl, puts("YES"), void();
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --> 0) solve();
}