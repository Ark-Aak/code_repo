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
int n,m,k,ans,tot_1,tot_2;
struct node{
	int x,y,ops;
}p[1005];
int h[1000005],l[1000005];
int H[1005],L[1005];
map<long long int,int>asd;
inline long long int num(int x,int y){
	return 1ll*(x-1ll)*m+1ll*y;
}
signed main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	read(n,m,k);
	for(int i=1;i<=k;i++){
		char x=getch();
		if(x=='R'){
			read(p[i].x,p[i].y);
			p[i].ops=1;
			H[++tot_1]=p[i].x;
		}else{
			read(p[i].x,p[i].y);
			p[i].ops=2;
			L[++tot_2]=p[i].x;
		}
	}
	sort(H+1,H+tot_1+1);
	sort(L+1,L+tot_2+1);
	ans=n*m%mod;
	ans=(ans*ans%mod+ans)%mod;
	ans=(1ll*ans*500000004ll)%mod;
	for(int i=1;i<=n;i++)h[i]=(((1ll*m*m)%mod*1ll*(i-1ll))%mod+(1ll*(m+1)*m/2)%mod)%mod;
	for(int i=1;i<=m;i++)l[i]=(1ll*(1ll*(1ll*(n-1)*m+2ll*i)%mod*n)%mod*500000004ll)%mod;
	for(int i=1;i<=tot_1;i++){
		if(H[i]==H[i-1])continue;
		for(int j=1;j<=tot_2;j++){
			if(L[j]==L[j-1])continue;
			asd[num(H[i],L[j])]=(1ll*(H[i]-1)*m+1ll*L[i])%mod;
		}
	}
	for(int i=1;i<=k;i++){
		if(p[i].ops==1){
			ans=(ans+mod+(1ll*(p[i].y-1ll)*h[p[i].x])%mod)%mod;
			h[p[i].x]=(1ll*h[p[i].x]*p[i].y)%mod;
			for(int j=1;j<=tot_2;j++){
				if(L[j]==L[j-1])continue;
				asd[num(p[i].x,L[j])]=(asd[num(p[i].x,L[j])]*p[i].y)%mod;
			}
		}else{
			ans=(ans+mod+(1ll*(p[i].y-1ll)*l[p[i].x])%mod)%mod;
			l[p[i].x]=(1ll*l[p[i].x]*p[i].y)%mod;
			for(int j=1;j<=tot_2;j++){
				if(H[j]==H[j-1])continue;
				asd[num(H[j],p[i].x)]=(asd[num(H[j],p[i].x)]*p[i].y)%mod;
			}
		}
	}
	write(ans);
	flush();
	return 0;
} 
