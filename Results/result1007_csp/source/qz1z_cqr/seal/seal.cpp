//20
#include<bits/stdc++.h>
using namespace std;
int n,t,m,res,x,y,a[2005],b[2005],p[2005],o[2005][3],all[4005],pd[4005];
bool c[2005];
void dfs(int l,int xz){
	if(l>n){
		if(xz!=m) return;
		int ans=0;
		for(int i=0;i<=n;i++){
			if(c[i]) ans+=p[i];
			if(c[o[i][0]] && c[o[i][1]]) ans+=o[i][2];
		}res=max(res,ans);
		return;
	}
	dfs(l+1,xz);
	if(xz<m){
		c[l]=1;
		dfs(l+1,xz+1);
		c[l]=0;
	}
}
signed main(){
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	scanf("%d%d%d",&n,&t,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		all[i*2-1]=a[i];
		all[i*2]=b[i];
	}
	sort(all+1,all+1+(n*2));all[n*2+1]=t+1;
	for(int i=1;i<=n;i++){
		int id=lower_bound(all+1,all+1+(n*2),a[i])-all;
		pd[id]=-1;a[i]=id; 
		id=lower_bound(all+1,all+1+(n*2),b[i])-all;
		pd[id]=i;b[i]=id; 
	}pd[n*2+1]=-1;
	for(int i=1;i<=n;i++){
		if(pd[b[i]+1]!=-1)
			p[pd[b[i]+1]]+=(all[b[i]+1]-all[b[i]]);
		else p[0]+=(all[b[i]+1]-all[b[i]]);
		o[i][0]=i;o[i][2]=(all[a[i]+1]-all[a[i]]);
		//cout<<i<<' '<<a[i]<<' '<<pd[a[i]+1]<<'\n';
		if(pd[a[i]+1]!=-1)
			o[i][1]=pd[a[i]+1];
		else o[i][1]=0;
	}c[0]=1;dfs(1,0);
	//for(int i=1;i<=n;i++){cout<<a[i]<<' '<<b[i]<<'\n';}
	//for(int i=0;i<=n;i++){cout<<p[i]<<' ';}cout<<'\n';
	//for(int i=1;i<=n;i++){cout<<o[i][0]<<' '<<o[i][1]<<' '<<o[i][2]<<'\n';}
	printf("%d",res+all[1]-1);
	return 0;
} 
