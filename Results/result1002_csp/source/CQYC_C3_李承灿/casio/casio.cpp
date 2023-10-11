#include<bits/stdc++.h>
#define N 30000100
using namespace std;
int t,p; 
int n;
int o[N];
int tot,k[N];
void read(int &x){
	x=0;
	int f=1;char s=getchar();
	while(s<'0'||s>'9') if(s=='-')f=-1,s=getchar();
	while(s>='0'&&s<='9'){x=x*10+s-48;s=getchar();}
	x=x*f;
}
signed main(){
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	read(t);read(p);
	o[1]=1;
	for(int i=2;i<=30000020;i++){
		if(o[i]==0) k[++tot]=i;
		for(int j=1;j<=tot&&i*k[j]<=30000020&&k[j]<=p;j++){
			o[i*k[j]]=1;
			if(i%k[j]==0) break;
		}
	}
	while(t--){
		read(n);
		while(true){
			if(o[n]==0) break;
			n++;
		}
		printf("%d\n",n);
	}
	return 0;
}


