#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

#define int ll

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

set <int> s;
vector <pii> v;
unordered_map <int, int> cnt;
int n;

signed main() {
	cin >> n;
	int ans = 0;
	rep (i, 1, n) {
		int s, c;
		cin >> s >> c;
		v.emplace_back(make_pair(s, c));
		cnt[s] += c; ans += c;
		::s.insert(s);
	}
	sort(v.begin(), v.end());
	int S = 0;
	s.insert(1e18);
	while (S < 1e18) {
		S = *s.upper_bound(S);
		s.insert(S * 2);
		ans -= cnt[S] - (cnt[S] & 1);
		cnt[S * 2] += cnt[S] / 2;
		ans += cnt[S] / 2;
		cnt[S] = cnt[S] % 2;
		s.erase(S);
	}
	cout << ans;
	return 0; 
}
