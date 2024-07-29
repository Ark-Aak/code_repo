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

string s;

string calc(string s) {
	vector <pii> v;
	int cnt = 0, id = 0;
	for (auto c : s) {
		id++;
		v.push_back(dl(cnt, id));
		if (c == '(') cnt++;
		else cnt--;
	}
	sort(v.begin(), v.end(), [](pii a, pii b) {
		return a.ec == b.ec ? a.fb > b.fb : a.ec < b.ec;
	});
	string res = "";
	for (auto [ignore, id] : v) res += s[id - 1];
	return res;
}

int main() {
	cin >> s;
	string nx = calc(s);
	while (calc(nx) != s) nx = calc(nx);
	cout << nx << endl;
}
