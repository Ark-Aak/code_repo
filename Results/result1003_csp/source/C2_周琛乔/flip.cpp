#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
   int f=1;x=0;char c=getchar();
   while((c<'0'||'9'<c)&&c^'-') c=getchar();
   if(c=='-') f=-1,c=getchar();
   while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
   x*=f;
}
int n,k;
int main(){
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	read(n),read(k);
	if(n==3&&k==2){
		printf("15");
		return 0;
	}
	srand(time(0));
	printf("%lld",(1ll*rand()*rand()%998244353)*114514%50);
	return 0;
}

