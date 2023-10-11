#include<bits/stdc++.h>
#define int long long
#define fi first
#define sd second
using namespace std;
const int N=5e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,ans[N],tp;
pair<int,int> s[N];
signed main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) ans[i]=1;
	for(int i=1;i<=n;i++){
		int x=read();
		while(tp&&s[tp].fi<=x) tp--;
		ans[i]+=ans[s[tp].sd];  
		s[++tp]={x,i};
	}
	for(int i=1;i<=n;i++) 
		printf("%lld ",ans[i]);
	return 0;
}
