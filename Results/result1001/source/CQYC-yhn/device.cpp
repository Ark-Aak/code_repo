#include<bits/stdc++.h>
using namespace std;
int T,n,k,dis[1005][1005],sum[15],qian[1005],hou[1005],cnt[1005][15],ans[1005][1005];
vector<int> e;
queue<int> q;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
signed main(){
    freopen("device.in","r",stdin);
    freopen("device.out","w",stdout);
    for(int i=111;i<=999;i++){
        int a1=i%10,a2=(i/10)%10,a3=i/100;
        if(!a1||!a2||!a3) continue;
        e.push_back(i);
        int t=i;
        while(t){
            cnt[i][t%10]++;
            t/=10;
        }
    }
    memset(dis,-1,sizeof(dis));
    for(int i=0;i<(int)e.size();i++){
        memset(qian,0,sizeof(qian));
        memset(hou,0,sizeof(hou));
        hou[0]=e[0];qian[e[0]]=0;
        hou[e[0]]=e[1];
        for(int j=1;j<((int)e.size()-1);j++){
            qian[e[j]]=e[j-1];
            hou[e[j]]=e[j+1];
        }
        // if(e[i]==123){
        //     for(int j=hou[0];j;j=hou[j]) cout<<j<<"\n";
        // }
        q.push(e[i]);dis[e[i]][e[i]]=0;
        while(!q.empty()){
            int t=q.front();q.pop(); 
            t*=13;t*=11;t*=7;
            for(int j=1;j<10;j++) sum[j]=0;
            int o=t;
            while(o){
                sum[o%10]++;
                o/=10;
            }
            for(int j=hou[0];j;j=hou[j]){
                // if(e[i]==123) cout<<j<<" "<<hou[j]<<"\n";
                bool f=1;
                for(int g=1;g<10;g++){
                    if(sum[g]<cnt[j][g]){
                        f=0;
                        break;
                    }
                }
                // if(e[i]==123) cout<<j<<" "<<f<<"\n";
                if(f){
                    qian[hou[j]]=qian[j];
                    hou[qian[j]]=hou[j];
                    q.push(j);
                    dis[e[i]][j]=dis[e[i]][q.front()]+1;
                }
            }
        }
    }
    for(int i=0;i<(int)e.size();i++){
        for(int j=0;j<(int)e.size();j++){
            ans[e[i]][dis[e[i]][e[j]]]++;
        }
    }
    for(int i=0;i<(int)e.size();i++){
        for(int j=1;j<=1000;j++) ans[e[i]][j]+=ans[e[i]][j-1];
    }
    T=read();
    while(T--){
        k=read(),n=read();
        n=min(n,(int)1000);
        cout<<ans[k][n]<<"\n";
    }
    return 0;
}