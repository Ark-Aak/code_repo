#include<bits/stdc++.h>
using namespace std;
namespace IO{
    char buff[1<<21],*p1=buff,*p2=buff;
    char getch(){
        return p1==p2&&(p2=((p1=buff)+fread(buff,1,1<<21,stdin)),p1==p2)?EOF:*p1++;
    }
    template<typename T>
    void read(T &x){
        char ch=getch();int fl=1;x=0;
        while(ch>'9'||ch<'0'){if(ch=='-')fl=-1;ch=getch();}
        while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getch();}
        x*=fl;
    }
    template<typename T,typename ...Args>
    void read(T &x,Args& ...args){
        read(x);read(args...);
    }
    char obuf[1<<21],*p3=obuf;
    void putch(char ch){
        if(p3-obuf<(1<<21))*p3++=ch;
        else fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=ch;
    }
    char ch[100];
    template<typename T>
    void write(T x){
        if(!x)return putch('0');
        if(x<0)putch('-'),x*=-1;
        int top=0;
        while(x)ch[++top]=x%10+48,x/=10;
        while(top)putch(ch[top]),top--;
    }
    template<typename T,typename ...Args>
    void write(T x,Args ...args){
        write(x);write(args...);
    }
    void flush(){fwrite(obuf,p3-obuf,1,stdout);}
}
using namespace IO; 
int n,T;
int s[5005][5005];
struct node{
	int x,y;
}p[1000005];
bool cmp(node A,node B){
	if(A.x!=B.x)return A.x<B.x;
	else return A.y>B.y;
}
inline int ask(int L,int R,int D,int U){
	if(L>R||D>U)return 0;
	return s[R][U]-s[L-1][U]-s[R][D-1]+s[L-1][D-1];
}
inline int sol(int L,int R,int D,int U){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(p[i].x<L||p[i].x>R)continue;
		if(p[i].y<D||p[i].y>U)continue;
		if(ask(p[i].x+1,R,p[i].y+1,U)==0)ans++;
	}
	return ans;
}
signed main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	read(n,T);
	for(int i=1;i<=n;i++)read(p[i].x);
	for(int i=1;i<=n;i++)read(p[i].y);
	for(int i=1;i<=n;i++)s[p[i].x][p[i].y]++;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)s[i][j]+=s[i-1][j];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)s[i][j]+=s[i][j-1];
	while(T--){
		int L,R,U,D;
		read(R,U,L,D);
		write(sol(L,R,D,U));putch('\n');
	}
	flush();
	return 0;	
}
