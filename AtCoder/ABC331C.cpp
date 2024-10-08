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

#define int ll

priority_queue <int, vector <int>, greater <int> > q;

int n, a[2000005];
int ans[2000005], sum;

signed main() {
	cin >> n;
	memset(ans, 0x3f, sizeof ans);
	rep (i, 1, n) {
		cin >> a[i];
		q.push(a[i]); sum += a[i];
	}
	while (q.size()) {
		sum -= q.top();
		ans[q.top()] = min(ans[q.top()], sum);
		q.pop();
	}
	rep (i, 1, n) cout << ans[a[i]] << " ";
	return 0;
}
