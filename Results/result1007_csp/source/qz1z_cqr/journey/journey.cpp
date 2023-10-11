#include<bits/stdc++.h>
#define GP pair<int,int>
#define MP make_pair
using namespace std;
int n,m,q,l,r,a,b,c[1005][1005],res[1005];
vector<GP> v[1005];
priority_queue<GP,vector<GP>,greater<GP> >qe;
signed main(){
	/*freopen("journey2.out","r",stdin);
	string s;
	for(int i=1;i<=1000000;i++){
		cin>>s;
		if(s=="Yes") a++;
	}
	cout<<a;
	return 0;*/
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		v[a].push_back(MP(i,b));
		v[b].push_back(MP(i,a));
		c[a][b]=c[b][a]=i;
	} 
	while(q--){
		scanf("%d%d%d%d",&l,&r,&a,&b);
		if(a==b){
			printf("Yes\n");
			continue;
		}
		if(l==r){
			if(c[a][b]>=l && c[a][b]<=r) printf("Yes\n");
			else printf("No\n");
			continue;
		}
		memset(res,0x3f,sizeof(res));
		qe.push(GP(l,a));res[a]=l;
		while(qe.size()){//dijk
			GP tp=qe.top();qe.pop();
			int s=tp.first,st=tp.second;
			if(s>res[st]) continue;
			//cout<<s<<' '<<st<<'\n';
			for(auto i:v[st]){
				if(i.first<s) continue;
				if(i.first>=res[i.second]) continue;
				//cout<<'-'<<i.first<<' '<<i.second<<' '<<res[i.second]<<'\n';
				res[i.second]=i.first;
				qe.push(MP(i.first,i.second));
			}
		}
		if(res[b]<=r) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
