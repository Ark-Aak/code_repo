#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
}
int n,f[N][11];
char a[N],s[N];
bool F(int i,int j){
	if(i>n) return (j==0);
	if(f[i][j]!=-1) return f[i][j];
	if(s[i]=='o') return f[i][j]=(F(i+1,(j*10)%11)&&F(i+1,(j*10+a[i]-'0')%11));
	return f[i][j]=(F(i+1,(j*10)%11)||F(i+1,(j*10+a[i]-'0')%11));
}
int main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	memset(f,-1,sizeof(f));
	read(n);
	scanf("%s",a+1);
	scanf("%s",s+1);
	puts(F(1,0)?"yoimiya":"oimiya");	
	return 0;
}

