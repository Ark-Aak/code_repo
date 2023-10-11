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
#define Frd friend
#define Mul multiset
#define Vt vector
#define Stk stack
#define Que queue
#define Due deque
#define Itt iterator
#define PQ priority_queue
#define umap unordered_map
#define uset unordered_set
#define mpr make_pair
#define ft first
#define sd second
#define of pop_front
#define ob pop_back
#define pf push_front
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
#define cal(x,y) ((x)+(y)*n)
using namespace std;
//--------------------------------------------------------------------
const int N=25,M=2e5+10;
//--------------------------------------------------------------------
int n,m;
char ch[N][M];
bitset<M> a[N];
int ans=__LONG_LONG_MAX__;
//--------------------------------------------------------------------
namespace IT
{
	Il void IOS() { ios::sync_with_stdio(false); } 	
	Il void CCT() { cin.tie(0); cout.tie(0); }
	Il int read()
	{
		int p=0, q=1;
		char ch=getchar();
		while (!isdigit(ch)) q=(ch=='-')?-1:1,ch=getchar();
		while (isdigit(ch)) p=(p<<3)+(p<<1)+(ch^48),ch=getchar();
		return p*q;
	}
	Il void dfs(int x)
	{
		if(x==n+1)
		{
			int s=0;
			rp(i,1,m)
			{
				int c=0;
				rp(j,1,n)
				{
					if(a[j][i]) c++;
				}
				if(c>n-c) s+=(n-c);
				else s+=c;
			}
			ans=min(ans,s);
			return;
		}
		rp(i,0,1)
		{
			a[x].flip();
			IT::dfs(x+1);
		}
	}
}
/*
3 4
0110
1010
0111
*/
/*
2
*/
Sig main(void)
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
//	int t1=clock();
	IT::IOS(); IT::CCT();
	n=IT::read(),m=IT::read();
	rp(i,1,n)
	{
		scanf("%s",ch[i]+1);
		rp(j,1,m) a[i][j]=ch[i][j]-'0';
	}
	IT::dfs(1);
	printf("%lld",ans);
//	int t2=clock();
//	printf("%lld ms",t2-t1);
	return 0;
}
