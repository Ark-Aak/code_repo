#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=1e6+5,Mod=11;
int f[N][12];//f_{i,j} 表示在第 i 个位置，当前模数11为v

int n;
char s[N],t[N];

inline bool dfs(int u,int v){
	if(f[u][v]!=-1) return f[u][v];
	if(u==::n){if(!v) return true;else return false;}
	if(t[u+1]=='y'){
		return f[u][v]=(dfs(u+1,(v*10+(s[u+1]-'0'))%Mod)|dfs(u+1,(v*10)%Mod));
	} else return f[u][v]=(dfs(u+1,(v*10+(s[u+1]-'0'))%Mod)&dfs(u+1,(v*10)%Mod));
}
signed main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	scanf("%d",&n);
	memset(f,-1,sizeof f);
	scanf("%s",s+1),scanf("%s",t+1);
	if(dfs(0,0)==1) cout<<"yoimiya"<<endl; 
	else cout<<"oimiya"<<endl;
	return 0;
}

//f[0][0]=1;
//memset(f,-1,sizeof f);
//for(int i=0;i<n;i++)
//for(int j=0;j<11;j++)
// if(if(t[i]+1=='y') f[i][((j*10)+s[i+1]-'0')%Mod]=f[i-1][j]&&f[i-2][j]; 
// else{f[i][j*10%Mod]=f[i-1][j]||f[i-2][j];} 
