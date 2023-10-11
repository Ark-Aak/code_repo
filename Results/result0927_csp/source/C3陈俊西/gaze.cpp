#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,Q,h[N],sum[N],a[N],ans;
struct node{
	int v,cut,id;
}x[N];
bool vis[N];
bool cmp(node a,node b){return a.v<b.v;}
map<int,int> m;
signed main(){
	freopen("gaze.in","r",stdin);
	freopen("gaze.out","w",stdout);
	n=read(),Q=read();
	if(n<=2000){
		for(int i=1;i<=n;i++) h[i]=read();
		while(Q--){
			int opt=read();
			if(opt==1){
				int x=read(),p=n,ct=n-1;
				for(int j=1;j<=n;j++){
					if(h[j]<x){
						p--,ct-=2;
						if(j==n) ct++;
						if(h[j-1]<x) ct++;
					} 		
				}
				printf("%lld\n",p-ct);
			} 
			else{
				int a=read(),b=read();
				h[a]=b;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++) x[i].v=read(),x[i].id=i;
		sort(x+1,x+1+n,cmp);
		vis[0]=vis[n+1]=1;
		for(int i=1;i<=n;i++){
			if(!vis[x[i].id+1]) sum[i]++;
			if(!vis[x[i].id-1]) sum[i]++;
			sum[i]+=sum[i-1];
			vis[x[i].id]=1;
			a[i]=x[i].v;
		}
		while(Q--){
			int opt=read();
			if(opt==1){
				int x=read();
				int xb=upper_bound(a+1,a+1+n,x)-a-1;
				printf("%lld\n",(n-xb)-(n-1-sum[xb]));
			}
			else{
				int a=read(),b=read();
				h[a]=b;
			}
		}
	}
	return 0;
}
