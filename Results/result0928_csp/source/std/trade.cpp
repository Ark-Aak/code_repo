#include<bits/stdc++.h>
using namespace std;
const int Maxn = 2005;

int N,M,C,f[2][Maxn],o,ans;
int U[Maxn],V[Maxn],Mi[Maxn];

int main(){
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	scanf("%d%d%d",&N,&M,&C);
	for(int i = 1 ; i <= N ; ++i) scanf("%d",&Mi[i]);
	for(int i = 1 ; i <= M ; ++i)
		scanf("%d%d",&U[i],&V[i]);
		
	memset(f[0] , -1 , sizeof f[0]);
	f[0][1] = 0;
	
	for(int i = 1 ; i <= 1000 ; ++i){
		o ^= 1;
		memset(f[o], -1 , sizeof f[o]);
		for(int j = 1 ; j <= M ; ++j) if(f[!o][U[j]] != -1)
			f[o][V[j]] = max(f[o][V[j]],f[!o][U[j]] + Mi[V[j]]);
		ans = max(ans , f[o][1] - i*i*C);
	}
	printf("%d\n",ans);
	return 0;
}
