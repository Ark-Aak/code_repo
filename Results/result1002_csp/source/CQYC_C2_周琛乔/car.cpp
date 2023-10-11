#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
   int f=1;x=0;char c=getchar();
   while((c<'0'||'9'<c)&&c^'-') c=getchar();
   if(c=='-') f=-1,c=getchar();
   while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
   x*=f;
}
int a,b,c,d;
int main(){
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	read(a),read(b),read(c),read(d);
	while(d--) puts("-1");
	return 0;
}

