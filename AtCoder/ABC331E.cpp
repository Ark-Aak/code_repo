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

int n, m, l;
int a[100005], b[100005];
vector <int> g[100005];
multiset <int> s;

int main() {
	read(n), read(m), read(l);
	rep (i, 1, n) {
		read(a[i]);
	}
	rep (i, 1, m) {
		read(b[i]);
		s.insert(b[i]);
	}
	rep (i, 1, l) {
		int a, b;
		read(a), read(b);
		g[a].emplace_back(b);
	}
	int ans = 0;
	rep (i, 1, n) {
		for (auto x : g[i]) {
			auto iter = s.lower_bound(b[x]);
			if (iter == s.end()) continue;
			if ((*iter) == b[x]) s.erase(iter);
		}
		if (s.size()) ans = max(ans, a[i] + (*s.rbegin()));
		for (auto x : g[i]) {
			s.insert(b[x]);
		}
	}
	cout << ans << endl;
	return 0;
}
