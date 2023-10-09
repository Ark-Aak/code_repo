#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

using namespace std;

typedef long long ll;

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

const int MAXN = 1e6 + 5, MOD = 1e6 + 3;
int n, k, len, a[MAXN], ans;
bitset <MAXN> seq;

void dfs(int step) {
	if (step > n) {
		int tmp = 0;
		rep (i, 1, k) tmp += seq[i];
		if (tmp != a[1]) return;
		rep (i, 2, n - k + 1) {
			tmp -= seq[i - 1];
			tmp += seq[i + k - 1];
			if (tmp != a[i]) return;
		}
		ans++;
		ans %= MOD;
		return;
	}
	seq[step] = 1;
	dfs(step + 1);
	seq[step] = 0;
	dfs(step + 1);
} 

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("bit.in", "r", stdin);
	freopen("bit.out", "w", stdout);
#endif
#endif
	cin >> n >> k;
	len = n - k + 1;
	rep (i, 1, len) cin >> a[i];
	dfs(1);
	cout << ans << endl;
	return 0; 
}
