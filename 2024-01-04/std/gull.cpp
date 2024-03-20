#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<set>
using namespace std;

#define bomb exit(1)
#define INF 1061109567
#define LINF 4557430888798830399ll
#define pprint(x) ::print(x),putchar(' ')
#define fprint(x) ::print(x),putchar('\n')
#define EE(x); struct edge { int nxt,to,w; }e[M << 1]; int head[N],ecnt = 1;\
	void add(int u,int v,int w = 0) { e[++ecnt] = {head[u],v,w},head[u] = ecnt; }\
	void add_edge(int u,int v,int w = 0) { add(u,v,w),add(v,u,w * x);}
#define ll long long
//#define C const
#define iter iterator
const double pi = acos(-1.0);
const int mod = 998244353;
void reduce(int &a) { a += a >> 31 & mod; }
int Mod(int x) { return x >= mod ? x - mod : x; }
//#define eps 0.00000001
#define fi first
#define se second
//#define getchar() (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
//char BB[1 << 15],*SS = BB,*TT = BB;
ll read()
{
	ll x = 0;int f = 1;char ch = getchar();
	for(;!isdigit(ch);ch = getchar()) if(ch == '-') f = -1;
	for(;isdigit(ch);ch = getchar()) x = x * 10 + (ch ^ 48);
	return x * f;
}
void print(ll x)
{
	if(x < 0) putchar('-'),x = -x;
	if(x > 9) print(x / 10);putchar(x % 10 + '0');
}
const int N = 5010;
int qpow(int a,int b)
{
	int ans = 1;
	for(;b;b >>= 1,a = (ll)a * a % mod) if(b & 1) ans = (ll)ans * a % mod;
	return ans;
}
int n;struct seq { int n,m,k,C,id,ans; }a[N];
struct query { int n,id; }q1[N],q2[N << 1];int cnt;
bool cmp(query u,query v) { return u.n < v.n; }
int b[N],inv[N],v[N];
int main()
{
	freopen("gull.in","r",stdin);freopen("gull.out","w",stdout);
	cnt = n = read();
	for(int i = 1;i <= n;i++)
	{
		a[i].n = read(),a[i].m = read(),a[i].k = read(),a[i].C = 1,a[i].id = i;
		q1[i].n = a[i].n,q2[i].n = a[i].m,q1[i].id = q2[i].id = i;
		if(a[i].n != a[i].m) q2[++cnt].n = a[i].n - a[i].m,q2[cnt].id = i;
	}
	sort(q1 + 1,q1 + 1 + n,cmp),sort(q2 + n,q2 + 1 + cnt,cmp);
	int fac = 1,m = 10000000,now = 1;
	for(int i = 1;i <= m;i++)
	{
		fac = (ll)fac * i % mod;
		while(q1[now].n == i && now <= n)
			a[q1[now].id].C = (ll)a[q1[now].id].C * fac % mod,now++;
	}
	fac = qpow(fac,mod - 2),now = 1;
	for(int i = m;i;i--)
	{
		while(q1[now].n == i && now <= cnt)
			a[q2[now].id].C = (ll)a[q2[now].id].C * fac % mod,now++;
		fac = (ll)fac * i % mod;
	}
	sort(a + 1,a + 1 + n,[&](seq u,seq v) { return u.k < v.k; });
	b[0] = 1;now = 1;while(!a[now].k && now <= n) a[now].ans = 1,now++;
	for(int i = 1;i <= 5000;i++)
	{
		for(int j = i - 1;~j;j--)
			reduce(b[j + 1] += b[j] - mod),b[j] = (ll)b[j] * (mod - j) % mod;
		while(a[now].k == i && now <= n)
		{
			int n = a[now].n,m = a[now].m,k = a[now].k,C = a[now].C;
			int res = 1,ans = 0;
			v[0] = 1;for(int j = 1;j <= k;j++) v[j] = (ll)v[j - 1] * (m + j) % mod;
			inv[k] = qpow(v[k],mod - 2);
			for(int j = k;j;j--) inv[j - 1] = (ll)inv[j] * (m + j) % mod;
			for(int j = 1;j <= k;j++)
			{
				C = (ll)C * (n + j) % mod * inv[j] % mod * v[j - 1] % mod;
				res = (ll)res * (m + j - 1) % mod;
				ans = (ans + (ll)b[j] * res % mod * C) % mod;
			}
			a[now].ans = (ll)ans * qpow(a[now].C,mod - 2) % mod;
			now++;
		}
	}
	sort(a + 1,a + 1 + n,[&](seq u,seq v) { return u.id < v.id; });
	for(int i = 1;i <= n;i++) fprint(a[i].ans);
}