#include<bits/stdc++.h>
#define int long long
using namespace std;
bool Begin;
const int max_n=100005;
inline int read(){
    int x=0;bool w=0;char c=getchar();
    while(!isdigit(c)) w|=c=='-',c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return w?-x:x;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10^48);
}

int n,a[max_n];
vector<int> ans;

inline void BasicOp(int x){
    ans.push_back(x);
    for(int i=1,j=x-1;i<j;++i,--j)
        swap(a[i],a[j]);
    for(int i=x+1,j=n;i<j;++i,--j)
        swap(a[i],a[j]);
}

int cnt[max_n],pos[max_n],tmp[max_n];

inline bool Check(){
    int psi=-1,psj=-1;
    for(int i=0;i<=n;++i)
        cnt[i]=0;
    for(int i=1;i<=n;++i){
        ++cnt[a[i]];
        if(cnt[a[i]]>1 && psj==-1)
            psj=i;
    }
    for(int i=1;i<psj;++i) if(a[i]==a[psj]){
        psi=i;
        break;
    }
    for(int i=1;i<=n;++i)
        cnt[i]+=cnt[i-1];
    for(int i=1;i<=n;++i)
        a[i]=cnt[a[i]]--;
    bool res=0;
    for(int i=1;i<=n;++i){
        pos[a[i]]=i;
        tmp[i]=a[i];
    }
    for(int i=1;i<=n;++i){
        if(pos[i]==i) continue;
        swap(tmp[pos[i]],tmp[i]);
        swap(pos[tmp[pos[i]]],pos[i]);
        res^=1;
    }
    if(res && psi!=-1){
        swap(a[psi],a[psj]);
        return 0;
    }
    return res;
}

bool tag;

inline void ReversOp(int l,int r){
    ans.push_back(l),
    ans.push_back(l+n-r+1),
    ans.push_back(n-r+1);
}

inline void solve(){
    for(int i=1;i<=n;++i)
        pos[a[i]]=i;
    for(int i=1,l,r;i<=n;++i){
        if(i==pos[i]) continue;
        if(tag)
            l=n-pos[i]+1,r=n-i+1;
        else
            l=i,r=pos[i];
        ReversOp(l,r);
        swap(a[pos[i]],a[i]);
        swap(pos[a[pos[i]]],pos[i]);
        tag^=1;
    }
}

bool End;
#define File "reverse"
signed main(){
    /* #ifndef ONLINE_JUDGE */
    /* freopen(File ".in","r",stdin); */
    /* freopen(File ".out","w",stdout); */
    /* #endif */
    // cerr<<"Memory : "<<(&Begin-&End)/1024.0/1024<<"\n";
    for(int T=read();T;--T){
        n=read();
        for(int i=1;i<=n;++i)
            a[i]=read();
        ans.clear();
        if(Check()){
            if(n%4==0) BasicOp(1);
            else if(n%4==1) BasicOp(2);
            else if(n%4==2){
                puts("-1");
                continue;
            }
            else BasicOp(1);
        }
		for (int i = 1; i <= n; i++) {
			write(a[i]);
			putchar(' ');
		}
		putchar(10), putchar(10);
        solve();
        write(ans.size()),putchar('\n');
        for(auto v:ans)
            write(v),putchar(' ');
        putchar('\n');
    }
    return 0;
}
