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

	bitset <MAXN> choice;

	function <int (vi)> mex = [](vi a) {
		bitset <MAXN> vis;
		int res = 0;
		for (auto el : a) {
			vis[el] = 1;
			if (el == res) while (vis[res]) ++res;
		}
	};

	function <vi (vi, int)> ultra = [](vi a, int m) {
		vi res;
		for (auto el : a) {
			res.emplace_back(el ^ m);
		}
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	};

	auto solve = [](auto dfs, int step) {
		if (step >= 2 * k) {
			if (choice.count() != n) return;
			vector <int> a;
			rep (i, 0, 2 * k - 1) {
				if (choice[i]) a.emplace_back(i);
			}
			return;
		}
		choice[step] = 1;
		dfs(step + 1);
		if (step != 0) {
			choice[step] = 0;
			dfs(step + 1);
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
		read(n), read(k), read(p);

	}
	return 0;
}