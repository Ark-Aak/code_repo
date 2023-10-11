#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int Maxn = 1e6+5;
const int Maxk = 1e3+5;
const int MOD = 1e9+7;
const int inv = 5e8+4;

inline int read(){
	int x = 0,f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch <= '9' && ch >= '0')
		x = x*10+ch-'0',ch = getchar();
	return x * f;
}

int N , M , K , ans ,cr , cc;
int DR[Maxn],DC[Maxn];
int Gr[Maxk],Gc[Maxk],Mr[Maxk],Mc[Maxk];

inline int calc(int i,int j){
	return ((LL)(i-1)*M+j) % MOD;
}

int Count(int A1,int d,int n){
	LL tmp =  (LL) A1 * n  % MOD;
	tmp += (LL)n*(n - 1)%MOD*inv%MOD*d%MOD;
	if(tmp >= MOD) tmp -= MOD;
	return tmp;
}

void upd(int &x , int y){
	x += y;
	if(x >= MOD) x -= MOD;
}

int main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	N = read(); M = read(); K = read();
	ans = Count(1 , 1 , (LL)N*M%MOD);
	char ch; int x,y; 
	while(K--){
		ch = getchar();
		while(ch != 'R'&& ch != 'S') ch = getchar(); 
		x = read(); y = read();
		if(ch == 'R'){
			if(!DR[x]) DR[x] = ++cr,Gr[cr] = x,Mr[cr] = 1;
			Mr[DR[x]] = (LL)Mr[DR[x]] * y % MOD; 
		}
		if(ch == 'S'){
			if(!DC[x]) DC[x] = ++cc,Gc[cc] = x,Mc[cc] = 1;
			Mc[DC[x]] = (LL) Mc[DC[x]] * y % MOD;
		}
	}
	for(int i = 1 ; i <= cr ; ++i){
		upd(ans , (LL)Count(calc(Gr[i],1),1,M)*(Mr[i]-1+MOD)%MOD);
		//printf("%d %d %lld\n",Gr[i],Mr[i],(LL)Count(calc(Gr[i],1),1,M)*(Mr[i]-1+MOD)%MOD);
	}
	for(int i = 1 ; i <= cc ; ++i){
		upd(ans , (LL)Count(calc(1,Gc[i]),M,N)*(Mc[i]-1+MOD)%MOD);
		//printf("%d %d %lld\n",Gc[i],Mc[i],(LL)Count(calc(1,Gc[i]),M,N)*(Mc[i]-1+MOD)%MOD);
	} 
	for(int i = 1 ; i <= cr ; ++i)
	for(int j = 1 ; j <= cc ; ++j){
		//printf("%d %d\n",calc(Gr[i],Gc[j]),Mr[i]*Mc[j] - Mr[i] - Mc[j] + 1);
		upd(ans,(LL)calc(Gr[i],Gc[j])*(((LL)Mr[i]*Mc[j] - Mr[i] - Mc[j] + 1)%MOD + MOD)%MOD);
	}
	printf("%d\n",ans);
	return 0;
}
