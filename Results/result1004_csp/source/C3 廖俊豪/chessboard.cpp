#include<bits/stdc++.h>
#define mk(a,b) make_pair(a,b)
using namespace std;
int n,m;
int a[2005][2005];
char s[2005][2005];
queue<pair<int,int> >q;
void w(int x,int y){
	int res=0;
	int I,J;
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			if(a[x+i][y+j]==0)return;
			if(a[x+i][y+j]==3){
				I=i;J=j;
				res++;
			}
		}
	}
	if(res>2)return;
	if(res==0){
		int ops=0;
		for(int i=0;i<=1;i++){
			for(int j=0;j<=1;j++){
				if(a[x+i][y+j]!=((a[x][y]-1)^i^j)+1)ops=1;
			}
		}
		if(ops==0){
			printf("No");
			exit(0);
		}
		return; 
	}
//	cout<<I<<"-"<<J<<endl;
	a[x+I][y+J]=1;
	int ops_1=0;
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			if(a[x+i][y+j]!=((a[x][y]-1)^i^j)+1)ops_1=1;
		}
	}
	int ops_2=0;
	a[x+I][y+J]=2;
	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			if(a[x+i][y+j]!=((a[x][y]-1)^i^j)+1)ops_2=1;
		}
	}
	if(ops_1==0&&ops_2==0){
		printf("No");
		exit(0);
	}
	if(ops_1==0){
		a[x+I][y+J]=2;
		q.push(mk(x+I,y+J));
	}else{
		a[x+I][y+J]=1;
		q.push(mk(x+I,y+J));
	}
}
void check(int x,int y){
	w(x-1,y-1);
	w(x-1,y);
	w(x,y-1);
	w(x,y);
}
void bfs(){
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
//		printf("(%d,%d)\n",x,y);
		q.pop();
		check(x,y);
	}
}
signed main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			if(s[i][j]=='0')a[i][j]=1;
			else if(s[i][j]=='1')a[i][j]=2;
			else a[i][j]=3;
			if(a[i][j]!=3)q.push(mk(i,j));
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			printf("%d ",a[i][j]-1);
//		}printf("\n");
//	}
	bfs();
	printf("Yes\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==3){
				a[i][j]=1;
				q.push(mk(i,j));
				bfs();
			}
			printf("%d",a[i][j]-1);
		}printf("\n");
	}
	return 0;
}
