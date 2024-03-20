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

const int MAXN = 5e5 + 5;
const int MAXK = 2e6 + 5;
int n, k, ans;
int a[MAXN], cnt[MAXK], mx, Sum = 0;
int v[MAXN], tot;

namespace subtask1 {
	int ans = 1e18, b[15], c[15];

	void dfs(int step) {
		if (step > n) {
			int s = 0, cnt = n;
			rep (i, 1, n) {
				if (b[i]) {
					int Max = 0;
					rep (j, 1, n) {
						if (c[j] == i) Max = max(Max, a[j] - 1);
					}
					s += Max * cnt * 2;
					cnt -= b[i];
				}
			}
			ans = min(ans, s);
			return;
		}
		rep (i, 1, n) {
			if (!b[i] && !b[i - 1] && i != 1) continue;
			if (b[i] < k) {
				b[i]++;
				c[step] = i;
				dfs(step + 1);
				b[i]--;
			}
		}
	}
}

namespace subtask3 {
	int ans = ::ans, sum = Sum;

	void dfs(int step) {
		int tans = ans, flg = 0, tsum = sum;
		rep (i, 1, 10) {
			int tcnti = cnt[i];
			int K = k;
			if (cnt[i]) {
				ans += sum * i;
				int ptr = i;
			}
		}
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);
#endif
#endif
	read(n), read(k);
	rep (i, 1, n) read(a[i]), mx = max(mx, a[i]), cnt[a[i]]++;
	rep (i, 1, mx) if (cnt[i]) v[++tot] = i;
	Sum = n;
	rep (i, 1, mx) {
		ans += (i - 1) * (cnt[i]);
	}
	if (n <= 10) {
		subtask1::dfs(1);
		cout << subtask1::ans;
		return 0;
	}
	cout << ans;
	return 0;
}
