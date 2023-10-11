#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
int n,k,ans=0;

bool vis[1000];
bool flag[1000];
void dfs(int x,int p){
	if(vis[x]) return;
	if(!vis[x]){
		vis[x]=1;
	//	ans++,dfs(x,p-1);
	}
	if(p==0){
		cout<<x<<endl;
		ans++;
		return;
	}
	int gg=x*13;
	int wang=gg/10000,qian=gg/1000%10,bai=gg/100%10,shi=gg/10%10,ge=gg%10;
	if(qian!=0&&bai!=0&&shi!=0){
		dfs(qian*100+bai*10+shi,p-1);
		dfs(qian*10+bai*100+shi,p-1);
		dfs(qian*10+bai+shi*100,p-1);
		dfs(qian*100+bai+shi*10,p-1);
		dfs(qian+bai*100+shi*10,p-1);
		dfs(qian+bai*10+shi*100,p-1);
	}	if(qian!=0&&bai!=0&&ge!=0){
		dfs(qian*100+bai*10+ge,p-1);
		dfs(qian*10+bai*100+ge,p-1);
		dfs(qian*10+bai+ge*100,p-1);
		dfs(qian*100+bai+ge*10,p-1);
		dfs(qian+bai*100+ge*10,p-1);
		dfs(qian+bai*10+ge*100,p-1);
	}	if(qian!=0&&ge!=0&&shi!=0){
		dfs(qian*100+ge*10+shi,p-1);
		dfs(qian*10+ge*100+shi,p-1);
		dfs(qian*10+ge+shi*100,p-1);
		dfs(qian*100+ge+shi*10,p-1);
		dfs(qian+ge*100+shi*10,p-1);
		dfs(qian+ge*10+shi*100,p-1);
	}	if(ge!=0&&bai!=0&&shi!=0){
		dfs(ge*100+bai*10+shi,p-1);
		dfs(ge*10+bai*100+shi,p-1);
		dfs(ge*10+bai+shi*100,p-1);
		dfs(ge*100+bai+shi*10,p-1);
		dfs(ge+bai*100+shi*10,p-1);
		dfs(ge+bai*10+shi*100,p-1);
	}
	if(wang!=0&&ge!=0&&shi!=0){
		dfs(ge*100+wang*10+shi,p-1);
		dfs(ge*10+wang*100+shi,p-1);
		dfs(ge*10+wang+shi*100,p-1);
		dfs(ge*100+wang+shi*10,p-1);
		dfs(ge+wang*100+shi*10,p-1);
		dfs(ge+wang*10+shi*100,p-1);
	}
	if(wang!=0&&ge!=0&&bai!=0){
		dfs(ge*100+wang*10+bai,p-1);
		dfs(ge*10+wang*100+bai,p-1);
		dfs(ge*10+wang+bai*100,p-1);
		dfs(ge*100+wang+bai*10,p-1);
		dfs(ge+wang*100+bai*10,p-1);
		dfs(ge+wang*10+bai*100,p-1);
	}
	if(wang!=0&&ge!=0&&qian!=0){
		dfs(ge*100+wang*10+qian,p-1);
		dfs(ge*10+wang*100+qian,p-1);
		dfs(ge*10+wang+qian*100,p-1);
		dfs(ge*100+wang+qian*10,p-1);
		dfs(ge+wang*100+qian*10,p-1);
		dfs(ge+wang*10+qian*100,p-1);
	}
	if(wang!=0&&shi!=0&&qian!=0){
		dfs(shi*100+wang*10+qian,p-1);
		dfs(shi*10+wang*100+qian,p-1);
		dfs(shi*10+wang+qian*100,p-1);
		dfs(shi*100+wang+qian*10,p-1);
		dfs(shi+wang*100+qian*10,p-1);
		dfs(shi+wang*10+qian*100,p-1);
	}
	if(wang!=0&&shi!=0&&bai!=0){
		dfs(shi*100+wang*10+bai,p-1);
		dfs(shi*10+wang*100+bai,p-1);
		dfs(shi*10+wang+bai*100,p-1);
		dfs(shi*100+wang+bai*10,p-1);
		dfs(shi+wang*100+bai*10,p-1);
		dfs(shi+wang*10+bai*100,p-1);
	}
	if(wang!=0&&qian!=0&&bai!=0){
		dfs(qian*100+wang*10+bai,p-1);
		dfs(qian*10+wang*100+bai,p-1);
		dfs(qian*10+wang+bai*100,p-1);
		dfs(qian*100+wang+bai*10,p-1);
		dfs(qian+wang*100+bai*10,p-1);
		dfs(qian+wang*10+bai*100,p-1);
	}
	gg=x*11;
	wang=gg/10000;
	qian=gg/1000%10,bai=gg/100%10,shi=gg/10%10,ge=gg%10;
	if(qian!=0&&bai!=0&&shi!=0){
		dfs(qian*100+bai*10+shi,p-1);
		dfs(qian*10+bai*100+shi,p-1);
		dfs(qian*10+bai+shi*100,p-1);
		dfs(qian*100+bai+shi*10,p-1);
		dfs(qian+bai*100+shi*10,p-1);
		dfs(qian+bai*10+shi*100,p-1);
	}	if(qian!=0&&bai!=0&&ge!=0){
		dfs(qian*100+bai*10+ge,p-1);
		dfs(qian*10+bai*100+ge,p-1);
		dfs(qian*10+bai+ge*100,p-1);
		dfs(qian*100+bai+ge*10,p-1);
		dfs(qian+bai*100+ge*10,p-1);
		dfs(qian+bai*10+ge*100,p-1);
	}	if(qian!=0&&ge!=0&&shi!=0){
		dfs(qian*100+ge*10+shi,p-1);
		dfs(qian*10+ge*100+shi,p-1);
		dfs(qian*10+ge+shi*100,p-1);
		dfs(qian*100+ge+shi*10,p-1);
		dfs(qian+ge*100+shi*10,p-1);
		dfs(qian+ge*10+shi*100,p-1);
	}	if(ge!=0&&bai!=0&&shi!=0){
		dfs(ge*100+bai*10+shi,p-1);
		dfs(ge*10+bai*100+shi,p-1);
		dfs(ge*10+bai+shi*100,p-1);
		dfs(ge*100+bai+shi*10,p-1);
		dfs(ge+bai*100+shi*10,p-1);
		dfs(ge+bai*10+shi*100,p-1);
	}
	if(wang!=0&&ge!=0&&shi!=0){
		dfs(ge*100+wang*10+shi,p-1);
		dfs(ge*10+wang*100+shi,p-1);
		dfs(ge*10+wang+shi*100,p-1);
		dfs(ge*100+wang+shi*10,p-1);
		dfs(ge+wang*100+shi*10,p-1);
		dfs(ge+wang*10+shi*100,p-1);
	}
	if(wang!=0&&ge!=0&&bai!=0){
		dfs(ge*100+wang*10+bai,p-1);
		dfs(ge*10+wang*100+bai,p-1);
		dfs(ge*10+wang+bai*100,p-1);
		dfs(ge*100+wang+bai*10,p-1);
		dfs(ge+wang*100+bai*10,p-1);
		dfs(ge+wang*10+bai*100,p-1);
	}
	if(wang!=0&&ge!=0&&qian!=0){
		dfs(ge*100+wang*10+qian,p-1);
		dfs(ge*10+wang*100+qian,p-1);
		dfs(ge*10+wang+qian*100,p-1);
		dfs(ge*100+wang+qian*10,p-1);
		dfs(ge+wang*100+qian*10,p-1);
		dfs(ge+wang*10+qian*100,p-1);
	}
	if(wang!=0&&shi!=0&&qian!=0){
		dfs(shi*100+wang*10+qian,p-1);
		dfs(shi*10+wang*100+qian,p-1);
		dfs(shi*10+wang+qian*100,p-1);
		dfs(shi*100+wang+qian*10,p-1);
		dfs(shi+wang*100+qian*10,p-1);
		dfs(shi+wang*10+qian*100,p-1);
	}
	if(wang!=0&&shi!=0&&bai!=0){
		dfs(shi*100+wang*10+bai,p-1);
		dfs(shi*10+wang*100+bai,p-1);
		dfs(shi*10+wang+bai*100,p-1);
		dfs(shi*100+wang+bai*10,p-1);
		dfs(shi+wang*100+bai*10,p-1);
		dfs(shi+wang*10+bai*100,p-1);
	}
	if(wang!=0&&qian!=0&&bai!=0){
		dfs(qian*100+wang*10+bai,p-1);
		dfs(qian*10+wang*100+bai,p-1);
		dfs(qian*10+wang+bai*100,p-1);
		dfs(qian*100+wang+bai*10,p-1);
		dfs(qian+wang*100+bai*10,p-1);
		dfs(qian+wang*10+bai*100,p-1);
	}
	gg=x*7;
	qian=gg/1000,bai=gg/100%10,shi=gg/10%10,ge=gg%10;
	if(qian!=0&&bai!=0&&shi!=0){
		dfs(qian*100+bai*10+shi,p-1);
		dfs(qian*10+bai*100+shi,p-1);
		dfs(qian*10+bai+shi*100,p-1);
		dfs(qian*100+bai+shi*10,p-1);
		dfs(qian+bai*100+shi*10,p-1);
		dfs(qian+bai*10+shi*100,p-1);
	}	if(qian!=0&&bai!=0&&ge!=0){
		dfs(qian*100+bai*10+ge,p-1);
		dfs(qian*10+bai*100+ge,p-1);
		dfs(qian*10+bai+ge*100,p-1);
		dfs(qian*100+bai+ge*10,p-1);
		dfs(qian+bai*100+ge*10,p-1);
		dfs(qian+bai*10+ge*100,p-1);
	}	if(qian!=0&&ge!=0&&shi!=0){
		dfs(qian*100+ge*10+shi,p-1);
		dfs(qian*10+ge*100+shi,p-1);
		dfs(qian*10+ge+shi*100,p-1);
		dfs(qian*100+ge+shi*10,p-1);
		dfs(qian+ge*100+shi*10,p-1);
		dfs(qian+ge*10+shi*100,p-1);
	}	if(ge!=0&&bai!=0&&shi!=0){
		dfs(ge*100+bai*10+shi,p-1);
		dfs(ge*10+bai*100+shi,p-1);
		dfs(ge*10+bai+shi*100,p-1);
		dfs(ge*100+bai+shi*10,p-1);
		dfs(ge+bai*100+shi*10,p-1);
		dfs(ge+bai*10+shi*100,p-1);
	}
}
int main() {
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		ans=0;
		scanf("%d%d",&k,&n);
		if(n==0){
			cout<<1;
			continue;
		}
		if(n==1){
			cout<<24;
			continue;
		}
		if(n<100)dfs(k,n);
		cout<<ans<<endl;
	}
	
	return 0;//福摩斯尔：盲生，你发现了华点。
}
