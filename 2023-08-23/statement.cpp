#include <bits/stdc++.h>

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define _rep(i, a, b) for (auto i = a;i >= b; i--)

using namespace std;

typedef long long ll;

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

int ans[10000005], T, L, R;
bitset <10000005> vis;

int main() {
	rep (i, 1, 1e7) {
		int t[10] = {0};
		int num = i, fNum = 0;
		while (num) {
			t[num % 10]++;
			num /= 10;
		}
		rep (i, 1, 9) {
			rep (j, 1, t[i]) {
				fNum *= 10;
				fNum += i;
			}
		}
		ans[i] = fNum;
	}
	read(T);
	while (T --> 0) {
		int res = 0;
		read(L), read(R);
		vis.reset();
		rep (i, L, R) {
			if (!vis[ans[i]]) vis[ans[i]] = 1, res++;
		}
		print(res), putchar(10);
	}
}
