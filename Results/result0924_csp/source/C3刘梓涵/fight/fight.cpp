#include<bits/stdc++.h>
#define int long long
#define inf LONG_LONG_MAX
#define fir first
#define sec second
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
#define Pr(i,j) pair<i,j>
#define PB(i) push_back(i)
#define MP(i,j) make_pair(i,j)
#define Fo(i,j) for(auto i:j)
#define mem(i,j) memset(i,j,sizeof(i))
#define FO(i,j,k) for(int i=j;i;i=k)
#define FFF(i,j,k) for(auto i=j;i!=k;++i)
#define For(i,j,k) for(int i=j;i<=k;++i)
#define FoR(i,j,k) for(int i=j;i^k;++i)
#define FOR(i,j,k) for(int i=j;i>=k;--i)
using namespace std;
template <typename _Tp>void read(_Tp& first) {
    _Tp x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    first = x * f;
}
#define N 1000005
#define Mod 1000000007
int n,x,now;
int a[N],f[N],l,r;
double ans;
void dfs(double s){
	if(l==r){
//		cout<<s<<endl;
		ans+=s;
		return;
	}
	int ll=l,rr=r,nn=now;
	if(l!=now&&l+1!=now){
		l+=2;a[++r]=a[l-2];
//		cout<<a[l-2]<<endl;
		dfs(s*(a[l-2]*1.0/(a[l-1]+a[l-2])));
		l=ll+2,r=rr;now=nn;
		a[++r]=a[l-1];
//		cout<<a[l-1]<<endl;
		dfs(s*(a[l-1]*1.0/(a[l-1]+a[l-2])));
	}else{
		if(l==now){
			l+=2;a[++r]=a[l-2];now=r;
			dfs(s*(a[l-2]*1.0/(a[l-1]+a[l-2])));
		}else{
			l+=2;a[++r]=a[l-1];now=r;
			dfs(s*(a[l-1]*1.0/(a[l-1]+a[l-2])));
		}
	}
}
signed main(){
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
    cin>>n>>x;
    For(i,1,n-1)cin>>f[i];
    if(n<=16){
    	For(k,1,n){
	    	ans=0.0;
	    	l=1,r=0;
	    	FoR(i,1,n){
		    	if(k==i&&k!=n)a[++r]=x,now=r;
		    	a[++r]=f[i];
			}if(k==n)a[++r]=x,now=r;
			dfs(1);
			printf("%.15lf\n",ans);
	//		cout<<endl;
		}
	}
	else{
		int p=1;
		For(i,1,100){
			p<<=1;
			if(n<=p){
				break;
			}
		}
		For(i,1,n-(p-n))printf("%.15lf\n",(double)1.0/p);
		For(i,1,p-n)printf("%.15lf\n",(double)1.0/(p/2));
	}
    return 0;
}
/*
4 3
4 5 2
*/
