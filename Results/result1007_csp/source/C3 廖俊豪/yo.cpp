#include<bits/stdc++.h>
using namespace std;
int n;
int Pow[1000005];
int s[100005];
char t[100005];
int f[1000005][11];
void dfs(int x,int y){
	if(f[x][y]!=-1)return;
	if(x==n+1){f[x][y]=(y==0);return;}
	dfs(x+1,y);
	dfs(x+1,(y+Pow[n-x]*s[x])%11);
	if(t[x]=='y'){
		if(f[x+1][y]==1||f[x+1][(y+Pow[n-x]*s[x])%11]==1){
			f[x][y]=1;
		}else{
			f[x][y]=0;
		}
	}else{
		if(f[x+1][y]==0||f[x+1][(y+Pow[n-x]*s[x])%11]==0){
			f[x][y]=0;
		}else{
			f[x][y]=1;
		}
	}
}
signed main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	memset(f,-1,sizeof f);
	Pow[0]=1;
	scanf("%d",&n);
	for(int i=1;i<n;i++)Pow[i]=(Pow[i-1]*10)%11;
	for(int i=1;i<=n;i++)scanf("%1d",&s[i]);
	scanf("%s",t+1);
	dfs(1,0);
	if(f[1][0]==1)printf("yoimiya");
	else printf("oimiya");
	return 0;
} 
