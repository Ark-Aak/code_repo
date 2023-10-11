#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=1010,Maxm=2e5+7;
int head[Maxn],tot,rt,als=5e7,xml,rt1;
vector<vector<vector<pair<int,int> > > >d;
int n,m,Q;
struct edge1{
	int u,v,id,Next;
}Edge[Maxm<<1];
inline void add(int u,int v,int id){
	Edge[++tot]=(edge1){u,v,id,head[u]},head[u]=tot;
}
struct node{
	int u,bg,mx;
};
inline bool getfev(int l,int r,int s,int t){
	queue<node>q;
	q.push((node){s,0,0});
	while(!q.empty()){
		node u=q.front();q.pop();
		if(u.u==t) return 1;
		for(int i=head[u.u];i;i=Edge[i].Next){
			int v=Edge[i].v;
			if(Edge[i].id>u.mx&&Edge[i].id>=l&&Edge[i].id<=r){
				if(u.bg==0) q.push((node){v,Edge[i].id,Edge[i].id});
				else q.push((node){v,u.bg,Edge[i].id});
			}
		}
	}
	return 0;
}
inline void getnai(int s){
	queue<node>q;
	q.push((node){s,0,0});
	while(!q.empty()){
		node u=q.front();q.pop();
		if(rt1>=5e7) break;
		if(u.u!=s){
			d[s][u.u].push_back(make_pair(u.bg,u.mx));
			rt++;
		}
		for(int i=head[u.u];i;i=Edge[i].Next){
			rt1++;
			int v=Edge[i].v;
			if(Edge[i].id>u.mx){
				if(u.bg==0) q.push((node){v,Edge[i].id,Edge[i].id});
				else q.push((node){v,u.bg,Edge[i].id});
			}
		}
	}
}
int main(){
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	als=als/(n*n);
	d.resize(n+1);
	for(int i=1;i<=n;i++) d[i].resize(n+1);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v,i),add(v,u,i);
	}
	for(int i=1;i<=n;i++){
		getnai(i);
		if(rt1>=5e7){
			xml=i-1;
			break;
		}
		if(rt>=als){
			xml=i;
			break;
		}
	}
	while(Q--){
		int l,r,s,t;
		scanf("%d%d%d%d",&l,&r,&s,&t);
		if(s<=xml){
			bool flg=0;
			for(auto i:d[s][t]){
				if(i.first>=l&&i.second<=r) flg=1;
			}
			printf("%s\n",flg?"Yes":"No");
			continue;
		}
		if(l==r){
			bool flg=0;
			for(int i=head[s];i;i=Edge[i].Next){
				if(Edge[i].v==t&&Edge[i].id==l) flg=1;
			}
			printf("%s\n",flg?"Yes":"No");
			continue;
		}
		printf("%s\n",getfev(l,r,s,t)?"Yes":"No");
	}
	return 0;
}
/*
5 4 6
1 2
2 3
3 4
3 5
1 3 1 4
1 3 2 4
1 4 4 5
1 4 4 1
2 3 1 4
2 2 2 3
*/

