#include <bits/stdc++.h>

#define int ll

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

int n, a, b;
string s;
stack <char> stk;

signed main() {
	cin >> n >> a >> b;
	cin >> s;
	int ans = 0;
	for (auto c : s) {
		if (!stk.size()) stk.push(c);
		else {
			if (c == '(') {
				stk.push(c);
			}
			else {
				if (stk.size() && stk.top() == '(') stk.pop();
				else stk.push(c);
			}
		}
	}
	vector <char> r;
	while (stk.size()) r.push_back(stk.top()), stk.pop();
	reverse(r.begin(), r.end());
	int cntr = 0;
	rep (i, 0, r.size() - 1) cntr += r[i] == ')';
	int cntl = r.size() - cntr;
	if (cntl < cntr) swap(cntl, cntr);
	if (2 * b < a) {
		ans += cntr / 2 * b;
		ans += cntl / 2 * b;
		cntl %= 2, cntr %= 2;
		if (cntl < cntr) swap(cntl, cntr);
		ans += cntr * 2 * b + (cntl - cntr) * b / 2;
	}
	else {
		ans += ceil(1.0 * cntr / 2) * a + (cntl - cntr) * b / 2;
	}
	print(ans);
	return 0;
}
