#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=100005;
int n,p,ans;
int a[N],inv[N],an[N],vis[N],tr[N];
bool fl=0;
int lowbit(int x){
	return x&(-x);
}
void add(int x){
	for(;x<=n;x+=lowbit(x)) tr[x]++;
}
int query(int x){
	int ans=0;
	for(;x;x-=lowbit(x)) ans+=tr[x];
	return ans;
}
signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	n=read();p=read();
	if(n%2){
		inv[0]=1;
		for(int i=1;i<=n;i++) inv[i]=inv[i-1]*i%p;
		ans=inv[n];
		cout << ans;
	} else{
		int ans=0;
		for(int i=1;i<=n;i++) a[i]=i;
		
		do{
			for(int i=1;i<=n;i++){
				ans+=query(n)-query(i);
				ans%=p;
				add(a[i]);
			}
			memset(tr,0,sizeof(tr));
		}while(next_permutation(a+1,a+n+1));
		cout << ans << "\n";
	}
	
	
	return 0;
}


