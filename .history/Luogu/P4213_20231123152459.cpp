#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define int ll

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

const int MAXN = 1664510 + 5;
int T;
bool flg[MAXN], vis[MAXN], mu[MAXN];
vector <int> prime;

void sieve(int n) {
	mu[1] = 1;
	rep (i, 2, n) {
		if (!flg[i]) prime.emplace_back(i), mu[i] = -1;
		for (auto j : prime) {
			if (i * j > n) break;
			flg[i * j] = 1;
			if (i % j == 0) {
				mu[i * j] = 0;
				break;
			}
			mu[i * j] = -mu[i];
		}
	}
	rep (i, 1, n) mu[i] += mu[i - 1];
}

unordered_map <int, int> mem;
const int MAXP = 1664510;

int suffix_sum_mu(int x) {
	if (x <= MAXP) return mu[x];
	if (mem.count(x)) return mem[x];
	int res = 1;
	for (int l = 2, r; l <= x; l = r + 1) {
		r = x / (x / l);
		res -= (r - l + 1) * suffix_sum_mu(x / l);
	}
	return mem[x] = res;
}

int suffix_sum_phi(int x) {
	int res = 0;
	for (int l = 1, r; l <= x; l = r + 1) {
		r = (x / (x / l));
		res = (suffix_sum_mu(r) - suffix_sum_mu(l - 1)) * (x / l) * (x / l);
	}
	return (res - 1) / 2 + 1;
}

int T, n;

int main() {
	sieve(1664510);
	read(T);
	while (T --> 0) {
		read(n);
		print(suffix_sum_mu(n)), putchar(32);
		print(suffix_sum_phi(n)), putchar(10);
	}
	return 0;
}