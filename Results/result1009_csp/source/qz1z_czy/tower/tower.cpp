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
const int N=5e4+10,K=60;
//--------------------------------------------------------------------
Il int read()
{
	int p=0, q=1;
	char ch=getchar();
	while (!isdigit(ch)) q=(ch=='-')?-1:1,ch=getchar();
	while (isdigit(ch)) p=(p<<3)+(p<<1)+(ch^48),ch=getchar();
	return p*q;
}
//--------------------------------------------------------------------
int n,k;
int b[N];
int mp[K][K];
char s[K][K];
Vt<int> G[N<<1];
int ans=INT_MAX;
int fl;
int vis[N];
int res;
//--------------------------------------------------------------------
void dfs(int u)
{
	vis[u]=1;
	int c=b[u];
//	cout<<u<<" ";
	for(auto v:G[c])
	{
//		cout<<v<<" ";
		rp(i,1,n)
		{
			if(b[i]==v)
			{
				if(!vis[i])
				{
//					cout<<i<<" ";				
					res+=abs(i-u);
					if(i==n)
					{
						ans=min(ans,res);
						fl=1;
//						return;
					}
					dfs(i);
					res-=abs(i-u);
				}
			}
		}
	}
}
/*
5 4
1 4 2 3 4
1010
0001
0110
0100
*/
Sig main(void)
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	n=read(),k=read();
	if(n==1) return !(printf("0"));
	rp(i,1,n) b[i]=read();
	rp(i,1,k)
	{
		scanf("%s",s[i]);
		rp(j,0,k-1) mp[i][j+1]=s[i][j]-'0';
	}
	rp(i,1,k)
	{
		rp(j,1,k)
		{
			if(mp[i][j]==1&&i!=j)
			{
				G[i].pb(j);
			}
		}
	}
//	cout<<1<<" ";
	dfs(1);
	if(!fl) return !(printf("-1"));
	printf("%lld",ans);
	return 0;
}
