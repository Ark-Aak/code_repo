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

const int MAXN = 20;
int T;
int n, k, p;

namespace solution {
	typedef vector <int> vi;

	const int MOD = 998244353;
	bitset <MAXN> choice;
	int ans = 0;

	function <int (vi)> mex = [](vi a) {
		bitset <MAXN> vis;
		int res = 0;
		for (auto el : a) {
			vis[el] = 1;
			if (el == res) while (vis[res]) ++res;
		}
		return res;
	};

	function <vi (vi, int)> ultra = [](vi a, int m) {
		vi res;
		for (auto el : a) {
			res.emplace_back(el ^ m);
		}
		res.erase(unique(res.begin(), res.end()), res.end());
		sort(res.begin(), res.end());
		return res;
	};

	function <vi (vi)> next_limit = [](vi a) {
		return ultra(a, mex(a) - 1);
	};
	
	function <int (vi)> lim = [](vi a) {
		vi lst = a, tmp;
		while ((tmp = next_limit(lst)) != lst) lst = tmp;
		return mex(lst);
	};

	function <void (int)> solve = [](int step) {
		if (step >= k) {
			if ((int) choice.count() != n) return;
			vector <int> a;
			rep (i, 0, k - 1) {
				if (choice[i]) a.emplace_back(i);
			}
			if (lim(a) == p) {
				ans++, ans %= MOD;
			}
			return;
		}
		choice[step] = 1;
		solve(step + 1);
		if (step != 0) {
			choice[step] = 0;
			solve(step + 1);
		}
	};
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("earth.in", "r", stdin);
	freopen("earth.out", "w", stdout);
#endif
#endif
	read(T);
	while (T --> 0) {
		read(k), read(n), read(p);
		k = pow(2, k);
		solution::ans = 0;
		solution::choice.reset();
		solution::solve(0);
		print(solution::ans), putchar(10);
	}
	return 0;
}