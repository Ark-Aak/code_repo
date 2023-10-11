#include<bits/stdc++.h>
using namespace std;
int n,m,k;
char s[1000005];
char t[1000005];
//int ans[500005];
int gg[3];
int o[15][3];
int dis[15][15][3];
bool kw[15];
void dfs(int x,int num,int jj,int be,int bef){
	if(o[be][bef]<=num) return;
	if(x==0){
		o[be][bef]=num;
		return;
	}
	if(dis[be][x][jj]<=num) return;
	dis[be][x][jj]=num;
	for(int i=0;i<=9;i++){
		if(!kw[i]) continue;
		if(jj==0){
			dfs((x+i)%11,num+1,1,be,bef);
		}else
			dfs((x-i+11)%11,num+1,0,be,bef);
	}
}
signed main() {
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;++i){
		gg[i&1]+=(int)(s[i]-'0');
		gg[i&1]%=11;
		kw[(int)(s[i]-'0')]=1;
	}
	if(t[n]=='o'){
		cout<<"oimiya";
		return 0;
	}
	int kk0=0,kk1=0;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=10;i++){
		o[i][0]=1e9;
		o[i][1]=1e9;
		dfs(i,0,0,i,0);
		dfs(i,0,1,i,1);
		if(o[i][0]!=1e9)kk0=max(kk0,o[i][0]);
		if(o[i][1]!=1e9)kk1=max(kk1,o[i][1]);
	}
	int qwq=n&1;
	int k=0,gg=0;
	for(int i=1;i<=n;i++){
		if(t[i]=='y'){
			gg++;
			if(t[i-1]!='y')k=i+qwq;
		}
		else{
			gg=0;
		}
		if(k&1){
			if(kk1<gg){
				cout<<"yoimiya ";
				return 0;
			}
		}
		else{ 
			if(kk0<gg){
				cout<<"yoimiya ";
				return 0;
			}
		}
	}
	cout<<"oimiya";
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
