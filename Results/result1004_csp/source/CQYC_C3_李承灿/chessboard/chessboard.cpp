#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[2003][2003];
int w[5][5],e[5][5];
char a[2003][2003];
signed main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	w[1][1]=w[2][2]=1;
	e[1][2]=e[2][1]=1;
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			int sum1=0,sum2=0,z=0;
			for(int x=i;x<=i+1;x++){
				for(int y=j;y<=j+1;y++){
					if(a[x][y]=='?'){z++;continue;}
					if(a[x][y]-'0'==w[x-i+1][y-j+1]) sum1++;
					if(a[x][y]-'0'==e[x-i+1][y-j+1]) sum2++;
				}
			}
			if(sum1==4||sum2==4){printf("No\n");return 0;}
			if((sum1==3||sum2==3)&&z==1){
				if(a[i][j]=='?') a[i][j]=a[i+1][j];
				else if(a[i][j+1]=='?') a[i][j+1]=a[i][j];
				else if(a[i+1][j]=='?') a[i+1][j]=a[i][j];
				else a[i+1][j+1]=a[i+1][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='?') ans[i][j]=1;
			else ans[i][j]=a[i][j]-'0';
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			int sum1=0,sum2=0;
			for(int x=i;x<=i+1;x++){
				for(int y=j;y<=j+1;y++){
					if(ans[x][y]==w[x-i+1][y-j+1]) sum1++;
					if(ans[x][y]==e[x-i+1][y-j+1]) sum2++;
				}
			}
			if(sum1==4||sum2==4){
				int z=0;
				for(int x=i;x<=i+1;x++){
					for(int y=j;y<=j+1;y++){
						if(a[x][y]=='?'){
							a[x][y]='1';
							ans[x][y]^=1;
							z=1;
							break;
						}
					}
					if(z==1) break;
				}
				if(z==0){printf("No\n");return 0;}
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			int sum1=0,sum2=0;
			for(int x=i;x<=i+1;x++){
				for(int y=j;y<=j+1;y++){
					if(ans[x][y]==w[x-i+1][y-j+1]) sum1++;
					if(ans[x][y]==e[x-i+1][y-j+1]) sum2++;
				}
			}
			if(sum1==4||sum2==4){printf("No\n");return 0; }
		}
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout<<ans[i][j];
		cout<<'\n';
	}
	return 0;
}


