#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

int n, k, fans;
int a[100], b[100], c[100];
const int mod = 1e9 + 7;

void solve() {
	rep (i, 1, n) c[i] = a[i] = b[i];
	int ans = 0;
	rep (i, 1, n) {
		ans += a[i];
	}
	_rep (i, n, 1) {
		if (c[i] > i) continue;
		rep (j, 1, a[i] / i) {
			rep (l, 1, i - 1) a[l]++;
		}
		ans -= a[i] / i;
		a[i] %= i;
	}
	fans += ans;
	fans %= mod;
}

void generate(int step) {
	if (step > n) return solve();
	rep (i, 0, k) b[step] = i, generate(step + 1);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
#endif
#endif
	cin >> n >> k;
	generate(1);
	cout << fans;
	return 0; 
}
