#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,mod=4294967296;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,Q,sum[N][10],ans;
string s;
void add(int &a,int b){if((a+=b)>=mod) a-=mod;}
signed main(){
	freopen("milky.in","r",stdin);
	freopen("milky.out","w",stdout);
	cin>>s;
	n=s.size();
	s=' '+s;
	Q=read();
	if(n<=1000){//milky
		while(Q--){
			int l=read(),r=read();
			ans=0;			
			for(int i=l-1;i<=r;i++)
				sum[i][2]=sum[i][3]=sum[i][4]=sum[i][5]=0;
			for(int i=l;i<r;i++)
				if(s[i]=='m') sum[i+1][2]++;
			for(int i=l;i<r;i++){
				sum[i][2]+=sum[i-1][2];
				if(s[i]=='i') sum[i+1][3]+=sum[i][2];
			}
			for(int i=l;i<r;i++){
				sum[i][3]+=sum[i-1][3];
				if(s[i]=='l') sum[i+1][4]+=sum[i][3];
			}
			for(int i=l;i<r;i++){
				sum[i][4]+=sum[i-1][4];
				if(s[i]=='k') sum[i+1][5]+=sum[i][4];
			}
			for(int i=l;i<=r;i++){
				sum[i][5]+=sum[i-1][5];
				if(s[i]=='y') ans+=sum[i][5];
			}			

			printf("%lld\n",ans%mod);	
		}
	}
	else{		
		for(int i=1;i<n;i++)
			if(s[i]=='m') sum[i+1][2]++;
		for(int i=1;i<n;i++){
			add(sum[i][2],sum[i-1][2]);
			if(s[i]=='i') add(sum[i+1][3],sum[i][2]);
		}
		for(int i=1;i<n;i++){
			add(sum[i][3],sum[i-1][3]);
			if(s[i]=='l') add(sum[i+1][4],sum[i][3]);
		}
		for(int i=1;i<n;i++){
			add(sum[i][4],sum[i-1][4]);
			if(s[i]=='k') add(sum[i+1][5],sum[i][4]);
		}
		for(int i=1;i<=n;i++){
			add(sum[i][5],sum[i-1][5]);
			if(s[i]=='y') add(sum[i][6],sum[i][5]);
		}			
		for(int i=1;i<=n;i++) add(sum[i][6],sum[i-1][6]);
		while(Q--){
			int l=read(),r=read();
			printf("%lld\n",sum[r][6]);
		}
	}
	return 0;
}
