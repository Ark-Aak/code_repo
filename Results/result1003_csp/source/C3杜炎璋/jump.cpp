#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while('0'<=c && c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	x*=f;
}
int f[500005],a[500005];
int r[500005];
int stk[500005],head=1,tail=0;
int dfs(int x) {
	if(x==0) return 0; 
	if(f[x]) return f[x];
	return f[x]=dfs(r[x])+1;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;i++) read(a[i]); 
	for(int i=n;i>=1;i--) {
		while(head<=tail && a[stk[tail]]<a[i]) r[stk[tail]]=i,tail--;
		stk[++tail]=i;
	}
	while(head<=tail) r[stk[head]]=0,head++;
	for(int i=1;i<=n;i++) dfs(i);
	for(int i=1;i<=n;i++) printf("%d ",f[i]);
	return 0;
}

