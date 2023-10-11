#include<bits/stdc++.h>
#define int long long
#define ll long long
#define mid ((l+r)>>1)
#define FOR(i,a,b) for(ll i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(ll i=(a); i>=(b); --i)
#define modj(x) ((x)-=((x)>=MOD)?MOD:0)
#define qmin(x,y) ((x)=min((x),(y)))
#define qmax(x,y) ((x)=max((x),(y)))
using namespace std;
const int MAXN=1e6;
inline ll read(){
	ll t=0,f=0;char v=getchar();
	while(!isdigit(v))f|=(v=='-'),v=getchar();
	while(isdigit(v))t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
inline void write(ll x){
	if(x<0){x*=-1; putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
int n,m,maxx=1e16;
int a[MAXN],ans;
int to[MAXN],nxt[MAXN]; 
int g1[MAXN],g2[MAXN]; 
int qzh[MAXN];
bool vis[MAXN];
signed main(){
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	int T=1;
	while(T--){
		n=read();m=read();
		if(m==1){
			FOR(i,1,n) a[i]=read();
			sort(a+1,a+n+1);
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=a[i];
			}
			cout<<ans-(a[(n+1)/2]);
			return 0;
		}
		if(m<=3){
			FOR(i,1,n) a[i]=read();
			for(int i=1;i<=n;i++){
				to[i]=i-1;
				nxt[i]=i+1;
			}
			int sum=0;
			for(int i=1;i<=m;i++){
				sum+=a[i];
			}
			for(int i=m;i<=n;i++){
				qzh[i]=sum;
				g1[i]=sum;
				g2[i]=-sum;
				sum-=a[i-m+1];
				sum+=a[i+1];
			}
			vis[0]=vis[n+1]=1;
			for(int i=m;i<n;i+=m){
				if((i/m)%2==1){
					int x=0,y=0;
					for(int i=1;i<=n;i++){
						if(!vis[i]&&qzh[i]>x){
							x=qzh[i];
							y=i;
						}
					}
					ans+=x;
					vis[y]=1;
					int r=nxt[y];
					int kk=y;
					for(int j=1;j<m;j++){
						kk=nxt[kk];
					}
					int pp=y;
					for(int j=1;j<=m;j++){
						vis[pp]=1;
						pp=to[pp];
					}
					int l=pp;
					//开始更新 
					int sum=0;
					for(int j=1;j<m;j++){
						sum+=a[pp];
						sum-=a[y];
						qzh[kk]+=sum;
						kk=to[kk];
						y=to[y];
						pp=to[pp];
					}
					nxt[l]=r;
					to[r]=l;
					
					
				}
				else{
					int x=1e16,y=0;
					for(int i=1;i<=n;i++){
						if(!vis[i]&&qzh[i]<x){
							x=qzh[i];
							y=i;
						}
					}
					ans+=x;
					vis[y]=1;
					int r=nxt[y];
					int kk=y;
					for(int j=1;j<m;j++){
						kk=nxt[kk];
					}
					int pp=y;
					for(int j=1;j<=m;j++){
						vis[pp]=1;
						pp=to[pp];
					}
					int l=pp;
					//开始更新 
					int sum=0;
					for(int j=1;j<m;j++){
						sum+=a[pp];
						sum-=a[y];
						qzh[kk]+=sum;
						kk=to[kk];
						y=to[y];
						pp=to[pp];
					}
					nxt[l]=r;
					to[r]=l;
				}
			}
			cout<<ans;
		} 
		else{
			FOR(i,1,n) a[i]=read();
			sort(a+1,a+n+1);
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=a[i];
			}
			cout<<ans-(a[(n+1)/2]);
		}
		
		
	}
	return 0;
}
/*
5 2
3 5 3 2 1
*/

