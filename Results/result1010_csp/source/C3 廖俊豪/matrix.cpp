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
int n,m,ans=1e9;
int s[200005];
int f[1<<12];
int b[1<<12];
inline bits(int x){
	int res=0;
	while(x){
		x-=x&(-x);
		res++;
	}
	return res;
}
signed main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	read(n,m);
	for(int i=0;i<(1<<n);i++)b[i]=bits(i);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char x=getch();
			s[j]=(s[j]<<1)+x-'0';
		}
		getch();
	}
	for(int i=1;i<=m;i++)f[s[i]]++;
	for(int i=0;i<(1<<n);i++){
		int sum=0;
		for(int j=0;j<(1<<n);j++){
			int res=b[j^i];
			res=min(res,n-res);
			sum+=res*f[j];
		}
		ans=min(ans,sum);
	}
	write(ans);
	flush();
	return 0;
} 
