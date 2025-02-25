#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 5e5 + 5;
int n;
string s;
map <pair <int, int>, int> ma;

signed main() {
	cin >> n;
    cin >> s;
	s = " " + s;
    int pre = 0, suf = 0, num = 0, Ans = 1e18, sum = 0;
    rep (i, 1, n) suf += i * (s[i] == '1'), sum += (s[i] == '1');
	rep (i, 1, n) {
		num += (s[i] == '1');
		suf -= i * (s[i] == '1');
		pre += i * (s[i] == '1');
        if (s[i] == '1') {
            Ans = min(Ans, ((i - num + 1 + i) * (num) / 2) - pre + suf
					- ((sum - num + i + i + 1) * (sum - num) / 2));
        }
    }
	cout << Ans << endl;
    return 0;
}
