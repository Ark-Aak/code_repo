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
const int mod=1e9+7,K=1e3+10,N=1e6+10;
//--------------------------------------------------------------------
int n,m,k;
int r[N],s[N];
int ans;
int mp[1010][1010];
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
	Il void init()
	{
		Mset(r,-1);
		Mset(s,-1);
	}
	Il void Do()
	{
		IT::init();
		n=IT::read(),m=IT::read(),k=IT::read();
		rp(i,1,k)
		{
			char ch;
			cin>>ch;
			int x,y;
			cin>>x>>y;
			if(ch=='R')
			{
				if(r[x]==0) continue;
				if(r[x]<0) r[x]=0;
				if(r[x]>0&&!y) r[x]=0;
				r[x]+=y;
				r[x]%=mod;
			}
			if(ch=='S')
			{
				if(s[x]==0) continue;
				if(s[x]<0) s[x]=0;
				if(s[x]>0&&!y) s[x]=0;
				s[x]+=y;
				s[x]%=mod;
			}
		}
//		rp(i,1,n) cout<<r[i]<<" ";
//		cout<<'\n';
//		rp(i,1,m) cout<<s[i]<<" ";
//		cout<<'\n';
		rp(i,1,n)
		{
			rp(j,1,m)
			{
				if(!r[i]||!s[j]) continue;
				mp[i][j]=(i-1)*m+j;
				mp[i][j]%=mod;
				if(r[i]==-1&&s[j]==-1)
				{
					ans+=mp[i][j];
					if(ans>=mod) ans%=mod;
					continue;
				}
				if(r[i]!=-1) mp[i][j]=mp[i][j]*r[i]%mod;
				if(s[j]!=-1) mp[i][j]=mp[i][j]*s[j]%mod;
				ans+=mp[i][j];
				if(ans>=mod) ans%=mod;
			}
		}
		printf("%lld",ans);
	}
}
Sig main(void)
{
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
//	int t1=clock();
	IT::IOS(); IT::CCT();
	IT::Do();
//	int t2=clock();
//	printf("%lld ms",t2-t1);
	return 0;
}
