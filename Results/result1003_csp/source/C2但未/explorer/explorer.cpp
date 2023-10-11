#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Maxn=5e5+5;
int n;
int a[Maxn],b[Maxn];
ll ans;
int cnt;
inline void solve20(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(a[i]>a[j]&&a[j]>b[j]&&b[j]>a[k]&&a[k]>b[k]&&b[k]>b[i])ans++;
				if(b[j]<a[j]&&a[j]<b[k]&&b[k]<a[k]&&a[k]<b[i]&&b[i]<a[i])ans++;
				if(a[i]>a[j]&&a[j]>a[k]&&a[k]>b[i]&&b[i]>b[j]&&b[j]>b[k])ans++;
			}
	printf("%lld",ans);
}
int main(){
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read();
		if(a[i]<b[i])swap(a[i],b[i]);
		if(a[i]==b[i]+1)cnt++;
	}
	ans=1ll*cnt*(cnt-1)*(cnt-2)/6ll;
	if(cnt==n){
		printf("%lld",ans);
		return 0;
	}
	if(n<=1000)solve20();
	return 0;
}

