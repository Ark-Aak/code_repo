#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}w[5000000];
int n,m,tot,ans[3000][3000],f;
char x;
bool check(int x,int y){
	int xx[5]={0,1,-1,1,-1},yy[5]={0,1,-1,-1,1};
	for(int i=1;i<=4;i++){
		if(ans[x][y]>=0&&ans[x+xx[i]][y]>=0&&ans[x][y]==ans[x+xx[i]][y+yy[i]]&&ans[x][y]!=ans[x+xx[i]][y]&&ans[x+xx[i]][y]==ans[x][y+yy[i]])
			return 0;
	}
	return 1;
}
void dfs(int step,int type){
	if(step>tot){
		cout<<"Yes"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<ans[i][j];
			}
			cout<<endl;
		}
		exit(0);
	}
	for(int i=0;i<=1;i++){
		int x=w[step].x,y=w[step].y;
		ans[x][y]=i;
		if(check(x,y)){
			dfs(step+1,i);
		}
	}
}
int main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			if(x=='1'||x=='0'){
				ans[i][j]=x-'0';
			}
			else{
				w[++tot].x=i;
				w[tot].y=j;
				ans[i][j]=-1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!check(i,j)){
				cout<<"No"<<endl;
			//	cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	dfs(1,1);
	dfs(1,0);
	cout<<"No"<<endl;
	return 0;
}

