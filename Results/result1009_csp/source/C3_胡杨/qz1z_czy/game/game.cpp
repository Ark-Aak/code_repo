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
const int N=1e3+10;
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
int T,f[N][N];
//--------------------------------------------------------------------

Sig main(void)
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	T=read();
	rp(i,1,1000)
	{
		rp(j,1,1000)
		{
			f[i][j]=(i+j)/__gcd(i,j)-2+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
		}
	}
	while(T--)
	{
		int m=read(),n=read();
		printf("%lld\n",f[m][n]);
	}
	return 0;
}
