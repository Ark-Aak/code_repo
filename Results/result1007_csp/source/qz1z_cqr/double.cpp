//30
#include<bits/stdc++.h>
#define GP pair<int,int>
#define MP make_pair
#define int long long
using namespace std;
int n,a,b,c,d,q,res[2005][2005];
vector<GP> v[2005];
priority_queue<GP,vector<GP>,greater<GP> >qe;
void add_eg(int x,int y,int w){
	v[x].push_back(MP(w,y));
	v[y].push_back(MP(w,x));
}
signed main(){
	freopen("double.in","r",stdin);
	freopen("double.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		add_eg(i*2-1,i*2,a);
	}
	for(int i=1;i<n;i++){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		add_eg(a*2-1,b*2-1,c);
		add_eg(a*2,b*2,d);
	}
	for(int i=1;i<=n*2;i++){
		memset(res[i],0x3f,sizeof(res[i]));
		res[i][i]=0;
		qe.push(GP(0,i));
		while(qe.size()){//dijk
			GP tp=qe.top();qe.pop();
			int s=tp.first,st=tp.second;
			if(s>res[i][st]) continue;
			for(auto j:v[st]){
				if(s+j.first>=res[i][j.second]) continue;
				res[i][j.second]=s+j.first;
				qe.push(MP(s+j.first,j.second));
			}
		}
	}
	scanf("%lld",&q);
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",res[a][b]);
	}
	return 0;
} 
