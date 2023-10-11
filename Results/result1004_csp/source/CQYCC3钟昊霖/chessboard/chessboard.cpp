#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=2e3+5;

int a[N][N],n,m;
bool b[N][N];

char c;

bool check(int x,int y){
	if(x<1) return true;
	if(y<1) return true;
	if(x>n) return true;
	if(y>m) return true;
	return false;
}

inline void Check(int i1,int j1,int i2,int j2,int i3,int j3,int i4,int j4,int i5,int j5){
	if(check(i1,j1)) return;
	if(check(i2,j2)) return;
	if(check(i3,j3)) return;
	if(check(i4,j4)) return;
	if(a[i1][j1]!=a[i4][j4]) return;
	if(a[i2][j2]!=a[i3][j3]) return;
	if(a[i1][j1]==a[i2][j2]) return;
	if(a[i1][j1]!=a[i2][j2]){
		if(b[i1][j1]) b[i1][j1]=0,a[i1][j1]=1;
		else if(b[i2][j2]) b[i2][j2]=0,a[i2][j2]=1;
		else if(b[i3][j3]) b[i3][j3]=0,a[i3][j3]=1;
		else if(b[i4][j4]) b[i4][j4]=0,a[i4][j4]=1;
	}
	return;
}

inline void Check1(int i1,int j1,int i2,int j2,int i3,int j3,int i4,int j4,int i5,int j5){
	if(check(i1,j1)) return;
	if(check(i2,j2)) return;
	if(check(i3,j3)) return;
	if(check(i4,j4)) return;
//	cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<" "<<i3<<" "<<j3<<" "<<i4<<" "<<j4<<endl; 
	if(a[i1][j1]!=a[i4][j4]) return;
	if(a[i2][j2]!=a[i3][j3]) return;
	if(a[i1][j1]==a[i2][j2]) return;
	cout<<"No";
	exit(0);
	return;
}


int main() {
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	scanf("%d%d",&n,&m);
	F(i,1,n) {
		F(j,1,m) {
		cin>>c; 
			if(c=='1') a[i][j]=1;
			else a[i][j]=0;
			if(c=='?') b[i][j]=1;
		}
	}
	F(i,1,n)
	F(j,1,m)
	Check(i,j,i,j+1,i+1,j,i+1,j+1,i,j);//Check(i,j-1,i,j,i+1,j-1,i+1,j,i,j),Check(i-1,j,i-1,j+1,i,j,i,j+1,i,j),Check(i-1,j-1,i-1,j,i,j-1,i,j,i,j);
	F(i,1,n)
	F(j,1,m)
	Check1(i,j,i,j+1,i+1,j,i+1,j+1,i,j);
	cout<<"Yes"<<endl;
	F(i,1,n){ F(j,1,m) {printf("%d",a[i][j]);}putchar('\n');}
	return 0;
}
