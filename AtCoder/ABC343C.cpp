#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

int stk[1000005], top;

signed main() {
	int n = read();
	int ans = 0;
	for (int i = 1; i * i * i <= n; i++) {
		top = 0;
		int ti = i * i * i;
		while (ti) stk[++top] = ti % 10, ti /= 10;
		bool flag = 1;
		rep (j, 1, top >> 1) if (stk[j] != stk[top - j + 1]) { flag = 0; break; }
		if (!flag) continue;
		ans = max(ans, i * i * i);
	}
	print(ans);
	return 0;
}
