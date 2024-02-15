#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
using ll = long long;
int n,kk;ll m;
struct Knapsack
{
	vector<int> f;ll sum;int n;
	Knapsack(int x):f(x + 1),sum(0),n(x) {}
	void add(int x,int v)
	{ for (int i = n;i >= x;i--) if (f[i] < f[i - x] + v) sum -= f[i],f[i] = f[i - x] + v,sum += f[i]; }
};
int f[N],val[N],a[N],b[N];
inline bool in(int l,int r,int x) {return l <= x && x <= r;}
void solve(int l,int r,int ql,int qr,Knapsack v)
{
	if (l > r || ql > qr) return;
	if (ql < l) v.add(a[ql],val[ql]),++ql;
	int pos = (l + r) >> 1,ret = n + 1,lp = max(ql,pos),rp = qr,ptrl = pos,ptrr = qr;auto tt = v;
	for (int i = l;i < pos;i++) tt.add(a[i],val[i]);
	while (lp <= rp)
	{
		int mid = (lp + rp) >> 1;auto tmp = tt;
		for (int i = ptrl;i <= min(r,mid);i++) tmp.add(b[i],val[i]);
		for (int i = max({ptrl,r + 1,ql});i <= mid;i++) tmp.add(b[i],val[i]);
		for (int i = ptrr;i > mid;--i) tmp.add(a[i],val[i]);
		if (tmp.sum <= m)
		{
			ret = mid;rp = mid - 1;while (ptrr >= mid) tt.add(a[ptrr],val[ptrr]),--ptrr;
		}
		else
		{
			lp = mid + 1;
			while (ptrl <= min(r,mid)) tt.add(b[ptrl],val[ptrl]),++ptrl;
			if (ptrl == r + 1 && ptrl < ql) ptrl = ql;
			while (ptrl <= mid) tt.add(b[ptrl],val[ptrl]),++ptrl;
		}
	}
	f[pos] = ret;
	if (ret == n + 1)
	{
		for (int i = pos + 1;i <= r;i++) f[i] = n + 1;
		for (int i = min(ql - 1,r);i >= pos;--i) v.add(b[i],val[i]);
		solve(l,pos - 1,ql,qr,v);return;
	}
	Knapsack vl = v,vr = v;
	static bool vis[N];
	for (int i = l;i <= r;i++)
	{
		vis[i] = 1;
		if (!in(l,pos - 1,i) && !in(ql,ret,i)) vl.add(in(pos,ql - 1,i) ? b[i] : a[i],val[i]);
		if (!in(pos + 1,r,i) && !in(ret,qr,i)) vr.add(a[i],val[i]);
	}
	for (int i = ql;i <= qr;i++)
	{
		if (vis[i]) continue;
		if (!in(l,pos - 1,i) && !in(ql,ret,i)) vl.add(a[i],val[i]);
		if (!in(pos + 1,r,i) && !in(ret,qr,i)) vr.add(in(r + 1,ret - 1,i) ? b[i] : a[i],val[i]);
	}
	for (int i = l;i <= r;i++) vis[i] = 0;
	solve(l,pos - 1,ql,ret,vl);solve(pos + 1,r,ret,qr,vr);
}
int main ()
{
	freopen("roguetrader.in","r",stdin);
	freopen("roguetrader.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n >> kk >> m;m *= kk;
	for (int i = 1;i <= n;i++) cin >> a[i] >> b[i] >> val[i],
			assert(a[i] < b[i] && a[i] >= 1 && b[i] <= kk && val[i] <= 10000 && val[i] > 0);
	solve(1,n,1,n,Knapsack(kk));ll ans = 0;for (int i = 1;i <= n;i++) ans += n - f[i] + 1;
	cout << ans << endl;
	return 0;
}