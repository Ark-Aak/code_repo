#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,Q;
int head[N*3],to[N*3],net[N*3],cnt;
ll siz[N*3],ans;
void add(int x,int y,ll z) {
	to[++cnt]=y;
	net[cnt]=head[x];
	head[x]=cnt;
	siz[cnt]=z;
}
bool p[N] ;
void w(int now,int t,ll sum) {
	if(now==t) {
		ans=min(ans,sum);
		return ;
	}
	p[now]=1;
	for(int i=head[now];i;i=net[i]) {
		if(p[to[i]]) continue;
		w(to[i],t,sum+siz[i]); 
	}
	p[now]=0;
}
int main() {
	freopen("double.in","r",stdin);
	freopen("double.out","w",stdout);
	cin>>n;
	ll d;
	for(int i=1;i<=n;i++) {
		scanf("%lld",&d);
		add(i*2-1,i*2,d);
		add(i*2,i*2-1,d);
	}
	int x,y;
	ll w1,w2;
	for(int i=1;i<n;i++) {
		scanf("%d%d%lld%lld",&x,&y,&w1,&w2);
		add(x*2-1,y*2-1,w1);
		add(y*2-1,x*2-1,w1);
		add(x*2,y*2,w2);
		add(y*2,x*2,w2);
	}
	cin>>Q;
	int u,v;
	while(Q--) {
		scanf("%d%d",&u,&v);
		ans=1e18;
		w(u,v,0);
		cout<<ans<<"\n";
	}
	return 0;
}

