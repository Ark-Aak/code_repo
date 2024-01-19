#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 105;
int n, a[MAXN][3], ans;
int T, sel[MAXN], lst[3], cnt[3];

void dfs(int step) {
	if (step > n) {
		memset(cnt, 0, sizeof cnt);
		memset(lst, 0, sizeof lst);
		int sum = 0;
		rep (i, 1, n) {
			cnt[sel[i]] += a[i][sel[i]];
			lst[sel[i]] = i;
			rep (j, 0, 2) cnt[j] -= i - lst[j], cnt[j] = max(cnt[j], 0ll);
		}
		rep (i, 0, 2) sum += cnt[i];
		ans = max(ans, sum);
		return;
	}
	rep (i, 0, 2) {
		sel[step] = i;
		dfs(step + 1);
	}
}

void solve() {
	n = read();
	rep (i, 1, n) a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
	if (n <= 10) {
		ans = 0;
		memset(cnt, 0, sizeof cnt);
		memset(lst, 0, sizeof lst);
		dfs(1);
		print(ans), putchar(10);
	}
	else {
		ans = 0;
		memset(cnt, 0, sizeof cnt);
		memset(lst, 0, sizeof lst);
		rep (i, 1, n) {
			int tlst[3], tcnt[3], tans = 0, fans = 0, pans = -1;
			rep (i, 0, 2) tlst[i] = lst[i], tcnt[i] = cnt[i];
			tlst[0] = i, tcnt[0] += a[i][0];
			tcnt[1] = max(0ll, tcnt[1] - (i - tlst[1]));
			tcnt[2] = max(0ll, tcnt[2] - (i - tlst[2]));
			rep (i, 0, 2) tans += tcnt[i];
			if (tans > fans) pans = 0, fans = tans;
			tans = 0;
			rep (i, 0, 2) tlst[i] = lst[i], tcnt[i] = cnt[i];
			tlst[1] = i, tcnt[1] += a[i][1];
			tcnt[0] = max(0ll, tcnt[0] - (i - tlst[0]));
			tcnt[2] = max(0ll, tcnt[2] - (i - tlst[2]));
			rep (i, 0, 2) tans += tcnt[i];
			if (tans > fans) pans = 1, fans = tans;
			tans = 0;
			rep (i, 0, 2) tlst[i] = lst[i], tcnt[i] = cnt[i];
			tlst[2] = i, tcnt[2] += a[i][2];
			tcnt[1] = max(0ll, tcnt[1] - (i - tlst[1]));
			tcnt[0] = max(0ll, tcnt[0] - (i - tlst[0]));
			rep (i, 0, 2) tans += tcnt[i];
			if (tans > fans) pans = 2;
			tans = 0;
			if (pans == 0) {
				lst[0] = i, cnt[0] += a[i][0];
				cnt[1] = max(0ll, cnt[1] - (i - lst[1]));
				cnt[2] = max(0ll, cnt[2] - (i - lst[2]));
				rep (i, 0, 2) tans += cnt[i];
				ans = tans;
			}
			if (pans == 1) {
				lst[1] = i, cnt[1] += a[i][1];
				cnt[0] = max(0ll, cnt[0] - (i - lst[0]));
				cnt[2] = max(0ll, cnt[2] - (i - lst[2]));
				rep (i, 0, 2) tans += cnt[i];
				ans = tans;
			}
			if (pans == 2) {
				lst[2] = i, cnt[2] += a[i][2];
				cnt[1] = max(0ll, cnt[1] - (i - lst[1]));
				cnt[0] = max(0ll, cnt[0] - (i - lst[0]));
				rep (i, 0, 2) tans += cnt[i];
				ans = tans;
			}
		}
		print(ans), putchar(10);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("codechef.in", "r", stdin);
	freopen("codechef.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
