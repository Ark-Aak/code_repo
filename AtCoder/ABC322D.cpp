#include<bits/stdc++.h>
using namespace std;

string s[3][4][4];
bool res[4][4];

void dfs(int x) {
	if(x==3) {
		int ops=1;
		for (int i=0;i<4;i++)for (int j=0;j<4;j++)if(res[i][j]==0)ops=0;
		if(ops==0)return;
		cout<<"Yes";
		exit(0);
	}
	for (int i=0;i<4;i++) {
		for (int j=-3;j<=3;j++) {
			for (int k=-3;k<=3;k++) {
				int ops=1;
				for (int l=0;l<4;l++) {
					for (int m=0;m<4;m++) {
						if(s[x][i][l][m]=='#'&&(l+j<0||l+j>3||m+k<0||m+k>3)) {
							ops=0;
							break;
						}
						if(res[l+j][m+k]==1&&s[x][i][l][m]=='#')ops=0;
					}
				}
				if(!ops)continue;
				for (int l=0;l<4;l++) {
					for (int m=0;m<4;m++) {
						if(s[x][i][l][m]=='#')res[l+j][m+k]=1;
					}
				}
				dfs(x+1);
				for (int l=0;l<4;l++) {
					for (int m=0;m<4;m++) {
						if(s[x][i][l][m]=='#')res[l+j][m+k]=0;
					}
				}
			}
		}
	}
}
signed main() {
	for (int i=0;i<3;i++)
			for (int j=0;j<4;j++)cin>>s[i][0][j];
	for (int i=0;i<3;i++){
			for (int j=1;j<4;j++){
				for (int k=0;k<4;k++){
					for (int l=0;l<4;l++){
						s[i][j][l][3-k]=s[i][j-1][k][l];
					}}}}
	dfs(0);
	cout<<"No";
	return 0;
}
