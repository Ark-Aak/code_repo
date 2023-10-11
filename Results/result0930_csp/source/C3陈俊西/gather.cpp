#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,BN=5e3+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,num[N],ans;
int s[BN][BN],tp[BN],cnt[N];
vector<int> Q[N],C[N];
int tr[N];
int lb(int x){return x&(-x);}
int add(int x,int k){for(;x;x-=lb(x)) tr[x]+=k;}
int sum(int x){int res=0;for(;x<=n;x+=lb(x)) res+=tr[x];return res;}
signed main(){
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) num[i]=read();
	if(n<=5000){
		for(int i=1;i<=n;i++)
			s[num[i]][++tp[num[i]]]=i;
		for(int l=1;l<n;l++){
			for(int i=1;i<=n;i++) cnt[i]=0;
			for(int i=1;i<=l;i++) cnt[num[i]]++;
			for(int r=l+1;r<=n;r++){
				cnt[num[r]]++;
				if(s[num[r]][cnt[num[r]]-1]==l) break;
				if(s[num[r]][cnt[num[r]]-1]<l) ans++;
			}
		}	
		printf("%lld",ans);
	}
	else{
		for(int i=1;i<=n;i++)
			Q[num[i]].emplace_back(i);
		for(int i=1;i<=n;i++) cnt[i]=-1;
		for(int i=1;i<=n;i++){
			int v=num[i];
			cnt[v]++;				
			if(cnt[v]>0)
				ans+=(Q[v][cnt[v]]-Q[v][cnt[v]-1]-1-sum(Q[v][cnt[v]-1])+sum(Q[v][cnt[v]])),add(Q[v][cnt[v]-1],1);
			else 
				ans+=(Q[v][cnt[v]]-1-sum(1)+sum(Q[v][cnt[v]]));
		}
		printf("%lld",ans);
	}
	return 0;
}
