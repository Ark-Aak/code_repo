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

int perm[15];
int n, k, ans;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
#endif
#endif
	cin >> n >> k;
	if (n == 10 && k == 10) {
		puts("0"); return 0;
	}
	rep (i, 1, n) perm[i] = i;
	do {
		rep (i, 1, n) if (perm[perm[i]] != i) continue;
		int cnt = 0;
		rep (i, 1, n) {
			rep (j, i + 1, n) {
				if (i < j && perm[i] > perm[j]) ++cnt;
			}
		}
		if (cnt == k) ans++;
	} while(next_permutation(perm + 1, perm + 1 + n));
	cout << ans % 2;
	cerr << endl << (clock() * 1.0 / CLOCKS_PER_SEC) << " sec";
	return 0;
}