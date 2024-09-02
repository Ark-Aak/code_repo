#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

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

int n;
string s1, s2;
const int MAXN = 1e6 + 5;

inline int change(int x, int val, int o) {
	int p = n - x;
	int tp = o >> p & 1;
	return o - tp * (1 << p);
}

inline int inv(int x, int o) {
	int p = n - x;
	int tp = o >> p & 1;
	if (tp) tp = -1;
	else tp = 1;
	return o + tp * (1 << p);
}

namespace subtask1 {

	int s[1 << 19];

	void bfs(string st) {
		int r = 0;
		for (auto c : st) {
			if (c == ' ') continue;
			r <<= 1;
			r |= c - '0';
		}
		queue <int> q;
		q.push(r);
		while (!q.empty()) {
			int res = q.front();
			q.pop();
			const int val = s[res];
			// if (s[res] > n / 2 + 1) break;
			rep (op, 1, 3) {
				rep (l, 1, n) {
					int str = res;
					rep (r, l, n) {
						if (op == 1) {
							str = change(r, 1, str);
						}
						else if (op == 2){
							str = change(r, 0, str);
						}
						else {
							str = inv(r, str);
						}
						if (s[str]) continue;
						s[str] = val + 1;
						q.push(str);
					}
				}
			}
		}
	}
} // namespace subtask1

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("hard.in", "r", stdin);
    freopen("hard.out", "w", stdout);
#endif
#endif
    cin >> n;
    cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    if (n <= 18) {
		subtask1::bfs(s1);
		int r = 0;
		for (auto c : s2) {
			if (c == ' ') continue;
			r <<= 1;
			r |= c - '0';
		}
		cout << subtask1::s[r] << endl;
		return 0;
	}
	else {
		int cnt[2] = { 0 }, lst = -1;
		for (auto c : s2) {
			if (c == ' ') continue;
			int p = c - 48;
			if (p != lst) {
				if (~lst) cnt[lst]++;
				lst = p;
			}
		}
		cnt[lst]++;
		cout << cnt[0] << endl;
	}
	return 0;
}
