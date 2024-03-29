#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (int) (a); i <= (int) (b); i++)
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

int T, n, m;

bool check(vector <int> a) {
	int minn = 1e9, xorsum = 0;
	for (auto i : a) minn = min(minn, i), xorsum ^= i;
	return minn > xorsum;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("divide.in", "r", stdin);
	freopen("divide.out", "w", stdout);
#endif
#endif
	//7 -> 3, 5
	//5 -> 2, 6
	read(T);
	while (T --> 0) {
		read(n), read(m);
		if (n == 1) {
			puts("-1");
			continue;
		}
		if (n <= 3) goto three;
		if (n % 2 == 0 && m % 2 == 0) {
			rep (i, 1, n - 2) putchar('1'), putchar(32);
			print((m - n + 2) / 2), putchar(32), print((m - n + 2) / 2), putchar(10);
			continue;
		}
		else if (n % 2 == 0 && m % 2 == 1) {
			vector <int> ans;
			int sum = 5;
			ans.emplace_back(2), ans.emplace_back(3);
			if ((int) ans.size() < n) rep (i, ans.size() + 1, n - 2) ans.emplace_back(2), sum += 2;
			if (sum >= m && (int) ans.size() < n) {
				puts("-1");
				continue;
			}
			if ((int) ans.size() < n) ans.emplace_back((m - sum) / 2), ans.emplace_back((m - sum) / 2), sum += (m - sum);
			if (sum != m) {
				puts("-1");
				continue;
			}
			if ((int) ans.size() != n) {
				puts("-1");
				continue;
			}
			if (!check(ans)) {
				puts("-1");
				continue;
			}
			for (auto i : ans) print(i), putchar(32);
			putchar(10);
		}
		else if (n % 2 == 1 && m % 2 == 0) {
			vector <int> ans;
			long long sum = 6;
			ans.emplace_back(1), ans.emplace_back(2), ans.emplace_back(3);
			if (n < 3) {
				puts("-1");
				continue;
			}
			if (m < 6) {
				puts("-1");
				continue;
			}
			if ((int) ans.size() < n) rep (i, ans.size() + 1, n - 2) ans.emplace_back(1), sum++;
			if (sum >= m && (int) ans.size() < n) {
				puts("-1");
				continue;
			}
			if ((int) ans.size() < n) ans.emplace_back((m - sum) / 2), ans.emplace_back((m - sum) / 2), sum += (m - sum);
			if (sum != m) {
				puts("-1");
				continue;
			}
			if ((int) ans.size() != n) {
				puts("-1");
				continue;
			}
			if (!check(ans)) {
				puts("-1");
				continue;
			}
			for (auto i : ans) print(i), putchar(32);
			putchar(10);
		}
		else {
			vector <int> ans;
			int sum = 13;
			ans.emplace_back(5);
			ans.emplace_back(2), ans.emplace_back(6);
			if (m < 13 || n < 3) {
				puts("-1");
				continue;
			}
			if ((int) ans.size() < n) rep (i, (int) ans.size() + 1, n - 2) ans.emplace_back(2), sum += 2;
			if (sum >= m && (int) ans.size() < n) {
				puts("-1");
				continue;
			}
			if ((int) ans.size() < n) ans.emplace_back((m - sum) / 2), ans.emplace_back((m - sum) / 2), sum += (m - sum);
			if (sum != m) {
				puts("-1");
				continue;
			}
			if ((int) ans.size() != n) {
				puts("-1");
				continue;
			}
			if (!check(ans)) {
				puts("-1");
				continue;
			}
			for (auto i : ans) print(i), putchar(32);
			putchar(10);
		}
		continue;
		three:
		int tn = m / 2, tm = m;
		rep (i, -20, 20) {
			rep (j, -20, 20) {
				int ttn1 = tn + i, ttn2 = tn + j;
				tm = m - ttn1 - ttn2;
				if (ttn1 <= 0 || ttn2 <= 0) continue;
				if (tm < 0) continue;
				if (n == 2 && tm == 0) {
					if (min(ttn1, ttn2) > (ttn1 ^ ttn2)) {
						print(ttn1), putchar(32), print(ttn2), putchar(10);
						goto end;
					}
				}
				else if (n == 3 && tm > 0) {
					if (min(tm, min(ttn1, ttn2)) > (tm ^ ttn1 ^ ttn2)) {
						print(tm), putchar(32), print(ttn1), putchar(32), print(ttn2), putchar(10);
						goto end;
					}
				}
			}
		}
		puts("-1");
		end:
		continue;
	}
	return 0;
}