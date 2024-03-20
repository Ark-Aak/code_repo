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

const int MAXN = 2e5 + 5;
int n, c, h[MAXN], f[MAXN];
int head, tail, q[MAXN];

double F(int x) {
	return f[x] + h[x] * h[x];
}

double slope(int x, int y) {
	return (F(x) - F(y)) / ((double) h[x] - (double) h[y]);
}

signed main() {
	n = read(), c = read();
	rep(i, 1, n) h[i] = read();
	q[head = tail = 1] = 1;
	rep(i, 2, n) {
		while (head < tail && slope(q[head], q[head + 1]) < 2 * h[i]) head++;
		int j = q[head]; f[i] = f[j] + (h[i] - h[j]) * (h[i] - h[j]) + c;
		while (head < tail && slope(q[tail - 1], q[tail]) > slope(q[tail], i)) tail--;
		q[++tail] = i;
	}
	print(f[n]);
	return 0;
}
