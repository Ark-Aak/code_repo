//O(nq?) 32pts
#include<bits/stdc++.h>
#define MX 60005
using namespace std;
int n,m,a[MX],b,xl,xr,yl,yr,ans;
vector<int> v[MX];
int lower_b(int t,int pr){
	int l=0,r=v[t].size()-1;
	while(l<r){
		int m=(l+r+1)>>1;
		if(v[t][m]<=pr){l=m;}
		else{r=m-1;}
	}return l;
}
int upper_b(int t,int pl){
	int l=0,r=v[t].size()-1;
	while(l<r){
		int m=(l+r)>>1;
		if(v[t][m]>=pl){r=m;}
		else{l=m+1;}
	}return r;
}
signed main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){scanf("%d",&b);v[a[i]].push_back(b);}
	for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
	while(m--){
		scanf("%d%d%d%d",&xr,&yr,&xl,&yl);b=yl;ans=0;
		for(int i=xr;i>=xl;i--){
			if(!v[i].size()) continue;
			int id1=lower_b(i,yr);
			int id2=upper_b(i,b);
			//cout<<i<<':'<<id1<<' '<<id2<<'\n';
			if(id1<id2) continue;
			if(v[i][id1]>yr) continue;
			if(v[i][id2]<b) continue;
			ans+=(id1-id2+1);
			b=max(b,v[i][id1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

