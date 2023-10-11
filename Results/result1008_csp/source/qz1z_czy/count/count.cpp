//#pragma GCC optimize(2)
#include<bits/stdc++.h>
//#include<cmath>
#define Sig signed
#define uSig unsigned
typedef long long ll;
#define int ll
//#define double long double
#define Fix fixed
#define Spcs(x) setprecision(x)
#define Il inline
#define pii pair<int,int>
#define re register
#define Mul multiset
#define Vt vector
#define Stk stack
#define Que queue
#define Itt iterator
#define PQ priority_queue
#define umap unordered_map
#define uset unordered_set
#define mpr make_pair
#define ft first
#define sd second
#define pb push_back
#define Bset bitset
#define Ins insert
#define Ers erase
#define Clr clear
#define lowbit(x) x&(-x)
#define Mset(x,y) memset(x,y,sizeof x)
#define Mcpy(x,y) memcpy(x,y,sizeof y)
#define Unq unique
#define rp(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define lp(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define rpt(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define lpt(i,a,b) for(int (i)=(a);(i)>(b);(i)--)
using namespace std;
//--------------------------------------------------------------------
const int M=1e5+10,N=5e3+10;
//--------------------------------------------------------------------
Il int read()
{
	int p=0,q=1;
	char ch=getchar();
	while(!isdigit(ch)) q=(ch=='-')?-1:1,ch=getchar();
	while(isdigit(ch)) p=(p<<3)+(p<<1)+(ch^48),ch=getchar();
	return p*q;
}
//--------------------------------------------------------------------
int mod=998244353;
int n,m;
int a[M<<1];
int c[N<<1];
int ans;
int l[M<<1];
//--------------------------------------------------------------------
void dfs(int step)
{
	if(step==n+1)
	{
		
		ans++;
		if(ans>=mod)
			ans-=mod;
//		rp(i,1,n) printf("%d ",c[i]);
//		puts("");
		return;
	}
	rp(i,1,m)
	{
		int s=0;
		for(int j=step-1;j>=step-l[i];j--) if(c[j]==a[i]) s++;
		if(s==l[i]) continue;
		c[step]=a[i];
		dfs(step+1);
	}
}
Sig main(void)
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	n=read(),m=read();
	rp(i,1,m) a[i]=read();
	rp(i,1,m) l[i]=a[a[i]];
	dfs(1);
	printf("%d",ans);
	return 0;
}
