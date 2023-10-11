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
int n,k;
int b[50005];
vector<int>to[50005];
vector<int>w[500005];
int s[55][55];
int last[55];
inline void add(int u,int v,int W){
	to[u].push_back(v);
	w[u].push_back(W);
//	write(u);putch('-');putch('>');write(v);putch('\n');
}
int dis[50005];
int vis[50005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
#define mk(a,b) make_pair(a,b)
void dijk(int S){
	memset(dis,0x7f,sizeof dis);
	dis[S]=0;
	vis[S]=1;
	q.push(mk(0,S));
	while(!q.empty()){
		int x=q.top().second;
//		write(x);putch('-');putch('\n');
		int l=q.top().first;
		q.pop();
		for(int i=0;i<to[x].size();i++){
			int y=to[x][i];
			int W=w[x][i];
			if(b[y]==b[x]&&s[b[x]][b[x]]==0)continue;
			if(dis[y]>dis[x]+W){
				dis[y]=dis[x]+W;
				q.push(mk(dis[y],y));
			}
		}
		vis[x]=1;
	}
	return;
}
signed main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	read(n,k);
	for(int i=1;i<=n;i++)read(b[i]);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			s[i][j]=getch()-'0';
		}
		getch();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(b[i]==j)continue;
			if(s[b[i]][j]==0)continue;
			if(last[j]==0)continue;
			add(i,last[j],i-last[j]);
		}
		if(last[b[i]]!=0)add(i,last[b[i]],i-last[b[i]]);
		last[b[i]]=i;
	}
	memset(last,0,sizeof last);
	for(int i=n;i>=1;i--){
		for(int j=1;j<=k;j++){
			if(b[i]==j)continue;
			if(s[b[i]][j]==0)continue;
			if(last[j]==0)continue;
			add(i,last[j],last[j]-i);
		}
		if(last[b[i]]!=0)add(i,last[b[i]],last[b[i]]-i);
		last[b[i]]=i;
	}
	dijk(1);
	write(dis[n]);
	flush();
}/*
5 4
1 4 2 3 4
1010
0001
0110
0100
*/
