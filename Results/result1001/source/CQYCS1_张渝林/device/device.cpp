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
int T,n,k;
int a[7],b[4],ct[11];
inline int solve(int x){
	rep(i,1,9)ct[i]=0;
	while(x)ct[x%10]+=2,x/=10;
	vector<int>p;
	rep(i,1,9)if(ct[i])p.pb(ct[i]);
	if(p.size()==3)return 24;
	if(p.size()==1)return 1;
	return 7;
}
inline int get(int x){
	rep(i,1,9)ct[i]=0;
	while(x)ct[x%10]+=2,x/=10;
	vector<int>p;
	rep(i,1,9)if(ct[i])p.pb(ct[i]);
	if(p.size()==1)return 1;
	if(p.size()==2)return 8;
	return 27;
}
int main(){
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	T=read();
	while(T--){
		k=read(),n=read();
		if(n==0){
			pf(1),putchar('\n');
			continue; 
		}
		if(n==1)pf(solve(k)),putchar('\n');
		else pf(get(k)),putchar('\n');
	}
	return 0;
}
