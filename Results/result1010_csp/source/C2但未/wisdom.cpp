#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<1)+(x<<3)+s-48;s=getchar();}
	return x*f;
}
const int Maxn=1e6+5,Mod=1e9+7;
int vis[Maxn];
int vis1[Maxn];
int n,m,q;
struct node{
	int op,x,y;
}s[1005];
inline bool cmp(node a,node b){return a.op>b.op;}
int pd[Maxn];
signed main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	n=read();m=read();q=read();
	for(int i=1;i<=q;i++){
		char ch;cin>>ch;
		int x=read(),y=read();
		if(ch=='R')s[i]={1,x,y};
		else s[i]={0,x,y};
	}
	sort(s+1,s+1+q,cmp);
	int len=0;
	for(int i=1;i<=q;i++)
		if(s[i].op)len=i;
	int ans=0;
	for(int i=1;i<=n;i++)vis[i]=1;
	for(int i=1;i<=m;i++)vis1[i]=1;
	for(int i=1;i<=len;i++){
		vis[s[i].x]=1ll*vis[s[i].x]*s[i].y%Mod;
	}
	for(int i=1;i<=n;i++)
		ans=(ans+1ll*(1ll*(i-1)*m*m%Mod+1ll*(1+m)*m/2ll%Mod)*vis[i]%Mod);
	for(int i=len+1;i<=q;i++){
		int sum=0;
		for(int j=1;j<=len;j++){
			int u=(1ll*(s[j].x-1)*m%Mod+s[i].x)%Mod;
			if(pd[s[j].x]==i)continue;
			pd[s[j].x]=i;
			sum+=u;
			ans=(ans+1ll*vis1[s[i].x]*vis[s[j].x]%Mod*(s[i].y-1+Mod)%Mod*u%Mod)%Mod;
		}
		ans=(ans+1ll*vis1[s[i].x]*(s[i].y-1+Mod)%Mod*(1ll*s[i].x*n+1ll*(n-1)*n/2%Mod*m-1ll*sum+Mod)%Mod)%Mod;
		vis1[s[i].x]=vis1[s[i].x]*s[i].y%Mod;
	}
	printf("%lld",ans);
	return 0;
}

