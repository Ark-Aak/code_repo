#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,k,p[N],q[N],cp[N],cq[N],c[N];
signed main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=n;i++) q[i]=read();
	if(k<=1000&&n<=1000){
		for(int i=1;i<k;i++){
			for(int j=1;j<=n;j++) c[p[j]]=q[j];
			for(int j=1;j<=n;j++) p[j]=q[j];
			for(int j=1;j<=n;j++) q[j]=c[j];
		}
		for(int i=1;i<=n;i++) 
			printf("%lld ",q[i]);
	}
	else{
		for(int i=1;i<=n;i++) cp[i]=p[i],cq[i]=q[i];
		int len=0;
		while(true){
			for(int j=1;j<=n;j++) c[p[j]]=q[j];
			for(int j=1;j<=n;j++) p[j]=q[j];
			for(int j=1;j<=n;j++) q[j]=c[j];
			len++;			
			bool same=1;
			for(int j=1;j<=n&&same;j++)
				if(p[j]!=cp[j]) same=0;
			for(int j=1;j<=n&&same;j++)
				if(q[j]!=cq[j]) same=0;	
			if(same) break;		
		}
		k++;
		k=k%len;
		if(k==0) k=len;
		if(k==1){
			for(int i=1;i<=n;i++) 
			printf("%lld ",p[i]);
			return 0;		
		}
		else if(k==2){
			for(int i=1;i<=n;i++) 
			printf("%lld ",q[i]);
			return 0;				
		}
		else{
			k-=2;
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++) c[p[j]]=q[j];
				for(int j=1;j<=n;j++) p[j]=q[j];
				for(int j=1;j<=n;j++) q[j]=c[j];			
			}
			for(int i=1;i<=n;i++) 
				printf("%lld ",q[i]);			
		}

	}
	return 0;
}
/*
5 100
4 5 1 2 3
3 2 1 5 4
*/

