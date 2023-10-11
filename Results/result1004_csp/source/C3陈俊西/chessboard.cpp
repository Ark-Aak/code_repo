#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m;
char s[N][N]; 
signed main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>s[i][j];
	bool lose=0;
	for(int i=1;i<=n&&!lose;i++){
		for(int j=1;j<=m&&!lose;j++){	
			if(i-1>=1&&j-1>=1){
				if(s[i-1][j-1]=='0'&&s[i][j]=='0'&&s[i-1][j]=='1'&&s[i][j-1]=='1') lose=1;
				if(s[i-1][j-1]=='1'&&s[i][j]=='1'&&s[i-1][j]=='0'&&s[i][j-1]=='0') lose=1;
			}
			if(i+1<=n&&j+1<=m){
				if(s[i+1][j+1]=='0'&&s[i][j]=='0'&&s[i+1][j]=='1'&&s[i][j+1]=='1') lose=1;
				if(s[i+1][j+1]=='1'&&s[i][j]=='1'&&s[i+1][j]=='0'&&s[i][j+1]=='0') lose=1;					
			}
			if(i-1>=1&&j+1<=m){
				if(s[i-1][j+1]=='0'&&s[i][j]=='0'&&s[i-1][j]=='1'&&s[i][j+1]=='1') lose=1;
				if(s[i-1][j+1]=='1'&&s[i][j]=='1'&&s[i-1][j]=='0'&&s[i][j+1]=='0') lose=1;	
			}
			if(i+1<=n&&j-1>=1){
				if(s[i+1][j-1]=='0'&&s[i][j]=='0'&&s[i+1][j]=='1'&&s[i][j-1]=='1') lose=1;
				if(s[i+1][j-1]=='1'&&s[i][j]=='1'&&s[i+1][j]=='0'&&s[i][j-1]=='0') lose=1;	
			}
		}
	}
	if(lose){
		printf("No");
		return 0;
	}
	for(int i=1;i<=n&&!lose;i++){
		for(int j=1;j<=m&&!lose;j++){
			if(s[i][j]=='?'){
				int cs=-1,sum=0;
				if(i-1>=1&&j-1>=1){
					if(s[i-1][j-1]=='0'&&s[i-1][j]=='1'&&s[i][j-1]=='1') s[i][j]='1',sum+=(cs!=0),cs=0;
					if(s[i-1][j-1]=='1'&&s[i-1][j]=='0'&&s[i][j-1]=='0') s[i][j]='0',sum+=(cs!=1),cs=1;
				}
				if(i+1<=n&&j+1<=m){
					if(s[i+1][j+1]=='0'&&s[i+1][j]=='1'&&s[i][j+1]=='1') s[i][j]='1',sum+=(cs!=0),cs=0;
					if(s[i+1][j+1]=='1'&&s[i+1][j]=='0'&&s[i][j+1]=='0') s[i][j]='0',sum+=(cs!=1),cs=1;					
				}
				if(i-1>=1&&j+1<=m){
					if(s[i-1][j+1]=='0'&&s[i-1][j]=='1'&&s[i][j+1]=='1') s[i][j]='1',sum+=(cs!=0),cs=0;
					if(s[i-1][j+1]=='1'&&s[i-1][j]=='0'&&s[i][j+1]=='0') s[i][j]='0',sum+=(cs!=1),cs=1;	
				}
				if(i+1<=n&&j-1>=1){
					if(s[i+1][j-1]=='0'&&s[i+1][j]=='1'&&s[i][j-1]=='1') s[i][j]='1',sum+=(cs!=0),cs=0;
					if(s[i+1][j-1]=='1'&&s[i+1][j]=='0'&&s[i][j-1]=='0') s[i][j]='0',sum+=(cs!=1),cs=1;	
				}			
				if(sum>1) lose=1;
			}
		}
	}
	if(lose){
		printf("No");	
		return 0;
	}
	for(int i=1;i<=n&&!lose;i++){
		for(int j=1;j<=m&&!lose;j++){
			if(s[i][j]=='?'){
				bool com=0;
				if(i-1>=1&&j-1>=1){
					if(s[i-1][j-1]=='0'&&s[i-1][j]=='1'&&s[i][j-1]=='1') s[i][j]='1',com=1;
					if(s[i-1][j-1]=='1'&&s[i-1][j]=='0'&&s[i][j-1]=='0') s[i][j]='0',com=1;
				}
				if(i+1<=n&&j+1<=m){
					if(s[i+1][j+1]=='0'&&s[i+1][j]=='1'&&s[i][j+1]=='1') s[i][j]='1',com=1;
					if(s[i+1][j+1]=='1'&&s[i+1][j]=='0'&&s[i][j+1]=='0') s[i][j]='0',com=1;					
				}
				if(i-1>=1&&j+1<=m){
					if(s[i-1][j+1]=='0'&&s[i-1][j]=='1'&&s[i][j+1]=='1') s[i][j]='1',com=1;
					if(s[i-1][j+1]=='1'&&s[i-1][j]=='0'&&s[i][j+1]=='0') s[i][j]='0',com=1;	
				}
				if(i+1<=n&&j-1>=1){
					if(s[i+1][j-1]=='0'&&s[i+1][j]=='1'&&s[i][j-1]=='1') s[i][j]='1',com=1;
					if(s[i+1][j-1]=='1'&&s[i+1][j]=='0'&&s[i][j-1]=='0') s[i][j]='0',com=1;	
				}			
				if(!com) s[i][j]='1';
			}
		}
	}	
	printf("Yes\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout<<s[i][j];
		printf("\n");
	}
	return 0;
}
/*
3 3
01?
1?0
?01
*/
