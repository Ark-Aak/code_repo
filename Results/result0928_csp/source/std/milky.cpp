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
using uint = unsigned int;

template < typename T > T read() {
	T x = 0; bool f = 0; char ch = getchar();
	while(!isdigit(ch)) f |= ch == '-', ch = getchar();
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

template < typename T > void chkmax(T &x, const T &y) { x = x > y ? x : y; }
template < typename T > void chkmin(T &x, const T &y) { x = x < y ? x : y; }

const int N = 1e6 + 10;
const char ts[] = "milky";

template < typename T >	struct mat {
	T res[6][6];
	mat() { memset(res, 0, sizeof res); }
	uint* operator [](int x) { return res[x]; }
	friend mat operator * (mat x, mat y) {
		mat z; 
		rep(i, 0, 5) rep(j, 0, 5) if(x[i][j]) rep(k, 0, 5) z[i][k] += x[i][j] * y[j][k];
		return z;
	}
};

mat < uint > s[N], is[N];

char T[N];
int Q, n;
int ind[256];

int main() {
	freopen("milky.in", "r", stdin); freopen("milky.out", "w", stdout);
	scanf("%s", T + 1); n = strlen(T + 1);
	mat < uint > I; rep(i, 0, 5) I[i][i] = 1;
	rep(i, 0, 4) ind[ts[i]] = i + 1;
	s[0] = is[0] = I;
	rep(i, 1, n) {
		auto a = I; a[ind[T[i]] - 1][ind[T[i]]] = 1;
		s[i] = s[i - 1] * a;
		a = I, a[ind[T[i]] - 1][ind[T[i]]] = -1;
		is[i] = a * is[i - 1];
	}
	Q = in;
	while(Q--) {
		int l = in, r = in;
		auto t = is[l - 1] * s[r];
		printf("%u\n", t[0][5]);
	}
	return 0;
}
