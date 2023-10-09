#include <bits/stdc++.h>

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define _rep(i, a, b) for (auto i = a;i >= b; i--)

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

int n, k, mod, cnt[1000], ans;

void dfs(ll step, ll sum, ll x, ll lst) {
	if (step != 0 && sum % step == 0 && sum / step == x) {
		ans++, ans %= mod;
		cout << step << " " << sum << " " << x << endl;
	}
	rep (i, lst, n) {
		if (cnt[i] < k) {
			cnt[i]++;
			dfs(step + 1, sum + i, x, i);
			cnt[i]--;
		}
	}
}

int main() {
	cin >> n >> k >> mod;
	rep (i, 1, n) {
		dfs(0, 0, i, 1);
		cout << ans << endl;
		ans = 0;
	}
}
