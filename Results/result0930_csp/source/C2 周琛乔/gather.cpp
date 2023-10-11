#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
inline void read(int &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
int n,x,lst[N],t[N],s[N];
long long ans;
inline void add(int x,int v){
	++x;
	for(;x<=n+1;x+=x&-x) t[x]+=v;
}
inline int get(int x){
	int ans=0;++x;
	for(;x;x-=x&-x) ans+=t[x];
	return ans; 
}
int main(){
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(x);
		ans+=get(lst[x])-lst[x];
		add(lst[x],1);
		lst[x]=i;
	} 
	printf("%lld",ans);
	return 0;
} 

