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

const int N = 1e6 + 5;
char s[N];
int qzh[N];
signed main() {
	int T = read();
	while (T--) {
		int n = read();
		scanf("%s", s + 1);
		int p = 0, ans = 0, sum = 0;
		rep(i, 1, n - 3) {
			if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'P' && s[i + 3] == 'C') sum++;
		}
		int B = sqrt(n) + 100;
		rep(T, 1, B) {
			ans = max(ans, sum - p);
			if (sum - p < -3) break;
			p += T - 1;
			int t = 0, pp = 0;
			rep(i, 1, n) {
				int res = 0;
				if (i > 2 && s[i - 2] == 'C' && s[i - 1] == 'C' && s[i] == 'P') res++;
				if (i > 2 && s[i - 2] == 'C' && s[i - 1] == 'C' && s[i] == 'P' && s[i + 1] == 'C') res--;
				if (i > 1 && s[i - 1] == 'C' && s[i] == 'C' && s[i + 1] == 'P' && s[i + 2] == 'C') res--;
				if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'P' && s[i + 3] == 'C') res--;
				if (s[i] == 'C' && s[i + 1] == 'P' && s[i + 2] == 'C') res++;
				if (s[i + 1] == 'C' && s[i + 2] == 'P' && s[i + 3] == 'C') res++;
				if (res > t) {
					t = res;
					pp = i;
				}
				res = 0;
				if (i > 1 && s[i - 1] == 'C' && s[i] == 'C' && s[i + 1] == 'C') res++;
				if (i > 2 && s[i - 2] == 'C' && s[i - 1] == 'C' && s[i] == 'P' && s[i + 1] == 'C') res--;
				if (i > 1 && s[i - 1] == 'C' && s[i] == 'C' && s[i + 1] == 'P' && s[i + 2] == 'C') res--;
				if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'P' && s[i + 3] == 'C') res--;
				if (res > t) {
					t = res;
					pp = i;
				}
			}
			if (!pp) break;
			int res = 0;
			int i = pp;
			if (i > 2 && s[i - 2] == 'C' && s[i - 1] == 'C' && s[i] == 'P') res++;
			if (i > 2 && s[i - 2] == 'C' && s[i - 1] == 'C' && s[i] == 'P' && s[i + 1] == 'C') res--;
			if (i > 1 && s[i - 1] == 'C' && s[i] == 'C' && s[i + 1] == 'P' && s[i + 2] == 'C') res--;
			if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'P' && s[i + 3] == 'C') res--;
			if (s[i] == 'C' && s[i + 1] == 'P' && s[i + 2] == 'C') res++;
			if (s[i + 1] == 'C' && s[i + 2] == 'P' && s[i + 3] == 'C') res++;
			if (res == t) {
				sum += res;
				_rep(j, n, i + 1) s[j + 1] = s[j];
				n++;
				s[i + 1] = 'C';
				continue;
			}
			sum += t;
			_rep(j, n, i + 1) s[j + 1] = s[j];
			n++;
			s[i + 1] = 'P';
		}
		printf("%lld\n", ans);
	}
	return 0;
}
