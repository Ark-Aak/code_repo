#include<bits/stdc++.h>
using namespace std;
bitset<30000005> vis;
int prime[2000005],cnt,w[30000005],f[30000005],tot,qu[300005];
inline void read(int &x){
	x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while('0'<=c && c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	x*=f;
}
inline void find(int x,int p) {
	prime[++cnt]=1;
	w[1]=1e9;
	for(int i=2;i<=x;i++) {
		if(!vis[i]) prime[++cnt]=i,w[i]=i;
		if(w[i]>p) f[++tot]=i;
		for(int j=2;i*prime[j]<=x && j<=cnt;j++) {
			vis[prime[j]*i]=1;
			w[prime[j]*i]=min(w[i],prime[j]);
		}
	}
}
int main(){
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	int n,p,maxn=0;
	read(n),read(p);
	for(int i=1;i<=n;i++) read(qu[i]),maxn=max(maxn,qu[i]);
	find(maxn+10,p);
	for(int i=1;i<=n;i++) {
		int t=qu[i];
		if(t<p) {
			int l=1,r=cnt;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(prime[mid]<t) l=mid+1;
				else r=mid-1;
			}
			printf("%d\n",prime[l]);	
		} else {
			int l=1,r=tot;
			while(l<=r) {
				int mid=(l+r)>>1;
				if(f[mid]<t) l=mid+1;
				else r=mid-1;
			}
			printf("%d\n",f[l]);
		}
	}
	return 0;
}

// fc ex_casio.out casio.out

