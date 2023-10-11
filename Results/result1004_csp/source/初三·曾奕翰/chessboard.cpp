#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[5005][5005];
int ans[500005];
signed main() {
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",a[i]+1);
	int T=10;
	while(T--){
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				if(a[i][j]=='1'&&a[i+1][j]=='0'&&a[i][j+1]=='0'&&a[i+1][j+1]=='?')
					a[i+1][j+1]='0';
				if(a[i][j]=='?'&&a[i+1][j]=='0'&&a[i][j+1]=='0'&&a[i+1][j+1]=='1')
					a[i][j]='0';
				if(a[i][j]=='1'&&a[i+1][j]=='?'&&a[i][j+1]=='0'&&a[i+1][j+1]=='1')
					a[i+1][j]='1';
				if(a[i][j]=='1'&&a[i+1][j]=='0'&&a[i][j+1]=='?'&&a[i+1][j+1]=='1')
					a[i][j+1]='1';
				if(a[i][j]=='0'&&a[i+1][j]=='1'&&a[i][j+1]=='1'&&a[i+1][j+1]=='?')
					a[i+1][j+1]='1';
				if(a[i][j]=='0'&&a[i+1][j]=='1'&&a[i][j+1]=='?'&&a[i+1][j+1]=='0')
					a[i][j+1]='0';
				if(a[i][j]=='0'&&a[i+1][j]=='?'&&a[i][j+1]=='1'&&a[i+1][j+1]=='0')
					a[i+1][j]='0';
				if(a[i][j]=='?'&&a[i+1][j]=='1'&&a[i][j+1]=='1'&&a[i+1][j+1]=='0')
					a[i][j]='0';
				if(a[i][j]=='?'&&a[i+1][j]=='1'&&a[i][j+1]=='1'&&a[i+1][j+1]=='?')
					a[i][j]='1';
				if(a[i][j]=='1'&&a[i+1][j]=='?'&&a[i][j+1]=='?'&&a[i+1][j+1]=='1'){
					a[i][j+1]='1';
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(a[i][j]=='1'&&a[i+1][j]=='0'&&a[i][j+1]=='0'&&a[i+1][j+1]=='1'){
				cout<<"No";
				return 0;
			}
			if(a[i][j]=='0'&&a[i+1][j]=='1'&&a[i][j+1]=='1'&&a[i+1][j+1]=='0'){
				cout<<"No";
				return 0;
			}
			
		}
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='?') printf("0");
			else printf("%c",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
