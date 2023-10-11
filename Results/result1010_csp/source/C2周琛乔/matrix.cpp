#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
int n,m,ans=2e9,len[1<<18],cnt[1<<18],sum,c[23];
char s[23][200005];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	read(n),read(m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<(1<<n);i++) len[i]=len[i-(i&-i)]+1;
	for(int i=1,z;i<=m;i++){
		z=0;
		for(int j=0;j<n;j++)
			if(s[j][i]=='1')
				z+=(1<<j);
		++cnt[z];
	}
	for(int i=0;i<(1<<n);i++){
		sum=0;
		for(int j=0;j<(1<<n);j++)
			c[len[i^j]]+=cnt[j];
		for(int j=0;j<=n;j++){
			sum+=min(j,n-j)*c[j];
			c[j]=0;		
		}
		ans=min(ans,sum);
	}
	printf("%d",ans);
	return 0;
}

