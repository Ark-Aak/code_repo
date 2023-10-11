#include<bits/stdc++.h>
using namespace std;
const int Maxn=3e7+5+200;
int T,p;
bool s[Maxn];
int f[Maxn];
int ans[Maxn];
vector<int>a[Maxn];
int ans1;
int main(){
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	scanf("%d%d",&T,&p);
	for(int i=2;i<Maxn;i++)
		if(!s[i]){
			f[i]=i;
			for(int j=i<<1;j<Maxn;j+=i){
				s[j]=1;
				f[j]=min(i,f[j/i]);
			}
		}
	int cnt=0,last=0;
	for(int i=2;i<Maxn;i++)
		if(!s[i])cnt=max(cnt,i-last),last=i;
	for(int i=Maxn-2;i>1;i--)
		if(!s[i])ans[i]=i;
		else ans[i]=ans[i+1];
	while(T--){
		int n;scanf("%d",&n);
		int p1=ans[n];
		if(p1==n){
			printf("%d\n",n);
			continue;
		}
		for(int i=n;i<ans[n];i++)
			if(f[i]>p){
				p1=i;break;
			}
		printf("%d\n",p1);
	}
	return 0;
}

