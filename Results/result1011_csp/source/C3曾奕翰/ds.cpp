#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
		x=x*10+c-'0',c=getchar();
	return x*f;
}
int ans;
int n,Q;
int x[100005];
int y[100005];
int minx[100005];
int px[100005];
int miny[100005];
int py[100005];
int minmh[100005];
int pmh[100005];
int main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]),minx[i]=1e9;
	for(int i=1;i<=n;i++)
		scanf("%d",&y[i]),miny[i]=1e9,minmh[i]=1e9;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(x[i]<x[j]&&y[i]<y[j]){
				if(x[j]<minx[i]){
					minx[i]=x[j];
					px[i]=j;
				}
				if(y[j]<miny[i]){
					miny[i]=y[j];
					py[i]=j;
				}
				if((x[j]-x[i])+(y[j]-y[i])<minmh[i]){
					
					minmh[i]=(x[j]-x[i])+(y[j]-y[i]);
					pmh[i]=j;
				} 
			}
		}
	}
	while(Q--){
		int u=read(),r=read(),d=read(),l=read();
		ans=0;
		for(int i=1;i<=n;i++){
			if(x[i]>=d&&x[i]<=u&&y[i]>=l&&y[i]<=r){
				if(n<=0){
					int flag=1;
					for(int j=1;j<=n;j++){
						if(x[j]>=d&&x[j]<=u&&y[j]>=l&&y[j]<=r){
							
							if(x[i]<x[j]&&y[i]<y[j]){
								flag=0;
								break;
							}
						}
					}
					if(flag) ans++;
				}
				else{
					if((px[i]==0||x[px[i]]>u||y[px[i]]>r)&&(py[i]==0||x[py[i]]>u||y[py[i]]>r)&&(pmh[i]==0||x[pmh[i]]>u||y[pmh[i]]>r)){
						ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

