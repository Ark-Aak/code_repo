#include <bits/stdc++.h>
#define db double
namespace IO{
    template<typename T>
    void read(T &x){
        char ch=getchar();int fl=1;x=0;
        while(ch>'9'||ch<'0'){if(ch=='-')fl=-1;ch=getchar();}
        while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
        x*=fl;
    }
    template<typename T,typename ...Args>
    void read(T &x,Args& ...args){
        read(x);read(args...);
    }
    template <typename _Tp>
    void write(_Tp x) {
        if(x<0) x=(~x+1),putchar('-');
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
}
using namespace std;
using namespace IO;
const db Inf=1e6;
const int N=1e6+5,M=105;
int n,m,s,t;
db ans,dis[N];
int tot=1,now[N],head[N];

struct node {
    int to,net;
    db val;
} e[N];

void add(int u,int v,db w) {
    e[++tot].to=v; e[tot].val=w;
    e[tot].net=head[u]; head[u]=tot;
    e[++tot].to=u; e[tot].val=0;
    e[tot].net=head[v]; head[v]=tot;
}

int bfs() {
    for(int i=0;i<=t;i++) dis[i]=Inf;
    queue<int> q;
    dis[s]=0; q.push(s); now[s]=head[s];
    while(!q.empty()) {
        int x=q.front(); q.pop();
        for(int i=head[x];i;i=e[i].net) {
            int v=e[i].to;
            if(e[i].val>0 && dis[v]==Inf) {
                q.push(v);
                now[v]=head[v];
                dis[v]=dis[x]+1;
                if(v==t) return 1;
            }
        }
    }
    return 0;
}

db dfs(int x,db sum) {
    if(x==t) return sum;
    db k,res=0;
    for(int i=now[x];i && sum;i=e[i].net) {
        now[x]=i;
        int v=e[i].to;
        if(e[i].val>0 && (dis[v]==dis[x]+1)) {
            k=dfs(v,min(sum,e[i].val));
            if(k==0) dis[v]=Inf;
            e[i].val-=k; e[i^1].val+=k;
            res+=k; sum-=k;
        }
    }
    return res;
}
int a[M][M],id[M][M],cnt;
int dx[5]={-1,1,0,0},dy[5]={0,0,-1,1};
const db pos1=1.0,pos2=sqrt(2)/2.0;
signed main() {
    read(n,m);
    s=0,t=5e4;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++) {
            if(s[j]=='#') a[i][j+1]=1;
        }
    }
    for(int i=0;i<=n+1;i++) {
        for(int j=0;j<=m+1;j++) {
            id[i][j]=++cnt;
        }
    }
    for(int i=1;i<=m;i++) {
        add(s,id[0][i]*4+2,Inf);
        add(s,id[n+1][i]*4,Inf);
    }
    for(int i=1;i<=n;i++) {
        add(s,id[i][0]*4+1,Inf);
        add(s,id[i][m+1]*4+3,Inf);
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            add(id[i][j]*4,id[i][j]*4+1,pos2);
            add(id[i][j]*4+1,id[i][j]*4+2,pos2);
            add(id[i][j]*4+2,id[i][j]*4+3,pos2);
            add(id[i][j]*4+3,id[i][j]*4,pos2);

            add(id[i][j]*4+1,id[i][j]*4,pos2);
            add(id[i][j]*4+2,id[i][j]*4+1,pos2);
            add(id[i][j]*4+3,id[i][j]*4+2,pos2);
            add(id[i][j]*4,id[i][j]*4+3,pos2);
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(!a[i][j]) continue;
            add(id[i][j]*4,t,Inf);
            add(id[i][j]*4+1,t,Inf);
            add(id[i][j]*4+2,t,Inf);
            add(id[i][j]*4+3,t,Inf);
        }
    }
    for(int i=0;i<=n+1;i++) {
        for(int j=0;j<=m+1;j++) {
            for(int p=0;p<=3;p++) {
                int xx=i+dx[p],yy=j+dy[p];
                if(xx<0 || yy<0 || yy>m+1 || xx>n+1) continue;
                if(i<xx) add(id[i][j]*4+2,id[xx][yy]*4,pos1);
                if(xx<i) add(id[i][j]*4,id[xx][yy]*4+2,pos1);
                if(j<yy) add(id[i][j]*4+1,id[xx][yy]*4+3,pos1);
                if(yy<j) add(id[i][j]*4+3,id[xx][yy]*4+1,pos1);
            }
        }
    }
    while(bfs()) {
        ans+=dfs(s,Inf);
    }
    cerr << tot << endl;
    printf("%.11lf",ans);
    return 0;
}
