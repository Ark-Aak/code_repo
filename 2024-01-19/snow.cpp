#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-')
			f = -1;
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
	if (x < 0)
		x = (~x + 1), putchar('-');
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e7 + 5;

int a1, b1, a2, b2, n, q;
int pos[MAXN], m, len[MAXN], cnt;
bool num1[MAXN], num2[MAXN], num3[MAXN], num4[MAXN];
int _pos[MAXN], _len[MAXN], cnt2, sum[MAXN], _sum[MAXN];

signed main() {
	a1 = read(), b1 = read(), a2 = read(), b2 = read(), n = read();
	rep (i, 0, a1 + b1 - 1) pos[++m] = (a2 + b2) * i + a2, pos[++m] = (a2 + b2) * (i + 1);
	rep (i, 0, a2 + b2 - 1) pos[++m] = (a1 + b1) * i + a1, pos[++m] = (a1 + b1) * (i + 1);
	sort(pos + 1, pos + m + 1);
	m = unique(pos + 1, pos + m + 1) - pos - 1;
	num1[0] = 1, num2[0] = 1;
	int now = 0;
	int op1 = 1, op2 = 1;
	rep (i, 1, m) {
		len[++cnt] = pos[i] - pos[i - 1];
		num1[cnt] = op1; num2[cnt] = op2;
		if (pos[i] % (a1 + b1) == a1 || pos[i] % (a1 + b1) == 0) op1 ^= 1;
		if (pos[i] % (a2 + b2) == a2 || pos[i] % (a2 + b2) == 0) op2 ^= 1;
		now += num1[cnt] * len[cnt] - num2[cnt] * len[cnt];
		if (now < 0) {
			len[cnt] += now;
			if (!len[cnt]) cnt--;
			len[++cnt] = -now;
			num1[cnt] = 0, num2[cnt] = 0;
			now = 0;
		}
	}
	rep (i, 1, m) {
		_len[++cnt2] = pos[i] - pos[i - 1];
		num3[cnt2] = op1;
		num4[cnt2] = op2;
		if (pos[i] % (a1 + b1) == a1 || pos[i] % (a1 + b1) == 0) op1 ^= 1;
		if (pos[i] % (a2 + b2) == a2 || pos[i] % (a2 + b2) == 0) op2 ^= 1;
		now += num3[cnt2] * _len[cnt2] - num4[cnt2] * _len[cnt2];
		if (now < 0) {
			_len[cnt2] += now;
			if (!_len[cnt2]) cnt2--;
			_len[++cnt2] = -now;
			num3[cnt2] = 0, num4[cnt2] = 0;
			now = 0;
		}
	}
	rep (i, 1, cnt) sum[i] = sum[i - 1] + len[i] * num2[i], pos[i] = pos[i - 1] + len[i];
	rep (i, 1, cnt2) _sum[i] = _sum[i - 1] + _len[i] * num4[i], _pos[i] = _pos[i - 1] + _len[i];
	while (n --> 0) {
		int p = read(), ans = 0;
		if (p <= pos[cnt]) {
			int s = upper_bound(pos + 1, pos + cnt + 1, p) - pos - 1;
			ans += sum[s];
			if (num2[s + 1]) ans += (p - pos[s]);
		}
		else {
			ans += sum[cnt];
			p -= pos[cnt];
			ans += (_sum[cnt2] * (p / _pos[cnt2]));
			p %= _pos[cnt2];
			int s = upper_bound(_pos + 1, _pos + cnt2 + 1, p) - _pos - 1;
			ans += _sum[s];
			if (num4[s + 1]) ans += (p - _pos[s]);
		}
		print(ans), putchar(10);
	}
	return 0;
}