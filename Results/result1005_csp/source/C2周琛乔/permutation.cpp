#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while((c<'0'||c>'9')&&c^'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int n,k;
struct xl{
	int a[N];
	inline void Read(){for(int i=1;i<=n;i++) read(a[i]);}
	inline void print(){for(int i=1;i<=n;i++) printf("%d ",a[i]);}
}a,b,c,tmp;
inline xl add(xl x,xl y){
	for(int i=1;i<=n;i++) tmp.a[x.a[i]]=y.a[i];
	return tmp;
}
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	read(n),read(k);
	b.Read(),c.Read();
	if(k==1){c.print();return 0;}
	--k;
	while(k--){
		a=b,b=c;
		c=add(a,b);
	}
	c.print();
	return 0;
}

