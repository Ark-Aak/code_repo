#include<bits/stdc++.h>
#define ll long long
#define f1 first
#define s2 second
#define N 3005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
int a[N][N],cnt[N];
ll n,m;
queue<pair<ll,ll> > q;
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("chessboard.in","r",stdin);
    freopen("chessboard.out","w",stdout);
    cin>>n>>m;
    string s;
    memset(a,2,sizeof(a));
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='?'){
                a[i][j+1]=2;
                q.push({i,j+1});
            }
            else a[i][j+1]=s[j]-'0';
        }
    }
    while(!q.empty()){
        ll i=q.front().f1,j=q.front().s2;
        q.pop();
        if((a[i-1][j-1]==0&&a[i-1][j]==1&&a[i][j-1]==1)||(a[i-1][j-1]==1&&a[i-1][j]==0&&a[i][j-1]==0)){//左上
            if(a[i][j]==a[i-1][j-1]){
                cout<<"No\n";
                return 0;
            }
            a[i][j]=!a[i-1][j-1];
        }
        if((a[i-1][j+1]==0&&a[i-1][j]==1&&a[i][j+1]==1)||(a[i-1][j+1]==1&&a[i-1][j]==0&&a[i][j+1]==0)){//右上
            if(a[i][j]==a[i-1][j+1]){
                cout<<"No\n";
                return 0;
            }
            a[i][j]=!a[i-1][j+1];
        }
        if((a[i+1][j-1]==0&&a[i+1][j]==1&&a[i][j-1]==1)||(a[i+1][j-1]==1&&a[i+1][j]==0&&a[i][j-1]==0)){//右下
            if(a[i][j]==a[i+1][j-1]){
                cout<<"No\n";
                return 0;
            }
            a[i][j]=!a[i+1][j-1];
        }
        if((a[i+1][j+1]==0&&a[i+1][j]==1&&a[i][j+1]==1)||(a[i+1][j+1]==1&&a[i+1][j]==0&&a[i][j+1]==0)){//右下
            if(a[i][j]==a[i+1][j+1]){
                cout<<"No\n";
                return 0;
            }
            a[i][j]=!a[i+1][j+1];
        }
        if(a[i][j]==2)q.push({i,j});
        ll len=q.size();
        cnt[len]++;
        if(cnt[len]>len)break;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(a[i][j]!=2&&a[i][j]==a[i-1][j-1]&&(!a[i][j])==a[i-1][j]&&(!a[i][j])==a[i][j-1]){
                cout<<"No\n";
                return 0;
            }
        }
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==2){
                if(i!=1&&2==a[i+1][j])a[i][j]=a[i+1][j]=a[i-1][j];
                else if(j!=1&&2==a[i][j+1])a[i][j]=a[i][j+1]=a[i][j-1];
                else if(i!=1)a[i][j]=a[i-1][j];
                else if(j!=1)a[i][j]=a[i][j-1];
                else if(a[i+1][j+1]!=2)a[i][j]=!a[i+1][j+1];
                else a[i][j]=1;
            }
            cout<<(a[i][j]);
        }
        cout<<endl;
    }
    return 0;
}
