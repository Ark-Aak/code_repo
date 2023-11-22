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

const int MAXN 5e5 + 5;
int euler_order[MAXN];

void dfs(int u, int fa) {
	euler_order[++euler_order[0]] = u;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
		euler_order[++euler_order[0]] = u;
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("young.in", "r", stdin);
	freopen("young.out", "w", stdout);
#endif
#endif
	
	return 0;
}