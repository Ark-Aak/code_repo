#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef __int128 i128;
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

const int MAXN = 5e5 + 5;
int T, n;
string str;

namespace subtask1 {

	int q;
	set <tuple <int, int> > s, t;
	int ans[MAXN];

	void solve() {
		cin >> q;
		int tq = q;
		while (q --> 0) {
			s.clear(), t.clear();
			int l, r;
			cin >> l >> r;
			int lst = l;
			rep (i, l + 1, r) {
				if (str[i] != str[i - 1]) {
					s.insert(dk(lst - l + 1, i - lst));
					t.insert(dk(i - lst, lst - l + 1));
					lst = i;
				}
			}
			s.insert(dk(lst - l + 1, r - lst + 1));
			t.insert(dk(r - lst + 1, lst - l + 1));
			int k;
			cin >> k;
			int ans = 0, rd = 0;
			while (t.size() && k >= get<0>(*t.begin()) - rd) {
				int val = get<0>(*t.begin()) - rd;
				int cnt = 0;
				ans += s.size() * val;
				rd += val;
				while (t.size() && get<0>(*t.begin()) - rd == 0) {
					cnt++;
					auto it = s.lower_bound(dk(get<1>(*t.begin()), get<0>(*t.begin())));
					if (it != s.begin() && next(it) != s.end()) {
						auto pit = prev(it);
						auto nit = next(it);
						int np = get<0>(*pit);
						int nv = get<1>(*pit) + get<1>(*nit) - rd;
						auto tpit = t.lower_bound(dk(get<1>(*pit), get<0>(*pit)));
						auto tnit = t.lower_bound(dk(get<1>(*nit), get<0>(*nit)));
						t.erase(tpit), t.erase(tnit);
						s.erase(nit), s.erase(pit);
						if (nv > 0) s.insert(dk(np, nv));
						if (nv > 0) t.insert(dk(nv, np));
					}
					s.erase(it);
					t.erase(t.begin());
				}
				k -= val;
			}
			ans += s.size() * k;
			subtask1::ans[tq - q] = r - l + 1 - ans;
		}
		rep (i, 1, tq) cout << ans[i] << " ";
		cout << endl;
	}
} // namespace subtask1

void solve() {
	cin >> n >> str;
	str = ' ' + str;
	if (str.find('H') == string::npos) {
		map <int, int> ans;
		int q;
		cin >> q;
		int tq = q;
		while (q --> 0) {
			int l, r, k;
			cin >> l >> r >> k;
			ans[tq - q] = max(r - l + 1 - k, 0);
		}
		rep (i, 1, tq) cout << ans[i] << " " ;
		cout << endl;
	}
	else if (n <= 5000) return subtask1::solve();
	else {
		int sp = 0;
		rep (i, 1, n - 1) if (str[i] != str[i + 1]) sp = i;
		int q;
		cin >> q;
		int tq = q;
		map <int, int> ans;
		while (q --> 0) {
			int l, r, k;
			cin >> l >> r >> k;
			int lenL = min(r - l + 1, max(0, sp - l + 1));
			int lenH = r - l + 1 - lenL;
			int minn = min(lenL, lenH);
			int len = r - l + 1;
			if (k <= minn) ans[tq - q] = max(0, len - 2 * k);
			else ans[tq - q] = max(0, len - 2 * minn - (k - minn));
		}
		rep (i, 1, tq) cout << ans[i] << " ";
		cout << endl;
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T --> 0) solve();
	return 0;
}
/*
1
9
LHHLLHHHL
7
2 5 1
3 6 1
4 8 2
2 7 1
1 9 1
1 9 0
1 9 8
*/
