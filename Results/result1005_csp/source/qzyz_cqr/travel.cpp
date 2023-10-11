#include<bits/stdc++.h>
using namespace std;
int n,k,m,l,r,p;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&l,&r,&p);
		if(p){printf("0\n");return 0;}
	}printf("1\n");
	return 0;
} 
