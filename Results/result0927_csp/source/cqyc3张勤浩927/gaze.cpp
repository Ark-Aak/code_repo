#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=2e5+7,inf=1e9;
int n,Q,h[Maxn];
//map<vector<int>,int>s;
//bool vis[Maxn];
int main(){
	freopen("gaze.in","r",stdin);
	freopen("gaze.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	h[0]=-inf;
//	if(n<=2000&&Q<=2000){
		while(Q--){
			int opt,x,y;
			scanf("%d%d",&opt,&x);
			if(opt==1){
				int res=0;
				for(int i=1;i<=n;i++){
					if(h[i]>=x&&h[i-1]<x) res++;
				} 
				printf("%d\n",res);
			}
			else{
				scanf("%d",&y);
				h[x]=y;
			}
		}		
		return 0;
//	} 
	return 0;
}
/*
5 4
8
6
3
5
4
1 5
2 4 1
1 5
1 3
*/
