#include <bits/stdc++.h>
using namespace std;
#define N 2005
int n,m,hd,tl;char a[N][N];struct Node {int x,y;}nw,q[N*N];
char f(char x) {return x=='0'?'1':'0';}
bool upd(int x,int y)
{
	if(!x || !y || x==n || y==m) return 1;int cnt=0;if(a[x][y]=='?') ++cnt;if(a[x+1][y]=='?') ++cnt;
	if(a[x][y+1]=='?') ++cnt;if(a[x+1][y+1]=='?') ++cnt;if(cnt>1) return 1;
	if(!cnt) return a[x][y]==a[x+1][y] || a[x][y]==a[x][y+1] || a[x][y]!=a[x+1][y+1];
	if(a[x][y]==a[x+1][y+1])
	{
		if(a[x+1][y]=='?' && a[x][y]!=a[x][y+1]) a[x+1][y]=f(a[x][y+1]),q[++tl]=(Node) {x+1,y};
		if(a[x][y+1]=='?' && a[x][y]!=a[x+1][y]) a[x][y+1]=f(a[x+1][y]),q[++tl]=(Node) {x,y+1};
	}
	if(a[x+1][y]==a[x][y+1])
	{
		if(a[x][y]=='?' && a[x+1][y]!=a[x+1][y+1]) a[x][y]=f(a[x+1][y+1]),q[++tl]=(Node) {x,y};
		if(a[x+1][y+1]=='?' && a[x+1][y]!=a[x][y]) a[x+1][y+1]=f(a[x][y]),q[++tl]=(Node) {x+1,y+1};
	}return 1;
}
int main()
{
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);	
	scanf("%d %d",&n,&m);hd=1;tl=0;nw.x=nw.y=1;for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(a[i][j]!='?') q[++tl]=(Node) {i,j};
	while(1)
	{
		if(hd>tl)
		{
			while(nw.x<=n && a[nw.x][nw.y]!='?') if(nw.y<m) ++nw.y;else ++nw.x,nw.y=1;
			if(nw.x>n) break;a[nw.x][nw.y]='0';q[++tl]=nw;
		}Node t=q[hd++];
		if(!upd(t.x,t.y)) {printf("No\n");return 0;}if(!upd(t.x-1,t.y)) {printf("No\n");return 0;}
		if(!upd(t.x,t.y-1)) {printf("No\n");return 0;}if(!upd(t.x-1,t.y-1)) {printf("No\n");return 0;}
	}printf("Yes\n");for(int i=1;i<=n;++i,putchar('\n')) for(int j=1;j<=m;++j) putchar(a[i][j]);return 0;
}