#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int N = 1e5 + 5;

int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			w = -w;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		s = (s << 1) + (s << 3) + (ch ^ '0');
		ch = getchar();
	}
	return s * w;
}
char read_char()
{
	char ch = getchar();
	while (ch < 'a' || ch > 'z')
		ch = getchar();
	return ch;
}
int n, q, lst[N];
multiset<int> S;
char str[5];
struct Segment_tree
{
	int sum, res, pos;
} tr[N << 2];
namespace FW
{
	int laz, a[N];
	void init() { fill(a, a + q + 1, 0), laz = n; }
	void C(int x, int k)
	{
		if (!x)
			return laz += k, void();
		while (x <= q)
			a[x] += k, x += x & (-x);
	}
	int Q(int r)
	{
		int res = laz;
		while (r)
			res += a[r], r -= r & (-r);
		return res;
	}
}
namespace SGT
{
	void pushup(int rt)
	{
		Segment_tree &A = tr[rt << 1], &B = tr[rt << 1 | 1];
		tr[rt].sum = A.sum + B.sum;
		if (A.res < B.res + A.sum)
			tr[rt].res = A.res, tr[rt].pos = A.pos;
		else
			tr[rt].res = B.res + A.sum, tr[rt].pos = B.pos;
	}
	void build_tree(int l, int r, int rt)
	{
		if (l == r)
		{
			tr[rt].pos = l, tr[rt].sum = tr[rt].res = (l ? 0 : n);
			return;
		}
		int mid = (l + r) >> 1;
		build_tree(l, mid, rt << 1), build_tree(mid + 1, r, rt << 1 | 1), pushup(rt);
	}
	void change(int nl, int l, int r, int rt, int k)
	{
		if (l == r)
		{
			tr[rt].res += k, tr[rt].sum += k;
			return;
		}
		int mid = (l + r) >> 1;
		if (nl <= mid)
			change(nl, l, mid, rt << 1, k);
		else
			change(nl, mid + 1, r, rt << 1 | 1, k);
		pushup(rt);
	}
}
void getans_1()
{
	if (!tr[1].res) printf("%d ", FW::Q(tr[1].pos));
	else
		putchar('0'), putchar(' ');
}
void getans_2()
{
	int val = FW::Q(q);
	if (!S.empty())
		val -= FW::Q(*S.rbegin());
	printf("%d\n", val);
}
void work() { getans_1(), getans_2(); }
void solve()
{
	n = read(), q = read(), fill(lst, lst + n + 1, 0);
	S.clear(), SGT::build_tree(0, q, 1), FW::init();
	for (int i = 1; i <= q; i++)
	{
		scanf("%s", str);
		if (str[0] == 'a')
		{
			SGT::change(i, 0, q, 1, -1);
			if (tr[1].res < 0)
				puts("bug"), SGT::change(i, 0, q, 1, 1);
			else
				S.insert(i), work();
		}
		else
		{
			int x = read(), y = read();
			auto it = S.lower_bound(lst[x]);
			if (y && it == S.end())
			{
				puts("bug");
				continue;
			}
			SGT::change(lst[x], 0, q, 1, -1), SGT::change(i, 0, q, 1, 1);
			if (y)
				SGT::change(*it, 0, q, 1, 1);
			if (tr[1].res >= 0)
			{
				if (y)
					S.erase(it);
				FW::C(lst[x], -1), lst[x] = i, FW::C(i, 1), work();
			}
			else
			{
				puts("bug"), SGT::change(lst[x], 0, q, 1, 1), SGT::change(i, 0, q, 1, -1);
				if (y)
					SGT::change(*it, 0, q, 1, -1);
			}
		}
	}
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int T = read();
	while (T--)
		solve();
	return 0;
}