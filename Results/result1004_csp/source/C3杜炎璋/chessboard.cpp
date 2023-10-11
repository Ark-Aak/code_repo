#include<bits/stdc++.h>
using namespace std;
int a[2005][2005];
int main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	memset(a,0x3f,sizeof a);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			char c;
			cin>>c;
			if(c=='1') a[i][j]=1;
			else if(c=='0') a[i][j]=0;
			else if(c=='?') a[i][j]=3;
		}
	} 
	for(int i=2;i<=n;i++) {
		for(int j=2;j<=m;j++) {
			if(a[i][j]==1) {
				if(a[i][j-1]==0 && a[i-1][j]==0 && a[i-1][j-1]==1) {printf("No");return 0;}
				if(a[i][j-1]==3 && a[i-1][j]==0 && a[i-1][j-1]==1) a[i][j-1]=1;
				if(a[i][j-1]==0 && a[i-1][j]==3 && a[i-1][j-1]==1) a[i-1][j]=1;
				if(a[i][j-1]==0 && a[i-1][j]==0 && a[i-1][j-1]==3) a[i-1][j-1]=0;
			} else if(a[i][j]==0) {
				if(a[i][j-1]==1 && a[i-1][j]==1 && a[i-1][j-1]==0) {printf("No");return 0;}
				if(a[i][j-1]==3 && a[i-1][j]==1 && a[i-1][j-1]==0) a[i][j-1]=0;
				if(a[i][j-1]==1 && a[i-1][j]==3 && a[i-1][j-1]==0) a[i-1][j]=0;
				if(a[i][j-1]==1 && a[i-1][j]==1 && a[i-1][j-1]==3) a[i-1][j-1]=1;
			} else if(a[i][j]==3) {
				if(a[i][j-1]==0 && a[i-1][j]==0 && a[i-1][j-1]==1) {a[i][j]=0;}
				if(a[i][j-1]==1 && a[i-1][j]==1 && a[i-1][j-1]==0) {a[i][j]=1;}
			}
		}
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(a[i][j]==3) {
				if(a[i][j-1]==1 && a[i-1][j]==1 && a[i-1][j-1]==0) a[i][j]=1;
				else if(a[i][j-1]==0 && a[i-1][j]==0 && a[i-1][j-1]==1) a[i][j]=0;
				else if(a[i-1][j+1]==1 && a[i][j+1]==0 && a[i-1][j]==0) a[i][j]=0;
				else if(a[i-1][j+1]==0 && a[i][j+1]==1 && a[i-1][j]==1) a[i][j]=1;
				else if(a[i+1][j]==1 && a[i][j+1]==1 && a[i+1][j+1]==0) a[i][j]=1;
				else if(a[i+1][j]==0 && a[i][j+1]==0 && a[i+1][j+1]==1) a[i][j]=0;
				else if(a[i+1][j]==1 && a[i][j-1]==1 && a[i+1][j-1]==0) a[i][j]=1;
				else if(a[i+1][j]==0 && a[i][j-1]==0 && a[i+1][j-1]==1) a[i][j]=0;
				else a[i][j]=1;
			} 
			printf("%d",a[i][j]);
		}
		printf("\n"); 
	}
	return 0;
}

