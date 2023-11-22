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

const int MAXN = 1e5 + 5;

int n, m;
struct node {
	int x, t;

	bool operator < (const node &t) const {
		return x < t.x;
	}
} s[MAXN];

priority_queue <int> q;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("eatery.in", "r", stdin);
	freopen("eatery.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, n) read(s[i].x), read(s[i].t);
	sort(s + 1, s + 1 + n);
	int ans = 0, sum = 0;
	rep (i, 1, n) {
		if (q.empty() && s[i].x + s[i].t <= m) {
			q.push(s[i].t);
			sum += s[i].t;
			ans = max(ans, (int) q.size());
			continue;
		}
		while (!q.empty() && q.top() + s[i].x > m) {
			sum -= q.top(); q.pop();
		}
		if (sum + s[i].x + s[i].t <= m) q.push(s[i].t), sum += s[i].t;
		ans = max(ans, (int) q.size());
	}
	print(ans);
	return 0;
}