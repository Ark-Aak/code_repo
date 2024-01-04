#include<bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,b) for(int i=1;i<=b;i++)
using namespace std;
char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=1e6+5;
int a[N],b[N];
bool vis[N];
int ggb[N];
int s[N];
signed main(){
    int n=read(),k=read();
    for(int i=1;i<=k;i++){
        a[i]=read();
        vis[a[i]]=1;
    }
    for(int i=1;i<=k;i++){
        b[i]=read();
        vis[b[i]]=1;
    }
    int gg=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0) gg++;
    }
    for(int i=1;i<=k;i++){
        ggb[b[i]]=i;
    }
    for(int i=1;i<=k;i++){
        if(ggb[a[i]]){
            s[ggb[a[i]]-i+k]++;
            s[ggb[a[i]]+k-i+k]++;
        }
    }
    int ans=0;
    for(int i=0;i<=2*k+1;i++){
        ans=max(ans,s[i]);
    }
    memset(ggb,0,sizeof(ggb));
    memset(s,0,sizeof(s));
    reverse(b+1,b+k+1);
    for(int i=1;i<=k;i++){
        ggb[b[i]]=i;
    }
    for(int i=1;i<=k;i++){
        if(ggb[a[i]]){
            s[ggb[a[i]]-i+k]++;
            s[ggb[a[i]]+k-i+k]++;
        }
    }
    for(int i=0;i<=2*k+1;i++){
        ans=max(ans,s[i]);
    }
    cout<<ans+gg<<endl;
    return 0;
}
