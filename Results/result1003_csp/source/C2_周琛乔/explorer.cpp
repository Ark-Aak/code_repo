#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
inline void read(int &x){
   int f=1;x=0;char c=getchar();
   while((c<'0'||'9'<c)&&c^'-') c=getchar();
   if(c=='-') f=-1,c=getchar();
   while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
   x*=f;
}
int n,a[N],b[N],x[10];
long long ans;
inline int Cnt(int l,int r){
	int s1=0,s2=0;
	for(int i=1;i<=6;i++){
		if(l<=x[i]&&x[i]<=r) ++s1;
		if(x[i]<=l||r<=x[i]) ++s2;
	}
	return min(s1,s2);
}
inline void sub1(){
	for(int i=1,c;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	for(int k=j+1;k<=n;k++){
		x[1]=a[i],x[2]=b[i];
		x[3]=a[j],x[4]=b[j];
		x[5]=a[k],x[6]=b[k];
		c=Cnt(a[i],b[i]);
		if(c^Cnt(a[j],b[j])) continue;
		if(c^Cnt(a[k],b[k])) continue;
		++ans;
	}
}
inline void sub2(){ans=1ll*n*(n-1)*(n-2)/6;}
bool sb2=1;
int main(){
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]),read(b[i]);
		if(a[i]>b[i]) swap(a[i],b[i]);
		sb2&=(b[i]-a[i]==1);
	}
	if(sb2) sub2();
	else sub1();
	printf("%lld",ans);
	return 0;
}

