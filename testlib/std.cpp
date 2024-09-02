#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char s[500005];
int n,q;
int t[500005][31],f[500005][31];

int main(){
	
	scanf("%s%d",s+1,&q);
	n=strlen(s+1);
	
	for(int i=1;i<=n+2;i++){
		for(int j=0;j<=26;j++){
			t[i][j]=n+2;		// 边界
			f[i][j]=n+2;
		}
	}
	
	for(int i=n;i>=1;i--){		// DP
		int nw=s[i]-'a';
		t[i][nw]=i+1;
		for(int j=nw+1;j<=26;j++){
			t[i][j]=t[t[i][j-1]][j-1];
		}
		for(int j=0;j<nw;j++){
			t[i][j]=t[t[i][26]][j];
		}
	}
	
	for(int i=1;i<=n;i++){				// 倍增预处理
		f[i][0]=t[i][26];
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		r++;
		for(int j=20;j>=0;j--){			// 倍增跳转
			if(f[l][j]<=r){
				l=f[l][j];
			}
		}
		if(l==r){
			puts("Yes");
		}else{
			puts("No");
		}
	}
	
	return 0;
}


