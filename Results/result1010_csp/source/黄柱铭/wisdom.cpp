#include<bits/stdc++.h>
#define int long long
#define debug_h for(int i=1;i<=n;i++) cout << h[i] << " ";
#define debug_l for(int i=1;i<=m;i++) cout << l[i] << " ";
using namespace std;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=1e6+5,mod=1e9+7;
int n,m,k,tot;
struct node{
	int op,x,y;
}qu[1005];
int tagh[N],pre[N];
bool cmp(node a,node b){
	return a.op<b.op;
}
int ans,pw[N],sum,id;
void init(){
	for(int i=1;i<=n;i++) tagh[i]=1;
	pw[1]=1;
	for(int i=2;i<=n;i++) pw[i]=(pw[i-1]+m)%mod;
}
signed main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	n=read();m=read();k=read();
//	if(n<=1000){
//		
//	}else{
		init();
		for(int i=1;i<=k;i++){
			char s;int x,y;
			cin >> s;
			x=read();y=read();
			if(s=='R')qu[++tot]=(node){1,x,y};
			else qu[++tot]=(node){2,x,y};
		}
		sort(qu+1,qu+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			if(qu[i].op==1) tagh[qu[i].x]=(tagh[qu[i].x]*qu[i].y)%mod;
			else{id=i;break;}
		}
		for(int i=1;i<=n;i++) sum=(sum+tagh[i])%mod;
		for(int i=1;i<=n;i++) pre[1]=(pre[1]+(pw[i]*tagh[i]%mod))%mod;
		for(int i=2;i<=m;i++) pre[i]=(pre[i-1]+sum)%mod;
		for(int i=id;i<=k;i++)	pre[qu[i].x]=pre[qu[i].x]*qu[i].y%mod;
		for(int i=1;i<=m;i++) ans=(ans+pre[i])%mod;
		cout << ans << "\n";
//	}
	
	return 0;
}


