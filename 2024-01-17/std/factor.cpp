#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int read() {
	int x = 0, f = 1;
	char c = getchar();
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
	if (x < 0)
		x = (~x + 1), putchar('-');
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 600005, MOD = 1e9 + 7;
ll n, x, tot = 0, m;
int st[MAXN], lim[MAXN], cnt[MAXN];
pair <int, int> p[MAXN];
map <ll, int> mp;

void mul(ll i, int x) {
	auto it = mp.find(i);
	if (it != mp.end()) it -> second = 1ll * it -> second * x % MOD;
	else mp[i] = x;
}

int main() {
	n = read(), m = read();
	rep(i, 1, n) {
		x = read();
		rep(j, 2, sqrt(x)) for (; x % j == 0; x /= j) p[++tot] = {j, i};
		if (x > 1) p[++tot] = {x, i};
	}
	sort(p + 1, p + tot + 1);
	rep(i, 1, tot) st[i] = ++cnt[p[i].second];
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i * (i - 1) / 2 < tot; i++) lim[i] = i * i - i, cnt[lim[i] + 1]++;
	rep(i, 1, MAXN - 5) cnt[i] += cnt[i - 1];
	int k = 1;
	rep(i, 1, tot) {
		int t = st[i];
		while (k * (k + 1) / 2 < i) k++;
		while (t <= min(m, (ll) lim[k])) {
			if (t + (++cnt[t]) > m) break;
			t += cnt[t];
		}
		if (t <= m && t > lim[k]) t += (m - t) / k * k;
		if (t > m) mul(-p[i].second, p[i].first);
		else mul(t, p[i].first);
	}
	print(mp.size()), putchar(10);
	for (auto p : mp) print(p.second), putchar(32);
	return 0;
}