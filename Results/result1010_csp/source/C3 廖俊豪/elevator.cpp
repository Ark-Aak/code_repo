#include<bits/stdc++.h>
#define int long long 
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
int n,k;
int a[500005];
int f[500005];
int q[500005],l,r;
signed main(){
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	read(n,k);
	for(int i=1;i<=n;i++)read(a[i]),a[i]--;
	sort(a+1,a+n+1);
	memset(f,0x3f,sizeof f);
	f[0]=0;
	if(n<=1000||k<=20||n*k<=10000000){
		for(int i=1;i<=n;i++){
			for(int j=i-1;i>=0&&i-j<=k;j--){
				f[i]=min(f[i],f[j]+(n-j)*2*a[i]);
			}
		}
	}else if(k<n){
		l=1,r=1;
		q[1]=0;
		for(int i=1;i<=n;i++){
			while(q[l]<i-k)l++;
			while((f[q[l+1]]-f[q[l]])<=2*a[i]*(q[l+1]-q[l])&&l<r)l++;
			f[i]=f[q[l]]+2*(n-q[l])*a[i];
			while(l<r&&(f[q[r]]-f[q[r-1]])*(i-q[r-1])>(f[i]-f[q[r-1]])*(q[r]-q[r-1])&&(q[r]+k>n||(f[i]-f[q[r]])<=2*a[q[r]+k]*(i-q[r])))r--;
			q[++r]=i;
		}
	}else{
		l=1,r=1;
		q[1]=0;
		for(int i=1;i<=n;i++){
			while(q[l]<i-k)l++;
			while((f[q[l+1]]-f[q[l]])<=2*a[i]*(q[l+1]-q[l])&&l<r)l++;
			f[i]=f[q[l]]+2*(n-q[l])*a[i];
			while(l<r&&(f[q[r]]-f[q[r-1]])*(i-q[r-1])>(f[i]-f[q[r-1]])*(q[r]-q[r-1]))r--;
			q[++r]=i;
		}
	}
	write(f[n]);
	flush();
	return 0;
}
