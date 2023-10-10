#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MOD = 1e9 + 7;
int n, b[10], a[10], ans;

void dfs(int step) {
	if (step > n) {
		bool vis[10] = {0};
		rep (i, 1, n) {
			vis[a[i]] = 1;
		}
		rep (i, 0, 10) if (!vis[i]) {
			ans += i;
			ans %= MOD;
			break;
		}
		return;
	}
	rep (i, 0, b[step]) a[step] = i, dfs(step + 1);
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("mex.in", "r", stdin);
	freopen("mex.out", "w", stdout);
#endif
#endif
	cin >> n;
	rep (i, 1, n) cin >> b[i];
	dfs(1);
	cout << ans;
	return 0;
}
