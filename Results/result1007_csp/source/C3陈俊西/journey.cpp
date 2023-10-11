#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,M=2e5+5,Q=1e6+1;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,q,u[M],v[M],l[Q],r[Q],s[Q],t[Q];

bool dis[N],can[N][N],ans[Q];
bool solve(int L,int R,int S,int T){
	memset(dis,0,sizeof dis);
	dis[S]=1;
	for(int i=L;i<=R;i++){
		int U=u[i],V=v[i];
		if(dis[U]) dis[V]=1;
		if(dis[V]) dis[U]=1;
	}
	return dis[T];
}

struct Node{
	int ss,tt,id;
};
vector<Node> deal[M];
void solve2(){
	for(int i=1;i<=n;i++)
		can[i][i]=1;
	for(int i=1;i<=m;i++){
		int U=u[i],V=v[i];
		for(int j=1;j<=n;j++){
			if(can[j][U]) can[j][V]=1;
			if(can[j][V]) can[j][U]=1;
		}
		for(int j=0;j<deal[i].size();j++){
			Node x=deal[i][j];
			if(can[x.ss][x.tt]) ans[x.id]=1;
		}
	}	
	return;
}
signed main(){
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;i++)
		u[i]=read(),v[i]=read();
	int cnt=0;
	for(int i=1;i<=q;i++){
		l[i]=read(),r[i]=read();
		s[i]=read(),t[i]=read();	
		if(l[i]==1) cnt++;	
	}

	if(cnt==q){
		for(int i=1;i<=q;i++)
			if(l[i]==1) deal[r[i]].emplace_back(Node{s[i],t[i],i});
		solve2();
		for(int i=1;i<=q;i++){
			if(ans[i]) puts("Yes");
			else puts("No");		
		}
	}	
	else{
		for(int i=1;i<=q;i++){
			if(l[i]==r[i]){
				int U=u[l[i]],V=v[l[i]];
				if((U==s[i]&&V==t[i])||(U==t[i]&&V==s[i])) puts("Yes");
				else puts("No");
			}
			else{
				if(solve(l[i],r[i],s[i],t[i])) puts("Yes");
				else puts("No");			
			}
		}
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
