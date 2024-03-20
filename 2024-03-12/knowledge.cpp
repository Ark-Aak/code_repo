#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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

const int MAXN = 1e5 + 5;
int n, k, a[MAXN], ans, res[MAXN];
vector <int> b[MAXN];
map <int, set <vector <int> > > mp;

signed main() {
	n = read(), k = read();
	rep (i, 1, n) a[i] = read(), mp[a[i] / k].insert({a[i] % k, i});
	rep (i, 1, n) {
		int x = read();
		b[i] = {x, i};
	}
	sort(b + 1, b + n + 1, greater <vector <int> >());
	rep (i, 1, n) {
		for (; ; mp.erase(--mp.end())) {
			/* cerr << i << endl; */
			auto &it = *mp.rbegin();
			auto &s = it.fb;
			if (s.empty()) continue;
			if (b[i][0] >= it.ec * k + s.begin() -> front()) {
				auto iter = (s.lower_bound({b[i][0] - it.ec * k + 1, 0}));
				iter--;
				res[iter -> back()] = b[i][1];
				s.erase(iter);
				break;
			}
			int tmp = max(1ll, it.first - b[i][0] / k);
			ans += tmp * s.size();
			/* cout << s.size() << endl; */
			auto &t = mp[it.first - tmp];
			if (s.size() > t.size()) swap(s, t);
			t.insert(s.begin(), s.end());
		}
	}
	print(ans), putchar(10);
	rep (i, 1, n) print(res[i]), putchar(32);
	return 0;
}
