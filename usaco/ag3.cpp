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
const int N=1e5+5;
int a[N];
int ans=0;
int yuan[N];
int vis[N];
int x=0;
signed main(){
    int t=read(),c=read();
    memset(a,-0x3f,sizeof(a));
    for(int i=1;i<=t;i++){
        a[i]=read();
    }
    sort(a+1,a+t+1);
    string s;
    cin>>s;
    int L=1e16,R=1e16,F=1e16;
    for(int i=0;i<c;i++){
        if(s[i]=='L') x--,L=min(L,i);
        if(s[i]=='R') x++,R=min(R,i);
        if(s[i]=='F'){
            F=min(F,i);
            int p=lower_bound(a+1,a+t+1,x)-a;
            if(a[p]==x){
                yuan[p]++;
            }
        }
    }
    memset(vis,0,sizeof(vis));
    int gg=0;
    for(int i=1;i<=t;i++){
        vis[i]=yuan[i];
        if(yuan[i]) gg++;
    }
    //L->R
    int now=x;
    for(int i=c-1;i>=0;i--){
        if(s[i]=='L') now++,ans=max(ans,gg);
        if(s[i]=='R') now--;
        if(s[i]=='F'){
            int p=lower_bound(a+1,a+t+1,now+2)-a;
            int p2=lower_bound(a+1,a+t+1,now)-a;
            if(a[p]==now+2){
                if(vis[p]==0) gg++;
                vis[p]++;
            }
            if(a[p2]==now){
                vis[p2]--;
                if(vis[p2]==0) gg--;
            }

        }
    }
    // cout<<ans<<endl;
    //R-L
    gg=0;
    for(int i=1;i<=t;i++){
        vis[i]=yuan[i];
        if(yuan[i]) gg++;
    }
    now=x;
    for(int i=c-1;i>=0;i--){
        if(s[i]=='L') now++;
        if(s[i]=='R') now--,ans=max(ans,gg);
        if(s[i]=='F'){
            int p=lower_bound(a+1,a+t+1,now-2)-a;
            int p2=lower_bound(a+1,a+t+1,now)-a;
            if(a[p]==now-2){
                if(vis[p]==0) gg++;
                vis[p]++;
            }
            if(a[p2]==now){
                vis[p2]--;
                if(vis[p2]==0) gg--;
            }

        }
    }
    // cout<<ans<<endl;
    //L->F
    gg=0;
    for(int i=1;i<=t;i++){
        vis[i]=yuan[i];
        if(yuan[i]) gg++;
    }
    now=x;
    for(int i=c-1;i>=0;i--){
        if(s[i]=='L'){
            now++;
            int p=lower_bound(a+1,a+t+1,now)-a;
            if(a[p]==now){
                if(vis[p]==0) ans=max(ans,gg+1);
            }
        }
        if(s[i]=='R') now--;
        if(s[i]=='F'){
            int p=lower_bound(a+1,a+t+1,now)-a;
            int p2=lower_bound(a+1,a+t+1,now)-a;
            if(a[p]==now){
                if(vis[p]==0) gg++;
                vis[p]++;
            }
            if(a[p2]==now){
                vis[p2]--;
                if(vis[p2]==0) gg--;
            }

        }
    }
    // cout<<ans<<endl;
    //r->F
    gg=0;
    for(int i=1;i<=t;i++){
        vis[i]=yuan[i];
        if(yuan[i]) gg++;
    }
    now=x;
    for(int i=c-1;i>=0;i--){
        if(s[i]=='L')
            now++;
        if(s[i]=='R'){
            now--;
            int p=lower_bound(a+1,a+t+1,now)-a;
            if(a[p]==now){
                if(vis[p]==0) ans=max(ans,gg+1);
            }
        }
        if(s[i]=='F'){
            int p=lower_bound(a+1,a+t+1,now-1)-a;
            int p2=lower_bound(a+1,a+t+1,now)-a;
            if(a[p]==now-1){
                if(vis[p]==0) gg++;
                vis[p]++;
            }
            if(a[p2]==now){
                vis[p2]--;
                if(vis[p2]==0) gg--;
            }

        }
    }
    // cout<<ans<<endl;
    //F->L
    gg=0;
    for(int i=1;i<=t;i++){
        vis[i]=yuan[i];
        if(yuan[i]) gg++;
    }
    now=x;
    for(int i=c-1;i>=0;i--){
        if(s[i]=='L')
            now++;
        if(s[i]=='R'){
            now--;
        }
        if(s[i]=='F'){
            int p=lower_bound(a+1,a+t+1,now-1)-a;
            int p2=lower_bound(a+1,a+t+1,now)-a;
            ans=max(ans,gg);
            if(a[p]==now-1){
                if(vis[p]==0) gg++;
                vis[p]++;
            }
            if(a[p2]==now){
                vis[p2]--;
                if(vis[p2]==0) gg--;
            }

        }
    }
    //F->R
    // cout<<ans<<endl;

    gg=0;
    for(int i=1;i<=t;i++){
        vis[i]=yuan[i];
        if(yuan[i]) gg++;
    }
    now=x;
    for(int i=c-1;i>=0;i--){
        if(s[i]=='L')
            now++;
        if(s[i]=='R'){
            now--;
        }
        if(s[i]=='F'){
            int p=lower_bound(a+1,a+t+1,now+1)-a;
            int p2=lower_bound(a+1,a+t+1,now)-a;
            ans=max(ans,gg);
            if(a[p]==now+1){
                if(vis[p]==0) gg++;
                vis[p]++;
            }
            if(a[p2]==now){
                vis[p2]--;
                if(vis[p2]==0) gg--;
            }

        }
    }
    cout<<ans<<endl;
    return 0;
}
