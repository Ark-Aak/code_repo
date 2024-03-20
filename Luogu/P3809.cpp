#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

string str;

int sa[1000005], rk[1000005], oldrk[1000005], id[1000005], cnt[1000005];
int key1[1000005];

bool cmp(int x, int y, int w) {
	return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m = 127, p = 0, i = 0;
	cin >> str;
	n = str.size();
	str = " " + str;
	rep (i, 1, n) ++cnt[rk[i] = str[i]];
	rep (i, 1, m) cnt[i] += cnt[i - 1];
	_rep (i, n, 1) sa[cnt[rk[i]]--] = i;
	for (int w = 1;; w <<= 1, m = p) {
	}
	rep (i, 1, n) cout << sa[i] << " ";
	return 0;
}
