#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,int>
using namespace std;
const int N=5e4+5,K=52;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int n,k,pre[N][K],lst[N][K],a[N];
char ok[K];
int e[K][K],cnt[K],id[K],u;
priority_queue<P,vector<P>,greater<P> >hp;
ll dis[N];
inline void Push(int x,int i){
	ll v=dis[i]+abs(i-x);
	if(x&&dis[x]>v){
		dis[x]=v;
		hp.push({dis[x],x});
	}
}
int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=k;i++){
		scanf("%s",ok+1);
		for(int j=1;j<=k;j++)
			if(ok[j]=='1') e[i][++cnt[i]]=j;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++) pre[i][j]=id[j];
		id[a[i]]=i;
	}
	memset(id,0,sizeof(id));
	for(int i=n;i;--i){
		for(int j=1;j<=k;j++) lst[i][j]=id[j];
		id[a[i]]=i;
	}
	memset(dis,0x3f,sizeof(dis));
	hp.push({0,1});dis[1]=0;
	while(!hp.empty()){
		u=hp.top().second,hp.pop();
		if(u==n){
			printf("%lld",dis[n]);
			return 0;
		}
		for(int i=1;i<=cnt[a[u]];i++){
			Push(pre[u][e[a[u]][i]],u);
			Push(lst[u][e[a[u]][i]],u);
		}
	}
	puts("-1");
	return 0;
}

