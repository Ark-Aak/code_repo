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

int id, T;
int l, r;

vector <int> get_factor(int x) {
	vector <int> ret;
	rep (i, 2, sqrt(x)) while (x % i == 0) ret.emplace_back(i), x /= i;
	if (x > 1) ret.emplace_back(x);
	return ret;
}

int calc1(int x) {
	int s = 0;
	while (x) {
		if (x >= 1) s += ((x - 1) >> 1) + 1;
		x >>= 1;
	}
	return s;
}

int calc2(int x) {
	int s = 0;
	while (x) {
		x >>= 1;
		s += x;
	}
	return s;
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
#endif
#endif
	read(id), read(T);
	while (T --> 0) {
		read(l), read(r);
		if (l == r) {
			int t = sqrt(l);
			if (t * t == l)	{
				print(1), putchar(10);
				continue;
			}
		}
		unordered_map <int, int> cnt;
		bool flg = 1;
		_rep (i, r, l) {
			vector <int> fac = get_factor(i);
			for (auto x : fac) ++cnt[x];
			for (auto x : cnt) {
				int p = x.first, e = x.second;
				if (p >= i && p % 4 == 3 && e % 2) {
					flg = 0;
				}
			}
			if (!flg) break;
		}
		for (auto x : cnt) {
			int p = x.first, e = x.second;
			if (p % 4 == 3 && e % 2) {
				flg = 0;
			}
		}
		if (flg) {
			print(2), putchar(10);
			continue;
		}
		int x = 1;
		for (int i = 1; i <= 7; i++) {
			
		}
	}
	return 0;
}
