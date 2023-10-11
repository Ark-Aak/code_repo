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
const int mod=1e9+7;
int p[10000005],phi[10000005],tot;
int vis[10000005];
inline int Mod(int x){if(x>=mod)x-=mod;return x;}
void Init(int x){
	for(int i=2;i<=x;i++){
		if(vis[i]==0){
			p[++tot]=i;
			vis[i]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=tot;j++){
			if(p[j]*i>x)break;
			vis[p[j]*i]=p[j];
			if(p[j]==vis[i]){
				phi[p[j]*i]=phi[i]*p[j];
				break;
			}
			phi[p[j]*i]=phi[p[j]]*phi[i];
		}
	}
	for(int i=2;i<=x;i++)phi[i]=Mod(phi[i-1]+phi[i]);
}
int asd[3005][3005]; 
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	Init(1e7);
	for(int i=1;i<=3000;i++)for(int j=1;j<=3000;j++)asd[i][j]=((i+j)/__gcd(i,j))-2;
	for(int i=1;i<=3000;i++)for(int j=1;j<=3000;j++)asd[i][j]=(asd[i][j-1]+asd[i][j])%mod;
	for(int i=1;i<=3000;i++)for(int j=1;j<=3000;j++)asd[i][j]=(asd[i-1][j]+asd[i][j])%mod;
	int T;
	read(T);
	while(T--){
		int n,m;
		read(n,m);
		if(n<=1000&&m<=1000)write(asd[n][m]);
		putch('\n');
	}
	flush();
	return 0;
} 
