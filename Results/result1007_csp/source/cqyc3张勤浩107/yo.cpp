#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=1e6+7;
int n,f[2][12];
short flg[Maxn];
bool ans=1;
char s[Maxn],t[Maxn];
vector<int>sodayo;
int main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=1;i<=n;i++) if(t[i]=='o') sodayo.push_back(i);
	int suki=sodayo.size();
	if(suki==n){
		printf("oimiya");
		return 0;
	}
	if(suki+log2(n)<=25){
		
		for(int i=0;i<(1<<suki);i++){
			memset(f,0,sizeof f);
			for(int j=0;j<suki;j++) flg[sodayo[j]]=0;
			for(int j=0;j<suki;j++) if(i&(1<<j)) flg[sodayo[j]]=1;else flg[sodayo[j]]=2;
			f[0][0]=1;
			for(int j=1;j<=n;j++){
				for(int k=0;k<11;k++){
					if(flg[j]==1) f[1][(k*10)%11]|=f[0][k];
					if(flg[j]==2) f[1][(k*10+(s[j]-'0'))%11]|=f[0][k];
					if(flg[j]==0) f[1][(k*10+(s[j]-'0'))%11]|=f[0][k],
								  f[1][(k*10)%11]|=f[0][k];
				}
				for(int k=0;k<11;k++){
					swap(f[0][k],f[1][k]);
					f[1][k]=0;
				}
			}
			ans&=f[0][0];
		}
	}
	else{
		ans&=(suki<=n/4);
	}
	printf("%s",ans?"yoimiya":"oimiya");
	return 0;
}
/*
6
121121
yyyyyy

5
19755
yoyyy
*/

