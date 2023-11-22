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

#define int ll

const int MAXN = 1e7 + 5;
const int MOD = 998244353;
vector <int> prime;
int phi[MAXN], flg[MAXN], n, k;

void sieve(int n) {
	phi[1] = 1;
	rep (i, 2, n) {
        if(!flg[i]) {
            prime.emplace_back(i);
            phi[i] = i - 1;
        }
        for (auto j : prime) {
			if (i * j > n) break;
            flg[i * j] = 1;
            if (i % j == 0) {
                phi[i * j] = phi[i] * j;
                break;
            }
            phi[i * j] = phi[i] * (j - 1);
        }
    }
}

namespace factor {
	vector <int> fac;
	int cnt[MAXN];

	function <int (int)> count = [](int x) {
		ll ans = 1;
		for (auto v : fac) {
			int c = 0;
			while (x % v == 0) x /= v, c++;
			ans = ans * (cnt[v] * k - c + 1) % MOD;
		}
		return ans;
	};

	function <void (int)> split = [](int x) {
		for (auto i : prime) {
			if (i * i > x) break;
			if (x % i == 0) {
				fac.emplace_back(i);
				int c = 0;
				while (x % i == 0) x /= i, c++;
				cnt[x] = c;
			}
		}
		if (x != 1) fac.emplace_back(x), cnt[x] = 1;
	};
}

namespace solution {
	int ans = 0;
	int used[MAXN];
	bool vis[MAXN];

	function <void (int)> solve = [](int s) {
		ans += phi[s] * factor::count(s) % MOD * (n / s) % MOD;
		ans %= MOD;
		for (auto v : factor::fac) {
			if (s * v <= n && !vis[s * v] && used[v] < factor::cnt[v] * k) {
				used[v]++;
				vis[s * v] = 1;
				solve(s * v);
				used[v]--;
			}
		}
	};
}

signed main() {
	read(n), read(k);
	sieve(1e7);
	factor::split(n);
	solution::solve(1);
	print(solution::ans);
	return 0;
}