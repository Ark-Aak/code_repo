#include <bits/stdc++.h>

#define eb emplace_back
#define ep emplace
#define fi first
#define se second
#define in read<int>()
#define lin read<ll>()
#define rep(i, x, y) for(int i = (x); i <= (y); i++)
#define per(i, x, y) for(int i = (x); i >= (y); i--)

using namespace std;

using ll = long long;
using db = double;
using pii = pair < int, int >;
using vec = vector < int >;
using veg = vector < pii >;

template < typename T > T read() {
	T x = 0; bool f = 0; char ch = getchar();
	while(!isdigit(ch)) f |= ch == '-', ch = getchar();
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

template < typename T > void chkmax(T &x, const T &y) { x = x > y ? x : y; }
template < typename T > void chkmin(T &x, const T &y) { x = x < y ? x : y; }

const int N = 1e6 + 10;

int n, a[N];
int lpos[N], rpos[N], stk[N], top;

int main() {
	freopen("mountain.in", "r", stdin); freopen("mountain.out", "w", stdout);
	n = in; rep(i, 1, n) a[i] = in;
	rep(i, 1, n) {
		while(top && a[i] > a[stk[top]]) rpos[stk[top]] = i, top--;
		if(a[stk[top]] == a[i]) lpos[i] = lpos[stk[top]];
		else lpos[i] = stk[top];
		rpos[i] = n + 1; stk[++top] = i;
	}
	rep(i, 1, n) printf("%d\n", rpos[i] - lpos[i] - 2);
	return 0;
}
