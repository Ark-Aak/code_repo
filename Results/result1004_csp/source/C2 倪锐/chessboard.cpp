/* 
 * 这题 std 代码有多长？
 * 打个暴力算了。
 */

#include<bits/stdc++.h>
#define re register
// #define int long long
#define rep(i,a,b) for(int i(a);i<=(b);++i)
#define req(i,a,b) for(int i(a);i>=(b);--i)
using namespace std;
// char buf[1<<23],*p1=buf,*p2=buf,ubuf[1<<23],*u=ubuf;
// #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template<typename TP> inline TP read(TP &num)
{
	re TP x=0;re int f=0;re char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename TP> inline void write(TP x)
{
	(x<0)?(putchar('-'),x=-x):0;
    (x>9)?(write(x/10),0):0;
	putchar((x%10)^48);
}
template<typename TP> inline void writeln(TP x)
{
	write<TP>(x);
	puts("");
}
int n,m,fill11_1,fill12_1,fill21_1,fill22_1,fill11_2,fill12_2,fill21_2,fill22_2;
char a[2003][2003];
inline void _no_()
{
	puts("No");
	exit(0);
}
inline void _yes_()
{
	puts("Yes");
	rep(i,1,n) cout<<(a[i]+1)<<'\n';
	exit(0);
}
inline void prt(){ rep(i,1,n) cout<<(a[i]+1)<<'\n';}
inline bool chk()
{
	rep(i,1,n-1) rep(j,1,m-1)
	{
		if((a[i][j]!='0'||a[i+1][j]!='1'||a[i][j+1]!='1'||a[i+1][j+1]!='0')&&
		   (a[i][j]!='1'||a[i+1][j]!='0'||a[i][j+1]!='0'||a[i+1][j+1]!='1'));
		else return 0;
	}
	return 1;
}
void dfs(int x,int y)
{
	if(y==m+1) ++x,y=1;
	if(x==n+1) {if(chk()) _yes_();return;}
	if(a[x][y]=='?') a[x][y]='0',dfs(x,y+1),a[x][y]='1',dfs(x,y+1);
	else dfs(x,y+1);
}
signed main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	read(n);read(m);
	rep(i,1,n)rep(j,1,m)while(!isdigit(a[i][j])&&a[i][j]!='?')a[i][j]=getchar();
	dfs(1,1);
	_no_();
	return 0;
	rep(_,1,10)rep(i,1,n) rep(j,1,m)
	{
		if(a[i][j]!='?') continue;
		fill11_1=fill12_1=fill21_1=fill22_1=-1;
		fill11_2=fill12_2=fill21_2=fill22_2=-1;
		// figure 1 is as follows
		if(i>1&&j>1) if(a[i-1][j]=='1'&&a[i][j-1]=='1'&&a[i-1][j-1]=='0') fill11_1=1;
		if(i<n&&j<m) if(a[i+1][j]=='1'&&a[i][j+1]=='1'&&a[i+1][j+1]=='0') fill12_1=1;
		if(i>1&&j<m) if(a[i-1][j]=='0'&&a[i][j+1]=='0'&&a[i-1][j+1]=='1') fill21_1=0;
		if(i<n&&j>1) if(a[i][j-1]=='0'&&a[i+1][j]=='0'&&a[i+1][j-1]=='1') fill22_1=0;
		if(fill11_1!=-1&&fill12_1!=-1&&(fill11_1^fill12_1)) _no_();
		if(fill21_1!=-1&&fill22_1!=-1&&(fill21_1^fill22_1)) _no_();
		// figure 2 is as follows
		if(i>1&&j>1) if(a[i-1][j]=='0'&&a[i][j-1]=='0'&&a[i-1][j-1]=='1') fill11_2=0;
		if(i<n&&j<m) if(a[i+1][j]=='0'&&a[i][j+1]=='0'&&a[i+1][j+1]=='1') fill12_2=0;
		if(i>1&&j<m) if(a[i-1][j]=='1'&&a[i][j+1]=='1'&&a[i-1][j+1]=='0') fill21_2=1;
		if(i<n&&j>1) if(a[i][j-1]=='1'&&a[i+1][j]=='1'&&a[i+1][j-1]=='0') fill22_2=1;
		if(fill11_2!=-1&&fill12_2!=-1&&(fill11_2^fill12_2)) _no_();
		if(fill21_2!=-1&&fill22_2!=-1&&(fill21_2^fill22_2)) _no_();
		// check
		int tian=-1,tian1=-1;
		if(fill11_1!=-1) tian=fill11_1;
		if(fill12_1!=-1&&tian==-1) tian=fill12_1;
		else if(fill12_1!=-1&&tian!=fill12_1) _no_();
		if(fill21_1!=-1&&tian==-1) tian=fill21_1;
		else if(fill21_1!=-1&&tian!=fill21_1) _no_();
		if(fill22_1!=-1&&tian==-1) tian=fill22_1;
		else if(fill22_1!=-1&&tian!=fill22_1) _no_();
		if(fill11_2!=-1) tian1=fill11_1;
		if(fill12_2!=-1&&tian1==-1) tian1=fill12_2;
		else if(fill12_2!=-1&&tian1!=fill12_2) _no_();
		if(fill21_2!=-1&&tian1==-1) tian1=fill21_2;
		else if(fill21_2!=-1&&tian1!=fill21_2) _no_();
		if(fill22_2!=-1&&tian1==-1) tian1=fill22_2;
		else if(fill22_2!=-1&&tian1!=fill22_2) _no_();
		
		if(tian!=-1&&tian1!=-1&&tian!=tian1) _no_();

		if(tian!=-1) a[i][j]=tian+48;
		else if(tian1!=-1) a[i][j]=tian1+48;
		cout<<i<<" "<<j<<" "<<tian<<" "<<tian1<<endl;
	}
	_yes_();
	return 0; 
}
