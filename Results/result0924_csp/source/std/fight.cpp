#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#define mp make_pair
#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
#define fi first
#define se second
const int M=1e4+10;
#define mid (l+r>>1)
#define lc (x<<1)
#define rc (x<<1|1) 
int pl[M];
void dfs(int x,int l,int r,vector<pair<double,int> > *f,int *a){
	if (l==r){
		f[x].pb(mp(1.0,l));
		pl[l]=x;
		return ;
	}
	dfs(lc,l,mid,f,a);
	dfs(rc,mid+1,r,f,a);
	for (auto xx:f[lc]){
		double tmp=0;
		for (auto y:f[rc]){
			tmp+=1.*(a[xx.se])/(a[xx.se]+a[y.se])*y.fi;
		}
		tmp=tmp*xx.fi;
		f[x].pb(mp(tmp,xx.se));
	}
	for (auto xx:f[rc]){
		double tmp=0;
		for (auto y:f[lc]){
			tmp+=1.*(a[xx.se])/(a[xx.se]+a[y.se])*y.fi;
		}
		tmp=tmp*xx.fi;
		f[x].pb(mp(tmp,xx.se));
	}
}
int a[M],b[M];

vector<pair<double,int> > f[M],g[M];
int n;
int main(){
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	n=read(); int X; a[n-1]=X=read();
	F(i,0,n-2) a[i]=read();
	dfs(1,0,n-1,f,a);
	DF(i,n-1,1) b[i]=a[i-1]; b[0]=X;
	dfs(1,0,n-1,g,b);
	F(i,0,n-1){
		int x=pl[i];
//		cerr<<x<<" !!!!\n";
		double ans=1.0;
		while (x>1){
			if (x&1){
				double pr=0;
				for (auto y:f[x^1]){
//					cerr<<y.fi<<" "<<y.se<<" !!! prob\n";
					pr+=1.*X/(X+a[y.se])*y.fi;
				}
//				cerr<<pr<<" NNNNNNNO\n";
				ans=ans*pr;
			}
			else{
				double pr=0;
				for (auto y:g[x^1]){
					pr+=1.*X/(X+b[y.se])*y.fi;
//					cerr<<y.fi<<" "<<y.se<<" !!! prob  gg\n";
				}
//				cerr<<pr<<" NNNNNNNO gg\n";
				ans=ans*pr;
			}
			x>>=1;
		}
		cout<<OO(12)<<ans<<"\n";
	}
	return 0;
}