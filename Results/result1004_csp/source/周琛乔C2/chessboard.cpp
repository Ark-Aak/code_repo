#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while((c<'0'||'9'<c)&&c^-'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int n,m;
char s[2005][2005];
inline void change(char &c,char ch){
	if(c^ch){
		if(c=='?') c=ch;
		else puts("No"),exit(0);
	}
}
inline bool m1(int x,int y,int no){
	if(s[x][y]^'0'&&no^1) return 0;
	if(s[x+1][y]^'1'&&no^2) return 0;
	if(s[x][y+1]^'1'&&no^3) return 0;
	if(s[x+1][y+1]^'0'&&no^4) return 0;
	return 1;
}
inline bool m2(int x,int y,int no){
	if(s[x][y]^'1'&&no^1) return 0;
	if(s[x+1][y]^'0'&&no^2) return 0;
	if(s[x][y+1]^'0'&&no^3) return 0;
	if(s[x+1][y+1]^'1'&&no^4) return 0;
	return 1;
}
int main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		if(i>1&&j>1){
			if(m1(i-1,j-1,4)) change(s[i][j],'1');
			if(m2(i-1,j-1,4)) change(s[i][j],'0');
		}
		if(i>1&&j<m){
			if(m1(i-1,j,2)) change(s[i][j],'0');
			if(m2(i-1,j,2)) change(s[i][j],'1');
		}
		if(j>1&&i<n){
			if(m1(i,j-1,3)) change(s[i][j],'0');
			if(m2(i,j-1,3)) change(s[i][j],'1');
		}
		if(i<n&&j<n){
			if(m1(i,j,1)) change(s[i][j],'1');
			if(m2(i,j,1)) change(s[i][j],'0');
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		if(i>1&&j>1){
			if(m1(i-1,j-1,4)) change(s[i][j],'1');
			if(m2(i-1,j-1,4)) change(s[i][j],'0');
		}
		if(i>1&&j<m){
			if(m1(i-1,j,2)) change(s[i][j],'0');
			if(m2(i-1,j,2)) change(s[i][j],'1');
		}
		if(j>1&&i<n){
			if(m1(i,j-1,3)) change(s[i][j],'0');
			if(m2(i,j-1,3)) change(s[i][j],'1');
		}
		if(i<n&&j<n){
			if(m1(i,j,1)) change(s[i][j],'1');
			if(m2(i,j,1)) change(s[i][j],'0');
		}
		if(s[i][j]=='?') s[i][j]='0';
	}
	puts("Yes");
	for(int i=1;i<=n;i++,putchar('\n'))
	for(int j=1;j<=n;j++)
		putchar(s[i][j]);
	return 0;
}

