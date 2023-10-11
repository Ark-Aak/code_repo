#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
int s[100005];
vector<int>to[100005];
vector<int>W1[100005],W2[100005];
int fa[100005][20],dep[100005];
int f[100005][2][2][20];
void dfs_s1(int x,int p){
//	dep[x]=dep[p]+1;
//	fa[x][0]=p;
	for(int i=0;i<to[x].size();i++){
		int y=to[x][i];
		int w1=W1[x][i];
		int w2=W2[x][i];
		if(y==p)continue;
		dfs_s1(y,x);
		s[x]=min(s[x],s[y]+w1+w2);
//		f[y][0][0][0]=min(w2,s[x]+s[y]+w1);
//		f[y][1][1][0]=min(w1,s[x]+s[y]+w2);
//		f[y][0][1][0]=min(w2+s[x],s[y]+w1);
//		f[y][1][0][0]=min(w1+s[x],s[y]+w2);
//		dfs(y,x);
	}
}
void dfs_s2(int x,int p){
	for(int i=0;i<to[x].size();i++){
		int y=to[x][i];
		int w1=W1[x][i];
		int w2=W2[x][i];
		if(y==p)continue;
		s[y]=min(s[y],s[x]+w1+w2);
		dfs_s2(y,x);
	}
}
void dfs(int x,int p){
	dep[x]=dep[p]+1;
	fa[x][0]=p;
	for(int i=0;i<to[x].size();i++){
		int y=to[x][i];
		int w1=W1[x][i];
		int w2=W2[x][i];
		if(y==p)continue;
		f[y][0][0][0]=min(w2,s[x]+s[y]+w1);
		f[y][1][1][0]=min(w1,s[x]+s[y]+w2);
		f[y][0][1][0]=min(w2+s[x],s[y]+w1);
		f[y][1][0][0]=min(w1+s[x],s[y]+w2);
		dfs(y,x);
	}
}
int dis(int x,int y){
	if(dep[(x+1)/2]<dep[(y+1)/2])swap(x,y);
	int ops1=x%2;
	int ops2=y%2;
	x=(x+1)/2;
	y=(y+1)/2;
	int ans_1[2][2];
	int ans_2[2][2];
	ans_1[0][0]=0;ans_1[0][1]=s[x];
	ans_1[1][0]=s[x];ans_1[1][1]=0;
	ans_2[0][0]=0;ans_2[0][1]=s[y];
	ans_2[1][0]=s[y];ans_2[1][1]=0;
	for(int i=18;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			int tmp[2][2];
			tmp[0][0]=ans_1[0][0];
			tmp[0][1]=ans_1[0][1];
			tmp[1][0]=ans_1[1][0];
			tmp[1][1]=ans_1[1][1];
			ans_1[0][0]=min(tmp[0][0]+f[x][0][0][i],tmp[0][1]+f[x][1][0][i]);
			ans_1[1][0]=min(tmp[1][0]+f[x][0][0][i],tmp[1][1]+f[x][1][0][i]);
			ans_1[0][1]=min(tmp[0][0]+f[x][0][1][i],tmp[0][1]+f[x][1][1][i]);
			ans_1[1][1]=min(tmp[1][0]+f[x][0][1][i],tmp[1][1]+f[x][1][1][i]);
			x=fa[x][i];
		}
	}
	if(x==y){
		return ans_1[ops1][ops2];
	}
	for(int i=18;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			int tmp_1[2][2];
			tmp_1[0][0]=ans_1[0][0];
			tmp_1[0][1]=ans_1[0][1];
			tmp_1[1][0]=ans_1[1][0];
			tmp_1[1][1]=ans_1[1][1];
			ans_1[0][0]=min(tmp_1[0][0]+f[x][0][0][i],tmp_1[0][1]+f[x][1][0][i]);
			ans_1[1][0]=min(tmp_1[1][0]+f[x][0][0][i],tmp_1[1][1]+f[x][1][0][i]);
			ans_1[0][1]=min(tmp_1[0][0]+f[x][0][1][i],tmp_1[0][1]+f[x][1][1][i]);
			ans_1[1][1]=min(tmp_1[1][0]+f[x][0][1][i],tmp_1[1][1]+f[x][1][1][i]);
			x=fa[x][i];
			int tmp_2[2][2];
			tmp_2[0][0]=ans_2[0][0];
			tmp_2[0][1]=ans_2[0][1];
			tmp_2[1][0]=ans_2[1][0];
			tmp_2[1][1]=ans_2[1][1];
			ans_2[0][0]=min(tmp_2[0][0]+f[y][0][0][i],tmp_2[0][1]+f[y][1][0][i]);
			ans_2[1][0]=min(tmp_2[1][0]+f[y][0][0][i],tmp_2[1][1]+f[y][1][0][i]);
			ans_2[0][1]=min(tmp_2[0][0]+f[y][0][1][i],tmp_2[0][1]+f[y][1][1][i]);
			ans_2[1][1]=min(tmp_2[1][0]+f[y][0][1][i],tmp_2[1][1]+f[y][1][1][i]);
			y=fa[y][i];
		}
	}
	int tmp_1[2][2];
	tmp_1[0][0]=ans_1[0][0];
	tmp_1[0][1]=ans_1[0][1];
	tmp_1[1][0]=ans_1[1][0];
	tmp_1[1][1]=ans_1[1][1];
	ans_1[0][0]=min(tmp_1[0][0]+f[x][0][0][0],tmp_1[0][1]+f[x][1][0][0]);
	ans_1[1][0]=min(tmp_1[1][0]+f[x][0][0][0],tmp_1[1][1]+f[x][1][0][0]);
	ans_1[0][1]=min(tmp_1[0][0]+f[x][0][1][0],tmp_1[0][1]+f[x][1][1][0]);
	ans_1[1][1]=min(tmp_1[1][0]+f[x][0][1][0],tmp_1[1][1]+f[x][1][1][0]);
	int tmp_2[2][2];
	tmp_2[0][0]=ans_2[0][0];
	tmp_2[0][1]=ans_2[0][1];
	tmp_2[1][0]=ans_2[1][0];
	tmp_2[1][1]=ans_2[1][1];
	ans_2[0][0]=min(tmp_2[0][0]+f[y][0][0][0],tmp_2[0][1]+f[y][1][0][0]);
	ans_2[1][0]=min(tmp_2[1][0]+f[y][0][0][0],tmp_2[1][1]+f[y][1][0][0]);
	ans_2[0][1]=min(tmp_2[0][0]+f[y][0][1][0],tmp_2[0][1]+f[y][1][1][0]);
	ans_2[1][1]=min(tmp_2[1][0]+f[y][0][1][0],tmp_2[1][1]+f[y][1][1][0]);
	return min(ans_1[ops1][0]+ans_2[ops2][0],ans_1[ops1][1]+ans_2[ops2][1]);
}
signed main(){
	freopen("double.in","r",stdin);
	freopen("double.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&s[i]);
	for(int i=1;i<n;i++){
		int u,v,w1,w2;
		scanf("%lld %lld %lld %lld",&u,&v,&w1,&w2);
		to[u].push_back(v);
		W1[u].push_back(w1);
		W2[u].push_back(w2);
		to[v].push_back(u);
		W1[v].push_back(w1);
		W2[v].push_back(w2);
	}
	dfs_s1(1,0);
	dfs_s2(1,0);
	dfs(1,0);
	for(int i=0;i<18;i++){
		for(int j=1;j<=n;j++){
			fa[j][i+1]=fa[fa[j][i]][i];
			f[j][0][0][i+1]=min(f[j][0][0][i]+f[fa[j][i]][0][0][i],f[j][0][1][i]+f[fa[j][i]][1][0][i]);
			f[j][1][0][i+1]=min(f[j][1][0][i]+f[fa[j][i]][0][0][i],f[j][1][1][i]+f[fa[j][i]][1][0][i]);
			f[j][0][1][i+1]=min(f[j][0][0][i]+f[fa[j][i]][0][1][i],f[j][0][1][i]+f[fa[j][i]][1][1][i]);
			f[j][1][1][i+1]=min(f[j][1][0][i]+f[fa[j][i]][0][1][i],f[j][1][1][i]+f[fa[j][i]][1][1][i]);
		}
	}
	int q;
	scanf("%lld",&q);
	while(q--){
		int u,v;
		scanf("%lld %lld",&u,&v);
		printf("%lld\n",dis(u,v));
	}
	return 0;
}
