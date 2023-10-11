#include<bits/stdc++.h>
using namespace std;
bool ck[30000005];
int T,P,n;
signed main(){
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout); 
	scanf("%d%d",&T,&P);
	P=min(P,30000001);
	for(int i=2;i<=P;i++){
	if(!ck[i]){
		for(int j=i*2;j<=30000000;j+=i)
			ck[j]=1;
	}}
	while(T--){
		scanf("%d",&n);
		while(ck[n])n++;
		printf("%d\n",n);
	}
	return 0;
} 
