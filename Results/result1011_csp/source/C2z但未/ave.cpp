#include<bits/stdc++.h>
//100
using namespace std;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
const int Maxn=1e6+5;
int n,x;
double a[Maxn];
int main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(x);
		a[i]=x;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		a[i]=(a[i]+a[i-1])/2;
	}
	printf("%.6lf",a[n]);
	return 0;
}

