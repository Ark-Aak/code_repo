#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <immintrin.h>
#include <emmintrin.h>

#include <bits/stdc++.h>
#define ll long long
#define rg register
#define il inline
using namespace std;
namespace IO
{
	char buff[1 << 21], *p1 = buff, *p2 = buff;
	il char getch()
	{
		return p1 == p2 && (p2 = ((p1 = buff) + fread(buff, 1, 1 << 21, stdin)), p1 == p2) ? EOF : *p1++;
	}
	template <typename T>
	il void read(T &x)
	{
		rg char ch = getch();
		rg int fl = 1;
		x = 0;
		while (ch > '9' || ch < '0')
		{
			if (ch == '-')
				fl = -1;
			ch = getch();
		}
		while (ch <= '9' && ch >= '0')
		{
			x = x * 10 + ch - 48;
			ch = getch();
		}
		x *= fl;
	}
	template <typename T, typename... Args>
	il void read(T &x, Args &...args)
	{
		read(x);
		read(args...);
	}
	char obuf[1 << 21], *p3 = obuf;
	il void putch(char ch)
	{
		if (p3 - obuf < (1 << 21))
			*p3++ = ch;
		else
			fwrite(obuf, p3 - obuf, 1, stdout), p3 = obuf, *p3++ = ch;
	}
	char ch[100];
	template <typename T>
	il void write(T x)
	{
		if (!x)
			return putch('0');
		if (x < 0)
			putch('-'), x *= -1;
		rg int top = 0;
		while (x)
			ch[++top] = x % 10 + 48, x /= 10;
		while (top)
			putch(ch[top]), top--;
	}
	template <typename T, typename... Args>
	il void write(T x, Args... args)
	{
		write(x);
		write(args...);
	}
	il void flush() { fwrite(obuf, p3 - obuf, 1, stdout); }
}
using namespace IO;
int n, V, X;
int a[200005], b[200005], c[200005];
int ans[200005];
int f[200005];
il void sol(int L, int R, int qL, int qR)
{
	if (qL > qR)
		return;
	if (L == R)
	{
		for (rg int i = qL; i <= qR; i++)
			ans[i] = L;
		cout << qL << " ~ " << qR << " = " << L << endl;
		return;
	}
	rg int g[200005], h[200005];
	for (rg int i = 0; i <= V; i++)
		h[i] = f[i];
	rg int x = ((qL + qR) >> 1);
	for (rg int i = qL; i < x; i++)
		for (rg int j = V; j >= a[i]; j--)
			h[j] = max(h[j], h[j - a[i]] + c[i]);
	for (rg int i = x; i < L; i++)
		for (rg int j = V; j >= b[i]; j--)
			h[j] = max(h[j], h[j - b[i]] + c[i]);
	rg int Now_l = max(L, x) - 1, Now_r = R + 1;
	rg int _l = max(L, x), _r = R;
	while (_l < _r)
	{
		rg int mid = ((_l + _r) >> 1);
		for (rg int i = 0; i <= V; i++)
			g[i] = h[i];
		for (rg int i = _l; i <= mid; i++)
			for (rg int j = V; j >= b[i]; j--)
				g[j] = max(g[j], g[j - b[i]] + c[i]);
		for (rg int i = mid + 1; i <= _r; i++)
			for (rg int j = V; j >= a[i]; j--)
				g[j] = max(g[j], g[j - a[i]] + c[i]);
		rg ll sum = 0;
		for (rg int i = 1; i <= V; i++)
			sum += g[i];
		if (sum <= 1ll * X * V)
			_r = mid;
		else
			_l = mid + 1;
		while (Now_r - 1 > _r)
		{
			Now_r--;
			for (rg int j = V; j >= a[Now_r]; j--)
				h[j] = max(h[j], h[j - a[Now_r]] + c[Now_r]);
		}
		while (Now_l + 1 < _l)
		{
			Now_l++;
			for (rg int j = V; j >= b[Now_l]; j--)
				h[j] = max(h[j], h[j - b[Now_l]] + c[Now_l]);
		}
	}
	ans[x] = _l;
	cout << x << " = " << _l << endl;
	for (rg int i = 0; i <= V; i++)
		g[i] = f[i];
	for (rg int i = R; i > _l; i--)
		for (rg int j = V; j >= a[i]; j--)
			f[j] = max(f[j], f[j - a[i]] + c[i]);
	sol(L, _l, qL, x - 1);
	for (rg int i = 0; i <= V; i++)
		f[i] = g[i];
	for (rg int i = qL; i <= x; i++)
		for (rg int j = V; j >= a[i]; j--)
			f[j] = max(f[j], f[j - a[i]] + c[i]);
	sol(max(_l, x + 1), R, x + 1, qR);
}
signed main()
{
	read(n, V, X);
	for (rg int i = 1; i <= n; i++)
		read(a[i], b[i], c[i]), ans[i] = n + 1;
	sol(1, n + 1, 1, n);
	rg ll sum = 0;
	for (rg int i = 1; i <= n; i++)
		sum += n - ans[i] + 1;
	write(sum);
	//	assert(cnt <= 4e8);
	flush();
	return 0;
}
