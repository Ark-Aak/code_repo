#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Maxn=1e5+5;
char s[Maxn];
vector<int>t[26];
int sum[Maxn][26];
int ans=1e9;
int main(){
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		t[s[i]-'a'].push_back(i);
		for(int j=0;j<26;j++)
			sum[i][j]=sum[i-1][j];
		sum[i][s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		int mx=sum[n][i],len=t[i].size();
		for(int j=0;j<len;j++){
			if(j){
				for(int k=0;k<26;k++)
					if(k!=i)mx+=max(0,sum[t[i][j]][k]-sum[t[i][j-1]-1][k]-1);
			}
			if(t[i][j]==n)break;
			if(j==len-1){
				mx++;
				for(int k=0;k<26;k++)
					if(k!=i)mx+=max(0,sum[n][k]-sum[t[i][j]][k]-1);
			}
		}
		if(len)ans=min(ans,mx);
	}
	printf("%d\n",ans);
	return 0;
}

