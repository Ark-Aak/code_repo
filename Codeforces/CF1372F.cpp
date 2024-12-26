#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

pii ask(int l, int r) {
	cout << "? " << l << " " << r << endl;
	int x, y;
	cin >> x >> y;
	return dl(x, y);
}

void solve(int l, int r) {
	if (l > r) return;
	pii res = ask(l, r);

}

signed main() {

	return 0;
}
