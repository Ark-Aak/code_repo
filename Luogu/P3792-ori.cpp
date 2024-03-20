#include <bits/stdc++.h>
#include <bits/extc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
typedef std::pair<int,int> pii;
typedef std::vector<int> vec;

using namespace std;

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define End return 0
#define blockId(x) ((x)/BLOCK_SIZE)

namespace Anschluss_zeit {
	const int MOD = 1e9 + 7;
	const double PI = acos(-1.0);
	const double EPS = 1e-6;
	const int MAXN = 1e6 + 5;
	namespace Math {
		int fac[MAXN];
		void initFac(int n) {fac[0] = 1;for (int i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % MOD;}
		template<typename T>
		T qpow(T a, T b, T p) {
			T ans = 1;a = (a % p + p) % p;
			while (b) {if (b % 2)ans = (a * ans) % p;a = (a * a) % p;b /= 2;}
			return ans;
		}
		template<typename T>
		T inv(T a, T p) {return qpow(a, p - 2, p);}
		int C(int m, int n, int p) {return fac[n] * qpow(fac[m], p - 2, p) % p * qpow(fac[n - m], p - 2, p) % p;}
	};
	namespace IO {
		template<typename T>
		void read(T& t) {
			T x = 0, f = 1;char c = getchar();
			while (!isdigit(c)) {if (c == '-') f = -1;c = getchar();}
			while (isdigit(c))x = (x << 3) + (x << 1) + (c^'0'), c = getchar();
			t = x * f;
		}
		template<typename T>
		void print(T x) {if (x < 0) x = (~x + 1), putchar('-');if (x > 9) print(x / 10);putchar(x % 10 + '0');}
		void print(string s) {int l = s.length();for (int i = 0; i < l; i++)putchar(s[i]);}
		void eoln(){putchar('\n');}
	};
	namespace Function {
		template<typename T>
		T blockSize(T n){return pow((double)n,0.5);}
		template<typename T>
		T blockSize(T n,T m){return (double)n/(double)pow((double)m,0.5);}
		template<typename T>
		T blockSizeM(T n){return pow((double)n*(double)n,1.0/3.0);}
	};
};
using namespace Anschluss_zeit;
using namespace IO;
using namespace Function;
using namespace Math;

int BLOCK_SIZE,n,m,modifyCount;
int a[2000005],queryCount,cnt[1000005];
int lcur=0,rcur=0,tcur=0,diff,ans[2000005];

struct Modify{
	int pos,val;
}modify[2000005];

struct Query{
	int l,r,id,ti;
	bool operator<(const Query &t)const{
		return blockId(l)!=blockId(t.l)?blockId(l)<blockId(t.l):blockId(r)!=blockId(t.r)?blockId(r)<blockId(t.r):ti<t.ti;
	}
}query[2000005];

void Move(int pos,int flg){
	if(flg==1){
		cnt[a[pos]]++;
		if(cnt[a[pos]]==1)diff++;
	}
	else{
		cnt[a[pos]]--;
		if(cnt[a[pos]]==0)diff--;
	}
}

void UpdateTime(int t){
	if(lcur<=modify[t].pos&&modify[t].pos<=rcur){
		Move(modify[t].pos,-1);
		swap(modify[t].val,a[modify[t].pos]);
		Move(modify[t].pos,1);
	}
	else swap(modify[t].val,a[modify[t].pos]);
}

signed main() {
	read(n);read(m);
	BLOCK_SIZE=blockSizeM(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,m){
	    char c=getchar();
	    while(c!='Q'&&c!='R')c=getchar();
		if(c=='Q'){
			read(query[++queryCount].l);
			read(query[queryCount].r);
			query[queryCount].ti=modifyCount;
			query[queryCount].id=queryCount;
		}
		else{
			read(modify[++modifyCount].pos);
			read(modify[modifyCount].val);
		}
	}
	sort(query+1,query+1+queryCount);
	rep(i,1,queryCount){
		Query x=query[i];
		while(lcur<x.l)Move(lcur++,-1);
		while(lcur>x.l)Move(--lcur,1);
		while(rcur<x.r)Move(++rcur,1);
		while(rcur>x.r)Move(rcur--,-1);
		while(tcur<x.ti)UpdateTime(++tcur);
		while(tcur>x.ti)UpdateTime(tcur--);
		ans[x.id]=diff;
	}
	rep(i,1,queryCount)print(ans[i]),eoln();
	return 0;
}
