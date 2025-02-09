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

const int MAXN=4e6+5;
const double PI=acos(-1.0);
complex<double> a[MAXN],b[MAXN];
int id[MAXN];
void init(int p) {
    int k=1<<p;
    for(int i=0;i<k;i++) id[i]=(id[i>>1]>>1)|((i&1)<<(p-1));
}
void fft(complex<double> *A,int N) {
    for(int i=1;i<N;i++) if(id[i]>i) swap(A[i], A[id[i]]);
    for(int len=2,M=1;len<=N;M=len,len<<= 1) {
        complex<double> W(cos(PI/M),sin(PI/M)),w(1.0, 0.0);
        for(auto L=0,R=len-1;R<=N;L+=len,R+=len) {
            auto w0=w;
            for(auto p=L,lim=L+M;p<lim;p++) {
                auto x=A[p]+w0*A[p+M],y=A[p]-w0*A[p + M];
                A[p]=x; A[p+M]=y;
                w0*=W;
            }
        }
    }
}
int ans[MAXN],pp[MAXN];
map<int,int> ma;
int main() {
    int n,m,x,k=1,p=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&pp[i]);a[pp[i]]=1;ma[pp[i]]++;}
    for(int i=1;i<=n;i++) {b[pp[i]]=1;}
    while(k<=2e6) k<<=1,p++;
    init(p);
    fft(a,k); fft(b,k);
    for(int i=0;i<k;i++) a[i]*=b[i];
    fft(a,k); reverse(a+1,a+k);
    for(int i=1;i<=2e6;i++) {
        ans[i]=(int)(a[i].real()/k+0.5);
    }
    long long sum=0;
    for(int i=1;i<=n;i++) {
        ans[2*pp[i]]--;
        if(ma[2*pp[i]]) ans[2*pp[i]]++;
        sum+=ans[2*pp[i]]/2;
    }
    printf("%lld\n",sum);
    return 0;
}
