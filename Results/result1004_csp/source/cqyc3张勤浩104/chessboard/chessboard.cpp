#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=1010;
int n,m;
char a[Maxn][Maxn],copy_a[Maxn][Maxn]; 
bool flg=0;
vector<pair<int,int> >qs,hsh;
inline bool check(int x,int y,int k){
	if(a[x-1][y]=='1'&&a[x][y+1]=='1'&&a[x-1][y+1]=='0'&&k==0) return 0;
	if(a[x-1][y]=='0'&&a[x][y+1]=='0'&&a[x-1][y+1]=='1'&&k==1) return 0;
	if(a[x-1][y]=='1'&&a[x][y-1]=='1'&&a[x-1][y-1]=='0'&&k==0) return 0;
	if(a[x-1][y]=='0'&&a[x][y-1]=='0'&&a[x-1][y-1]=='1'&&k==1) return 0;
	if(a[x+1][y]=='1'&&a[x][y+1]=='1'&&a[x+1][y+1]=='0'&&k==0) return 0;
	if(a[x+1][y]=='0'&&a[x][y+1]=='0'&&a[x+1][y+1]=='1'&&k==1) return 0;
	if(a[x+1][y]=='1'&&a[x][y-1]=='1'&&a[x+1][y-1]=='0'&&k==0) return 0;
	if(a[x+1][y]=='0'&&a[x][y-1]=='0'&&a[x+1][y-1]=='1'&&k==1) return 0;
	return 1;
}
inline bool checkIsRight(void){
	bool Isflg=0;
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++){
			if(a[i][j]=='1'&&a[i+1][j+1]=='1'&&a[i+1][j]=='0'&&a[i][j+1]=='0') Isflg=1;
			if(a[i][j+1]=='1'&&a[i+1][j]=='1'&&a[i][j]=='0'&&a[i+1][j+1]=='0') Isflg=1; 
		}
	if(Isflg) return 0;
	return 1;
}
int main(){
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='?') qs.push_back(make_pair(i,j));
		}
	if(!checkIsRight()){
		printf("No");
		return 0;
	}
	int alltest=1e8/n/m;
	for(int test=1;test<=alltest;test++)
	for(auto i:qs){
		if(check(i.first,i.second,1)&&check(i.first,i.second,0));
		else if(check(i.first,i.second,1)) a[i.first][i.second]='1';
		else if(check(i.first,i.second,0)) a[i.first][i.second]='0';
		else{
			flg=1;
			break;
		}
	}
	if(flg){
		printf("No");
		return 0;
	}
	if(!checkIsRight()){
		printf("No");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			copy_a[i][j]=a[i][j];
			if(a[i][j]=='?'){
				hsh.push_back(make_pair(i,j));
				if(hsh.size()>20) break;
			}
		}
	int thek=hsh.size();
	bool ceryflg=0;
 	for(int i=0;i<(1<<thek);i++){
 		for(int j=0;j<thek;j++){
 			if(i&(1<<j))
 				copy_a[hsh[j].first][hsh[j].second]='1';	
			else 
				copy_a[hsh[j].first][hsh[j].second]='0';
		}
		ceryflg|=checkIsRight();
		if(ceryflg==1){
			for(int j=0;j<thek;j++)
				a[hsh[j].first][hsh[j].second]=copy_a[hsh[j].first][hsh[j].second];	
		}
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='?')
				a[i][j]=(i+j)%2?'1':'0';
	if(!checkIsRight()){
		printf("No");
		return 0;
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++){
			if(a[i][j]=='?') cout<<1;
			else cout<<a[i][j];
		}
	return 0;
}
/*
3 3
010
1?1
010

3 3
01?
1?0
?01

4 4
01??
1?01
?10?
01?1

4 4
01?1
1?10
00?1
1?0?
*/

