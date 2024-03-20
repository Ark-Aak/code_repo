#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,sse2,sse3,sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace __gnu_pbds;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll read() {
	ll x = 0, f = 1;
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
int n, x, tot = 0;
ll m;
int st[300010], lim[1010], cnt[600010];
pair <int, int> p[MAXN];
gp_hash_table<ll, int> mp;

inline void mul(ll i, int x) {
	auto it = mp.find(i);
	if (it != mp.end()) it -> second = 1ll * it -> second * x % MOD;
	else mp[i] = x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep (i, 1, n) {
		cin >> x;
		for (int j = 2; j * j <= x; j++) for (; x % j == 0; x /= j) p[++tot] = {j, i};
		if (x > 1) p[++tot] = {x, i};
	}
	sort(p + 1, p + tot + 1);
	rep (i, 1, tot) st[i] = ++cnt[p[i].second];
	memset(cnt + 1, 0, 4 * n);
	for (int i = 1; i * (i - 1) / 2 < tot; i++) lim[i] = i * i - i, cnt[lim[i] + 1]++;
	rep (i, 1, MAXN - 5) cnt[i] += cnt[i - 1];
	int k = 1;
	rep (i, 1, tot) {
		ll t = st[i];
		while (k * (k + 1) / 2 < i) k++;
		while (t <= min(m, (ll) lim[k])) {
			if (t + (++cnt[t]) > m) break;
			t += cnt[t];
		}
		if (t <= m && t > lim[k]) t += (m - t) / k * k;
		if (t > m) mul(-p[i].second, p[i].first);
		else mul(t, p[i].first);
	}
	cout << mp.size() << "\n";
	for (auto p : mp) cout << p.second << " ";
	return 0;
}