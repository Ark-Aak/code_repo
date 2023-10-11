#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,k,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();k=read();m=read();
	int ans=1;
	for(int i=1;i<=m;i++){
		int l=read(),r=read(),s=read();
		if(s!=0)ans=0;
	}
	printf("%d",ans);
	return 0;
}

