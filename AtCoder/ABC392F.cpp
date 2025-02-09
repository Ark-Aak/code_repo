#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int N=1e6+5;

struct Treap {
    int ch[N][2],val[N],key[N],siz[N],tot=0;
    bool fl[N];

   void down(int x) {
        swap(ch[x][0],ch[x][1]);
        if(ch[x][0]) fl[ch[x][0]]^=1;
        if(ch[x][1]) fl[ch[x][1]]^=1;
        fl[x]=0;
    }

    int build(int x)
    {
        val[++tot]=x,siz[tot]=1,key[tot]=rand();
        return tot;
    }

    void update(int x) {
        siz[x]=1+siz[ch[x][1]]+siz[ch[x][0]];
    }

    void split(int now,int k,int &x,int &y) {
        if(!now) {
            x=y=0;
            return ;
        }
        if(fl[now]) down(now);
        if(siz[ch[now][0]]<k) {
            x=now;
            split(ch[now][1],k-siz[ch[now][0]]-1,ch[now][1],y);
        } else {
            y=now;
            split(ch[now][0],k,x,ch[now][0]);
        }
        update(now);
    }

    int merge(int x,int y) {
        if(!x || !y) return x+y;
        if(key[x]<key[y]) {
            if(fl[x]) down(x);
            ch[x][1]=merge(ch[x][1],y);//xÎª¸ùµÄÊ±ºò£¬yµÄÖµºÍxµÄÓÒ×Ó±È½Ï
            update(x);
            return x;
        } else {
            if(fl[y]) down(y);
            ch[y][0]=merge(x,ch[y][0]);//ÒÔyÎª¸ù, yµÄÖµºÜxµÄ×ó×Ó±È½Ï
            update(y);
            return y;
        }
    }

    void solve(int i)
    {
        if(!i) return;
        if(fl[i]) down(i);
        solve(ch[i][0]);
        printf("%d ",val[i]);
        solve(ch[i][1]);
    }

}tree;

int main() {
    int n,rt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int l,x,y;
        scanf("%d",&l);
        tree.split(rt,l-1,x,y);
        x=tree.merge(x,tree.build(i));
        rt=tree.merge(x,y);
    }
    tree.solve(rt);
    return 0;
}
