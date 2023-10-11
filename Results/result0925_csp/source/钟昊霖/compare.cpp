#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i, a, b) for (int i = a; i <= b; i++)
#define R(i, a, b) for (int i = a; i >= b; i--)

#define mk(a, b) make_pair(a, b)
#define inv(x) ksm(x, Mod - 2)
#define mem(a, b) memset(a, b, sizeof a)

#define De(x) cerr << "------------------" << x << "--------------" << endl
#define Debug() cerr << "----------------------------------------" << endl
#define lson(x) x << 1
#define rson(x) x << 1 | 1

const int N = 2e5 + 5, TN = 1e6 + 5, Mod = 998244353, inf = INT_MAX, Inf = LONG_LONG_MAX;
inline int ksm(int a, int b);
inline int read();
string s;
int T = 1, ans = 0, n, m, a[N];

signed main()
{
	//freopen(".in","r",stdin);freopen(".out","w",stdout);
	while (T--)
	{
		system("fc game.out game3.ans");
	}
	return 0;
}
inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f *= -1;
		c = getchar();
	}
	while (c <= '9' && c >= '0')
	{
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline int ksm(int a, int b)
{
	int aa = 1;
	while (b)
	{
		if (b & 1)
			aa *= a, aa %= Mod;
		a *= a;
		a %= Mod;
		b >>= 1;
	}
	return aa;
}
