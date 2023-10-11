#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define sd second
const int N=1e6+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,h[N],ans[N],ml[N],mr[N],tp;
pair<int,int> s[N];
signed main(){
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) h[i]=read();
	
	if(n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(h[j]<=h[i]) ans[i]++;
				else j=0;			
			}
			for(int j=i+1;j<=n;j++){
				if(h[j]<=h[i]) ans[i]++;
				else j=n+1;						
			}
		}
		for(int i=1;i<=n;i++)
			printf("%lld\n",ans[i]);
	}
	else{
		tp=0;
		s[++tp]={h[1],1};
		for(int i=2;i<=n;i++){
			while(tp>0&&s[tp].fi<h[i]) mr[s[tp].sd]=i-1,tp--;
			s[++tp]={h[i],i};
		}
		while(tp) mr[s[tp].sd]=n,tp--;
		
		s[++tp]={h[n],n};
		for(int i=n-1;i>=1;i--){
			while(tp>0&&s[tp].fi<h[i]) ml[s[tp].sd]=i+1,tp--;
			s[++tp]={h[i],i};
		}
		while(tp) ml[s[tp].sd]=1,tp--;
		
		for(int i=1;i<=n;i++)
			printf("%lld\n",mr[i]-ml[i]);
	}
	return 0;
}	
