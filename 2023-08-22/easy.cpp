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

int n, m, p[200005];
ll ans = 0;

void dfs(int step) {
	if (step > m) {
		rep (i, 1, n) {
			rep (j, i + 1, n) {
				if (p[i] > p[j]) ans += (j - i), ans %= 998244353;
			}
		}
		return;
	}
	rep (i, 1, n) {
		rep (j, i, n) {
			int L = i, R = j;
			while (L < R) {
				swap(p[L], p[R]);
				L++; R--;
			}
			dfs(step + 1);
			L = i, R = j;
			while (L < R) {
				swap(p[L], p[R]);
				L++; R--;
			}
		}
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);
#endif
#endif
	cin >> n >> m;
	rep (i, 1, n) cin >> p[i];
	dfs(1);
	cout << ans;
	return 0; 
}
