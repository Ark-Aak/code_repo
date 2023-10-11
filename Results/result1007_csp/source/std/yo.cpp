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
const int T = 11;

int n;
char s[N], t[N];
bool f[N][11];

int main() {
    freopen("yo.in", "r", stdin), freopen("yo.out", "w", stdout);
	n = in; scanf("%s", s + 1), scanf("%s", t + 1);
	f[n + 1][0] = true;
	per(i, n, 1) 
		if(t[i] == 'y') {
			rep(j, 0, T - 1) 
				f[i][j] = f[i + 1][(j * 10 + s[i] - '0') % T] | f[i + 1][(j * 10) % T];
		} else {
			rep(j, 0, T - 1)
				f[i][j] = f[i + 1][(j * 10 + s[i] - '0') % T] & f[i + 1][(j * 10) % T];
		}
	if(f[1][0]) puts("yoimiya");
	else puts("oimiya");
	return 0;
}
