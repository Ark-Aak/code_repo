#include<bits/stdc++.h>
using namespace std;
string s,t;
int n,f[1000002][11],g[100002][11];
int main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	scanf("%d",&n);
	cin>>s>>t;
	s=" "+s;
	t=" "+t;
	memset(f,-1,sizeof f);
	f[1][0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=10;j++) 
			if(f[i][j]>0) f[i+1][(j*10+(s[i]-'0'))%11]=f[i][j];
		for(int j=0;j<=10;j++) 
			if(f[i][j]>0) f[i+1][(j*10)%11]=f[i][j];
	}
	memset(g,-1,sizeof g);
	for(int j=0;j<=10;j++) {
		if(f[n+1][j]>0) {
			if(t[n]=='y' && j==0) g[n+1][j]=1;
			else g[n+1][j]=0;
		}
	}
	for(int i=n;i>=1;i--) {
		if(t[i]=='o') {
			for(int j=0;j<=10;j++) 
				if(f[i][j]) {
					if(g[i+1][(j*10)%11]==0 || g[i+1][(j*10+(s[i]-'0'))%11]==0) g[i][j]=0;
					else g[i][j]=1;
				}
		} else {
			for(int j=0;j<=10;j++) 
				if(f[i][j]) {
					if(g[i+1][(j*10)%11]==1 || g[i+1][(j*10+(s[i]-'0'))%11]==1) g[i][j]=1;
					else g[i][j]=0;
				}
		}
	}
	if(g[1][0]>0) printf("yoimiya");
	else printf("oimiya");
	return 0;
}
/*
2
00
yy 
*/

