#include<bits/stdc++.h>
#define ll long long
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
int n,m,T;
struct node{
	int l,r;
}a[N];
int t[N];
inline void add(int x,int k){
	while(x<=n)t[x]+=k,x+=x&-x;
}
inline int query(int x){
	int ans=0;
	while(x)ans+=t[x],x-=x&-x;
	return ans;
}
int b[N];
int main(){
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	n=read(),T=read();
	rep(i,1,n)a[i].l=read(),a[i].r=read();
	while(T--){
		m=read();
		int ans=0;
		rep(i,1,m)b[i]=read(),add(b[i],1);
		rep(i,1,n)ans+=(query(a[i].r)-query(a[i].l-1))&1;
		rep(i,1,m)add(b[i],-1);
		pf(ans),putchar('\n');
	}
	return 0;
}
