#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

priority_queue <double, vector <double>, greater <double> > q;
int n;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ave.in", "r", stdin);
	freopen("ave.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n) {
		int t; read(t);
		q.push(t);
	}
	while (q.size() > 1) {
		double a = q.top(); q.pop();
		double b = q.top(); q.pop();
		q.push((a + b) / 2.0);
	}
	printf("%.6lf", q.top());
	return 0;
}
