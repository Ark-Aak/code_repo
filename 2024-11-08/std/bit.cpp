#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
bool st;
const int maxn=2e5+5,inf=(1ll<<31)-1,mod=1e9+7;
const double eps=1e-6;
int n,q;
int a[maxn];
int cnt[40][5];
int tree[maxn<<2][35][5];
int cal(int x){
    int cnt=0;
    while(x){
        if(x%2) cnt++;
        x=x/2;
    }
    return cnt;
}
void pushup(int node){
    for(int k=0;k<=30;k++){
        tree[node][k][1]=(tree[node<<1][k][1]&tree[node<<1|1][k][1]);
        tree[node][k][2]=(tree[node<<1][k][2]|tree[node<<1|1][k][2]);
        tree[node][k][3]=(tree[node<<1][k][3]+tree[node<<1|1][k][3]);
    }
}
void build(int node,int l,int r){
    if(l==r){
        int cnt=cal(a[l]);
        for(int k=0;k<=30;k++){
            if(cnt==k){
                tree[node][k][1]=a[l];
                tree[node][k][2]=a[l];
                tree[node][k][3]=1;
            }else{
                tree[node][k][1]=inf;
                tree[node][k][2]=0;
                tree[node][k][3]=0;
            }
        }
        return ;
    }
    int mid=(l+r)/2;
    build(node<<1,l,mid);
    build(node<<1|1,mid+1,r);
    pushup(node);
}
void query(int node,int L,int R,int l,int r){
    if(L<=l&&r<=R){
        for(int k=0;k<=30;k++){
            cnt[k][1]&=tree[node][k][1];
            cnt[k][2]|=tree[node][k][2];
            cnt[k][3]+=tree[node][k][3];
        }
        return ;
    }
    int mid=(l+r)/2;
    if(mid>=L) query(node<<1,L,R,l,mid);
    if(mid<R)  query(node<<1|1,L,R,mid+1,r);
    return ;
}
bool en;
signed main(){
	freopen("bit.in","r",stdin);
	freopen("bit.out","w",stdout); 
    cerr<<(&en-&st)/1024/1024;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    for(int i=1,l,r;i<=q;i++){
        scanf("%d%d",&l,&r);
        bool flag=0;
        for(int k=0;k<=30;k++){
            cnt[k][1]=inf;
            cnt[k][2]=cnt[k][3]=0;
        }
        query(1,l,r,1,n);
        for(int mid=0;mid<=30;mid++){
            int temp1=0,temp2=inf,num1=0,num2=0;
            for(int k=0;k<=mid;k++){
                temp1|=cnt[k][2];
                num1+=cnt[k][3];
            }
            for(int k=mid+1;k<=30;k++){
                temp2&=cnt[k][1];
                num2+=cnt[k][3];
            }
            if(temp1==temp2&&num1&&num2){
                flag=1;
                break;
            }
        }
        for(int mid=0;mid<=30;mid++){
            if(cnt[mid][1]==cnt[mid][2]&&cnt[mid][3]>1){
                int temp1=0,temp2=inf;
                for(int k=0;k<=mid-1;k++){
                    temp1|=cnt[k][2];
                }
                for(int k=mid+1;k<=30;k++){
                    temp2&=cnt[k][1];
                }
                if((temp1|cnt[mid][1])==(temp2&cnt[mid][2])){
                    flag=1;
                    break;
                }
            }
        }
        printf(flag?"YES\n":"NO\n");
    }
    return 0;
}
