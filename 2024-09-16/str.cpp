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

int T;
string s;
int n;

inline string work(string &s) {
	unordered_map <char, int> id;
	int cnt = 25;
	string res;
	for (auto ch : s) {
		if (id.find(ch) == id.end()) id[ch] = cnt--;
		res += 'a' + id[ch];
	}
	return res;
}

const int MAXN = 1e5 + 5;
const int BASE = 131;
const int MOD = 1e9 + 7;

int hsh[MAXN];

void solve() {
	cin >> s;

}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("str.in", "r", stdin);
	freopen("str.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T --> 0) solve();
	return 0;
}
