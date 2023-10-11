#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    int x,y;
}p[100005];
inline bool cmp(node A,node B){
    if(A.y!=B.y)return A.y<B.y;
    else return A.x<B.x;
}
int asd[200005],maxn;
int tree[200005];//未加进来的点
inline int lowbit(int x){return x&(-x);}
inline void modify(int x,int y){
    while(x<=maxn){
        tree[x]+=y;
        x+=lowbit(x);
    }
}
inline int query(int x){
    int sum=0;
    while(x){
        sum+=tree[x];
        x-=lowbit(x);
    }
    return sum;
}
map<int,int>M;
void qwe(){
    sort(asd+1,asd+2*n+1);
    M[asd[1]]=1;
    maxn=1;
    for(int i=2;i<=2*n;i++)
        if(asd[i]!=asd[i-1])
            M[asd[i]]=++maxn;
}
signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout); 
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&p[i].x,&p[i].y);
        asd[i*2-1]=p[i].x;
        asd[i*2]=p[i].y;
    }
    qwe();
    for(int i=1;i<=n;i++){
        p[i].x=M[p[i].x];
        modify(p[i].x,1);
        p[i].y=M[p[i].y];
    }
    sort(p+1,p+n+1,cmp);
    int l=maxn+1;
    int ans=0;
    for(int i=1;i<=n;i++){
        modify(p[i].x,-1);
        if(p[i].x<l){
            if(n-i==query(l-1))ans++;
            l=p[i].x;
        }
    }
    printf("%d",ans);
	return 0;
}
