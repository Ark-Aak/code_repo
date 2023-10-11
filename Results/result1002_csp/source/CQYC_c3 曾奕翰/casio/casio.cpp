#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}
	return x*f;
}
int n,p;
bool isprime[1000005];
int prime[1000005],tot;
void Euler(){
	isprime[1]=1;
	for(int i=2;i<=1000000;i++){
		if(!isprime[i]){
			prime[++tot]=i;
		}
		for(int j=1;j<=tot;j++){
			if(i*prime[j]>1000000||i*prime[j]<0) break;
			isprime[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
int check(int x){
	for(int i=1;i<=tot;i++){
		if(prime[i]>sqrt(x))
			break;
		if(x%prime[i]==0)
			return prime[i];
	}
	return -1;
}
signed main() {
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	int T=read();
	p=read();
	Euler();
	while(T--){
		n=read();
		while(check(n)<=p){
			if(check(n)==-1) break;
			if(n%2==0) n++;
			else n+=2;
		}
		cout<<n<<endl;
	} 
	return 0;
}

