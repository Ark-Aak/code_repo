#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=1e5+7;
ll head[Maxn],tot;
struct edge1{
	ll u,v,w,Next;
}Edge[Maxn<<1];
inline void add(ll u,ll v,ll w){
	Edge[++tot]=(edge1){u,v,w,head[u]},head[u]=tot;
}
ll n,w[Maxn],Q;
struct node{
	ll u,stp;
};
inline ll bfs(ll s,ll t){
	queue<node>q;
	q.push((node){s,0});
	ll ans=1e16,ss=0;
	while(!q.empty()){
		node u=q.front();q.pop();
		if(u.u==t){
			ans=min(ans,u.stp);
		}
		for(ll i=head[u.u];i;i=Edge[i].Next){
			ss++;
			if(ss>=100090) return ans;
			if(Edge[i].v!=u.u){
				q.push((node){Edge[i].v,u.stp+Edge[i].w});
			}
		}
	}
	return ans;
}
int main(){
	freopen("double.in","r",stdin);
	freopen("double.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&w[i]),add(2*i,2*i-1,w[i]),add(2*i-1,2*i,w[i]);
	for(ll i=1,u,v,w1,w2;i<n;i++){
		scanf("%lld%lld%lld%lld",&u,&v,&w1,&w2);
		add(2*u-1,2*v-1,w1);add(2*u,2*v,w2);
		add(2*v-1,2*u-1,w1);add(2*v,2*u,w2);
	}
	scanf("%lld",&Q);
	while(Q--){
		ll u,v;
		scanf("%lld%lld",&u,&v);
		printf("%lld\n",bfs(u,v));
	}
	return 0;
}
/*
5
3 6 15 4 8
1 2 5 4
2 3 5 7
1 4 1 5
1 5 2 1
3
1 2
5 6
1 10
*/

