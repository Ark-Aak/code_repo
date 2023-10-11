#include<bits/stdc++.h>
#define ll __int128
#define L xd[x].l
#define R xd[x].r
#define mid (l+r>>1LL)
#define lc L,l,mid
#define rc R,mid+1,r
#define Root 1,1,n
#define OK l>=Ll&&r<=Rr
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define pb push_back
#define ull unsigned ll
#define e(x) for(int i=h[x],y=to[i];i;i=nxt[i],y=to[i])
#define E(x) for(auto y:p[x])
#define Pi pair<int,int>
#define ui unsigned ll
inline int read(){int s=0,w=1;char c=getchar();while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();return s*w;}
inline void pf(ll x){if(x<0) putchar('-'),x=-x;if(x>9)pf(x/10);putchar(x%10+48);}
const int N =5e5+5,M=1e6+5,inf=(1LL<<31)-1;
const ll llf=1e18,mod=1e8+7,bas=131;
const ui base=13331;
using namespace std;
int T,n,m;
inline ll c(ll x,ll y){
	if(x<y||x<0||y<0)return 0;
	ll ans=1;
	for(ll i=x-y+1;i<=x;i++)ans*=i;
	for(ll i=1;i<=y;i++)ans/=i;
	return ans;
}
inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read();
		ll ans=0;
		rep(i,1,n)rep(j,1,m){
			ans+=c((ll)n*m-n-m+1,2)+(ll)(n-1)*c((ll)n*m-(ll)n,1)+(ll)(m-1)*c((ll)n*m-(ll)m,1)-(ll)(n-1)*(m-1);
			int delx=min(n-i,i-1),dely=min(m-j,j-1);
			rep(dx,0,delx)rep(dy,0,dely){
				if(dx==0&&dy==0)continue;
				if(gcd(dx,dy)!=1)continue;
				int rk=inf,ck=inf;
				if(dx)rk=(n-i)/dx+(i-1)/dx;
				if(dy)ck=(m-j)/dy+(j-1/dy);
				int ct=min(rk,ck);
				ans+=c(ct,2)*c((ll)n*m-ct-1,1);
				if(dx&&dy){
					ans+=c(ct,2)*c((ll)n*m-ct-1,1);
				}
			}
		}
		pf(ans),putchar('\n');
	}
	return 0;
}
