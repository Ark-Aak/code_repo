#include<bits/stdc++.h>
using namespace std;
int n,m,tot1[3],x[2005],y[2005],tot2,flag;
char a[2005][2005];
int b1(int x,int y) {
	if(a[x-1][y]=='0'&&a[x][y-1]=='0'&&a[x-1][y-1]=='1') return 0;
	if(a[x-1][y]=='1'&&a[x][y-1]=='1'&&a[x-1][y-1]=='0') return 1;
	return -1;
}
int b2(int x,int y) {
	if(a[x-1][y]=='0'&&a[x][y+1]=='0'&&a[x-1][y+1]=='1') return 0;
	if(a[x-1][y]=='1'&&a[x][y-1]=='1'&&a[x-1][y+1]=='0') return 1;
	return -1;
}
int b3(int x,int y) {
	if(a[x+1][y]=='0'&&a[x][y-1]=='0'&&a[x+1][y-1]=='1') return 0;
	if(a[x+1][y]=='1'&&a[x][y-1]=='1'&&a[x+1][y-1]=='0') return 1;
	return -1;
}
int b4(int x,int y) {
	if(a[x+1][y]=='0'&&a[x][y+1]=='0'&&a[x+1][y+1]=='1') return 0;
	if(a[x+1][y]=='1'&&a[x][y+1]=='1'&&a[x+1][y+1]=='0') return 1;
	return -1;
}
int main() {
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<=n; i++) a[i][0]='#';
	for(int i=0; i<=m; i++) a[0][i]='#';
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>a[i][j];
			if(a[i][j]=='?') {
				tot1[1]++;
				x[tot1[1]]=i,y[tot1[1]]=j;
			}
		}
	}
	int yh=0;
	while(1) {
		yh=(yh+1)%2;
		tot1[(yh+1)%2]=0;
		for(int i=1; i<=tot1[yh]; i++) {
			if((b1(x[i],y[i])==1||b1(x[i],y[i])==-1)&&(b2(x[i],y[i])==1||b2(x[i],y[i])==-1)&&(b3(x[i],y[i])==1||b3(x[i],y[i])==-1)&&(b4(x[i],y[i])==1||b4(x[i],y[i])==-1)) {
				a[x[i]][y[i]]='1';
			} else {
				if((b1(x[i],y[i])==0||b1(x[i],y[i])==-1)&&(b2(x[i],y[i])==0||b2(x[i],y[i])==-1)&&(b3(x[i],y[i])==0||b3(x[i],y[i])==-1)&&(b4(x[i],y[i])==0||b4(x[i],y[i])==-1)) {
					a[x[i]][y[i]]='0';
				} else {
					if(b1(x[i],y[i])==-1&&b2(x[i],y[i])==-1&&b3(x[i],y[i])==-1&&b4(x[i],y[i])==-1) {
						tot1[(yh+1)%2]++;
						x[tot1[(yh+1)%2]]=x[i],y[tot1[(yh+1)%2]]=y[i];
					} else {
						flag=1;
						break;
					}
				}
			}
		}
		if(tot1[(yh+1)%2]==tot1[yh]||flag==1) break;
	}
	if(flag==1) {
		cout<<"No";
		return 0;
	}
	if(tot1[(yh+1%2)]==0) {
		cout<<"Yes"<<endl;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) cout<<a[i][j];
			cout<<endl;
		}
		return 0;
	}
	
	return 0;
}
