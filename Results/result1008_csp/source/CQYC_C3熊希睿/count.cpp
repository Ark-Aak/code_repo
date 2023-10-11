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

int n, m, b[100], a[100], ans;

void solve() {
	int lst = 0, cnt = 0;
	rep (i, 1, n) {
		if (a[i] != lst) cnt = 1, lst = a[i];
		else cnt++;
		if (cnt > b[lst]) return;
	}
	ans++;
	ans %= 998244353;
}

void generate(int step) {
	if (step > n) return solve();
	rep (i, 1, m) a[step] = i, generate(step + 1);
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
#endif
#endif
	cin >> n >> m;
	rep (i, 1, m) cin >> b[i];
	generate(1);
	cout << ans;
	return 0; 
}
