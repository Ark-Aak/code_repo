#include<bits/stdc++.h>
using namespace std;
const  int N = 500011,mod = 998244353;
typedef struct{
	int fa,s[2];
	bool rev;
	 int len,totl,sum,w,k,b;
}Tree;
Tree t[N];
long long V;
int idx;
 int Val(long long k,long long b,long long len)
{
	return (b * len + (len + mod - 1) * len % mod * (mod + 1) / 2 % mod * k) % mod;
}
void Add(int p,long long k,long long b)
{
	if(!p) return;
	t[p].k = (t[p].k + k) % mod,t[p].b = (t[p].b + b) % mod,t[p].sum = (t[p].sum + Val(k,b,t[p].totl % mod)) % mod,b = (b + k * t[t[p].s[0]].totl) % mod,t[p].w = (t[p].w + Val(k,b,t[p].len)) % mod;
}
void rev(int p)
{
	t[p].b = (t[p].b + t[p].k * (t[p].totl + mod - 1ll)) % mod,t[p].k = (mod - t[p].k) % mod;
	swap(t[p].s[0],t[p].s[1]);
	t[p].rev ^= 1;
}
void pushdown(int p)
{
	if(t[p].rev)
		rev(t[p].s[0]),rev(t[p].s[1]),t[p].rev = 0;
	Add(t[p].s[0],t[p].k,t[p].b),Add(t[p].s[1],t[p].k,(t[p].b + 1ll * t[p].k * (t[p].totl + mod - t[t[p].s[1]].totl)) % mod),t[p].k = t[p].b = 0;
}
void pushup(int p)
{
	t[p].totl = (t[t[p].s[0]].totl + t[p].len + t[t[p].s[1]].totl) % mod;
	t[p].sum = (t[t[p].s[0]].sum + t[p].w + t[t[p].s[1]].sum) % mod;
}
bool isroot(int x)
{
	return t[t[x].fa].s[0] != x && t[t[x].fa].s[1] != x;
}
void rotate(int x)
{
	int y = t[x].fa,z = t[y].fa;
	if(!isroot(y))
		t[z].s[t[z].s[1] == y] = x;
	t[x].fa = z;
	int k = (t[y].s[1] == x);
	t[t[y].s[k] = t[x].s[k ^ 1]].fa = y;
	t[t[x].s[k ^ 1] = y].fa = x;
	pushup(y),pushup(x);
}
int st[N];
void splay(int x)
{
	int top = 0,r = x;
	st[++top] = x;
	while(!isroot(r)) st[++top] = r = t[r].fa;
	while(top) pushdown(st[top--]);
	while(!isroot(x))
	{
		int y = t[x].fa,z = t[y].fa;
		if(!isroot(y))
		{
			if((t[y].s[1] == x) ^ (t[z].s[1] == y)) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}
int access(int x)
{
	int y = 0;
	for(int r = x;r;r = t[y = r].fa)
	{
		splay(r);
		t[r].s[1] = y,pushup(r);
	}
	splay(x);
	return y;
}
void makeroot(int x)
{
	access(x),rev(x);
}
void split(int x,int y)
{
	makeroot(x),access(y);
}
int LCA(int x,int y)
{
	makeroot(1),access(x);
	return access(y);
}
struct{
	short opt;
	int x,y,k;
}o[100011];
int u[300011],id,uid;
pair<long long,int> pl[300011];
int plcnt;
int Dp(long long p)
{
	return (*lower_bound(pl + 1,pl + plcnt + 1,make_pair(p,0))).second;
}
int n,q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	t[1] = {0,{0,0},0,1,1,1,1,0,0};
	for(int i = 2;i <= n;i++)
	{
		t[i] = {0,{0,0},0,1,1,0,0,0,0};
		cin >> t[i].fa;
		split(i,1),Add(1,0,1);
	}
	idx = plcnt = n;
	for(int i = 1;i <= n;i++)
		pl[i] = {i,i};
	for(int i = 1;i <= q;i++)
	{
		cin >> o[i].opt >> o[i].x;
		if(o[i].opt == 1) cin >> o[i].y >> o[i].k,o[i].k %= mod;
		else if(o[i].opt == 2) cin >> o[i].k;
		else cin >> o[i].y;
		if(o[i].x > n)
			u[++id] = o[i].x;
		if(o[i].y > n)
			u[++id] = o[i].y;
	}
	sort(u + 1,u + id + 1);
	V = n;
	for(int i = 1;i <= q;i++)
	{
		if(o[i].opt == 1)
		{
			int x = Dp(o[i].x),y = Dp(o[i].y),lca = LCA(x,y);
			 int sum = 0;
			split(x,lca),Add(lca,o[i].k,o[i].k),sum += t[lca].totl;
			split(y,lca),Add(lca,o[i].k,o[i].k),sum += t[lca].totl;
			split(lca,lca),Add(lca,0,mod - 1ll * sum * o[i].k % mod),sum += mod - 1;
			split(1,lca),Add(lca,0,1ll * sum * o[i].k % mod);
		}else if(o[i].opt == 2)
		{
			int p = Dp(o[i].x);
			split(1,p);
			int b = o[i].k;
			Add(p,0,b);
			long long R = V + b;
			int lp = p;
			while(uid < id && u[uid + 1] <= R)
			{
				uid++;
				 int w,len;
				if(V < u[uid] - 1)
					len = (u[uid] - V - 1) % mod,w = Val(mod - 1,b,len),t[++idx] = {lp,{0,0},0,len,len,w,w,0,0},lp = idx,V = u[uid] - 1,b = R - V;
				if(V < u[uid])
					w = b,t[++idx] = {lp,{0,0},0,1,1,w,w,0,0},lp = idx,b--,pl[++plcnt] = {++V,idx};
			}
			V = R;
		}else{
			int x = Dp(o[i].x),y = Dp(o[i].y);
			split(x,y);
			cout << t[y].sum << "\n";
		}
	}
	return 0;
}
