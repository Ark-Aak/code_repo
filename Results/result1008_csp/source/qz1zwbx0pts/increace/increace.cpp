#include<bits/stdc++.h>
using namespace std;
struct node{
	int net,v,w;
};
node e[200005];
int head[200005],n,m,anss[200005],tot=1;
int dfs(int u,int w){
	int ans=1;
	for(int i=head[u];i;i=e[i].net){
		if(e[i].w>w){
			ans+=dfs(e[i].v,e[i].w);
		}
	}
	return ans;
}
void opr(int u,int ty,int w,int st,int wh)
{
	int maxx=0,minn=999999,minw,maxw,mi,ma;
	for(int i=head[u];i;i=e[i].net){
	//	cout<<e[i].w<<" "<<w<<" "<<endl;
		if(e[i].w>w){
			int sum=dfs(e[i].v,e[i].w);
		//	cout<<sum<<endl;
			if(sum>maxx){
				maxx=sum;
				maxw=e[i].w;
				ma=e[i].v;
			//	cout<<-1;
			}
			if(sum<minn){
				minn=sum;
				minw=e[i].w;
				mi=e[i].v;
			//	cout<<-1;
			}
		}
	}
	if(maxx==0||minn==999999){
		anss[wh]=st;
		return;
	}
	if(!ty){
		opr(ma,1,maxw,st+1,wh);
	}
	else{
		opr(mi,0,minw,st+1,wh);
	}
}
void add(int u,int v,int w){
	e[tot].v=v;
	e[tot].w=w;
	e[tot].net=head[u];
	head[u]=tot++;
} 
int main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	cin>>n>>m;
	for(int u,v,w,i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
		
	}
	for(int i=1;i<=n;i++){
		opr(i,0,0,0,i);
	}
	for(int i=1;i<=n;i++){
		cout<<anss[i]<<" ";
	}
	return 0;
}

