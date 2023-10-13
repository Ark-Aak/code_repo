#include <bits/stdc++.h>
#include "datalib.h"

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

ll a, b, ans;
const int MAXN = 5e7 + 5;

vector <int> p;
bitset <MAXN> vis;
int f[MAXN], sum[MAXN];

void sieve(int n) {
	f[1] = 1;
	vis[1] = 1;
	rep (i, 2, n) {
		if (!vis[i]) {
			p.emplace_back(i);
			f[i] = i + 1;
		}
		for (auto j : p) {
			if (i * j > n) break;
			int pos = i * j;
			vis[pos] = 1;
			f[pos] = f[i] * f[j];
			if (i % j == 0) {
				f[pos] -= f[i / j] * j;
				break;
			}
		}
	}
}

int lstans = 0;
const int MOD = 998244353;

using namespace Rand;

signed main() {
	sieve(5e7);
	for (int i = 1; i <= 5e7; i++) sum[i] = (sum[i - 1] + abs(i - (f[i] - i))) % MOD;
	for (int i = 1; i <= 30; i++) {
		stringstream ss1, ss2;
		ss1 << "data/test" << i << ".out";
		ss2 << "data/test" << i << ".in";
		ofstream ouf(ss1.str()), inf(ss2.str());
		int T = 2e6;
		inf << T << endl;
		while (T --> 0) {
			int a = rand_long(1, 5e7);
			int b = rand_long(1, 5e7);
			inf << (min(a, b) ^ lstans) << " " << (max(a, b) ^ lstans) << endl;
			ouf << (sum[max(a, b)] - sum[min(a, b) - 1] + MOD) % MOD << endl;
			lstans = (sum[max(a, b)] - sum[min(a, b) - 1] + MOD) % MOD;
		}
		ouf.close(), inf.close();
		lstans = 0;
	}
	return 0;
}