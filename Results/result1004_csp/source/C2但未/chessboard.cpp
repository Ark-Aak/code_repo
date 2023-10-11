#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<1)+(x<<3)+s-48;s=getchar();}
	return x*f;
}
const int Maxn=2005;
int n,m;
struct node{
	int x,y;
};
int a[Maxn][Maxn],s[Maxn][Maxn];
char ch[Maxn];
queue<node>h;
inline bool pd2(int x,int y){
	if(a[x][y]==0&&a[x][y+1]==1&&a[x+1][y]==1&&a[x+1][y+1]==0)return 0;
	if(a[x][y]==1&&a[x][y+1]==0&&a[x+1][y]==0&&a[x+1][y+1]==1)return 0;
	return 1;
}
inline void over(){
	printf("Yes\n");
	memcpy(s,a,sizeof a);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==2)a[i][j]=0;
	for(int x=1;x<n;x++)
		for(int y=1;y<m;y++){
			if(!pd2(x,y)){
				for(int i=0;i<2;i++)
					for(int j=0;j<2;j++)
					if(s[x+i][y+j]==2)a[x+i][y+j]=!a[x+i][y+j];
			}
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%d",a[i][j]);
		puts("");
	}
}
int f[Maxn][Maxn];
inline int Cnt(int x,int y){
	int cnt=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			if(a[x+i][y+j]==2)cnt++;
	return cnt;
}
int main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for(int j=1;j<=m;j++)
			a[i][j]=(ch[j]=='?'?2:ch[j]-'0');
	}
	node id;int cnt2=1e9;
	for(int x=1;x<n;x++)
		for(int y=1;y<m;y++){
			int cnt=0;
			for(int i=0;i<2;i++)
				for(int j=0;j<2;j++)
					if(a[x+i][y+j]==2)cnt++;
			f[x][y]=cnt;
			if(!pd2(x,y)){
				printf("No");
				return 0;
			}
			if(cnt&&cnt2>cnt){
				cnt2=cnt;
				id={x,y};
			}
		}
	if(cnt2>1){
		over();
		return 0;
	}
	h.push({id.x,id.y});
	while(h.size()){
		node tmp=h.front();
		h.pop();
		f[tmp.x][tmp.y]=Cnt(tmp.x,tmp.y);
		if(!f[tmp.x][tmp.y])continue;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				if(a[tmp.x+i][tmp.y+j]==2){
					a[tmp.x+i][tmp.y+j]=1;
					if(!pd2(tmp.x,tmp.y))a[tmp.x+i][tmp.y+j]=0;
					if(!pd2(tmp.x,tmp.y)){
						printf("No");
						return 0;
					}
				}
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++){
				if(i+j==0||tmp.x+i>=n||tmp.y+j>=m)continue;
				f[tmp.x+i][tmp.y+j]=Cnt(tmp.x+i,tmp.y+j);
				if(f[tmp.x+i][tmp.y+j]==1){
					h.push({tmp.x+i,tmp.y+j});
				}
			}
	}
	int op=1;
	for(int x=1;x<n;x++)
		for(int y=1;y<m;y++)
			if(!pd2(x,y))op=0;
	if(!op)printf("No");
	else over();
	return 0;
}

