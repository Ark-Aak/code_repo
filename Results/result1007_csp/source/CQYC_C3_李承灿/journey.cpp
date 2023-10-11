#include<bits/stdc++.h>
#define int long long
#define N 1003
#define M 200003
using namespace std;
int n,m,q;
int tot,head[N],to[M<<1],nxt[M<<1],val[M<<1];
int d[N];
struct node{
	int id,L,R,S,T;
	bool ans;
}a[1000003];
bool cmp1(node x,node y){
	if(x.S==y.S) return x.L>y.L;
	return x.S<y.S;
}
bool cmp2(node x,node y){
	return x.id<y.id;
}
void add(int u,int v,int w){
	nxt[++tot]=head[u];
	to[tot]=v;
	val[tot]=w;
	head[u]=tot;
}
bool dij(int l,int r,int s,int t){
	for(int i=1;i<=n;i++) d[i]=-1;
	d[s]=l;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > w;
	w.push(make_pair(l,s));
	while(!w.empty()){
		int x=w.top().first,id=w.top().second;
		w.pop();
		for(int i=head[id];i;i=nxt[i]){
			if(d[to[i]]==-1&&x<=val[i]){
				d[to[i]]=val[i];
				w.push(make_pair(val[i],to[i]));
			}
		}
	}
	if(d[t]!=-1&&d[t]<=r) return 1;
	else return 0;
}
void dij2(int x){
	int l=a[x].L,r=a[x].R,s=a[x].S,t=a[x].T;
	if(s!=a[x-1].S) for(int i=1;i<=n;i++) d[i]=-1;
	else if(d[t]!=-1&&d[t]<=r){
		a[x].ans=1;
		return;
	}
	d[s]=l;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > w;
	w.push(make_pair(l,s));
	while(!w.empty()){
		int x=w.top().first,id=w.top().second;
		w.pop();
		for(int i=head[id];i;i=nxt[i]){
			if((d[to[i]]==-1||val[i]<d[to[i]])&&x<=val[i]){
				d[to[i]]=val[i];
				w.push(make_pair(val[i],to[i]));
			}
		}
	}
	if(d[t]!=-1&&d[t]<=r) a[x].ans=1;
	else a[x].ans=0;
}
signed main(){
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&q);
	for(int i=1,u,v;i<=m;i++){
		scanf("%lld %lld",&u,&v);
		add(u,v,i);
		add(v,u,i);
	}
	if(n<=1000&&m<=1000&&q<=1000){
		while(q--){
			int l,r,s,t;
			scanf("%lld %lld %lld %lld",&l,&r,&s,&t);
			if(dij(l,r,s,t)) printf("Yes\n");
			else printf("No\n");
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		scanf("%lld %lld %lld %lld",&a[i].L,&a[i].R,&a[i].S,&a[i].T);
		a[i].id=i;
	}
	sort(a+1,a+q+1,cmp1);
	for(int i=1;i<=q;i++) dij2(i);
	sort(a+1,a+q+1,cmp2);
	for(int i=1;i<=q;i++){
		if(a[i].ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}


