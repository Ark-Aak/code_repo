#include <bits/stdc++.h>
#include <bits/extc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
typedef std::pair<int,int> pii;
typedef std::vector<int> vec;

using namespace std;

#define __rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))
#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define End return 0

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
		int bitCount(int n,int t){
			if(n==0)return 0;
			if(t)return bitCount(n>>1,t)+(n&1);
			else return bitCount(n>>1,t)+!(n&1);
		}
		template<typename T,int mod = 1000000007>
		class Modint{
		private:
			T n;
		public:
			T operator()(){return n;}
			operator int() { return n; }
			Modint(){n=0;}
			Modint(T m){n=m;n=(n%mod+mod)%mod;}
			Modint operator=(Modint a){n=a.n;n%=mod;return n;}
			bool operator==(Modint a){return n==a.n;}
			Modint operator+=(Modint a){n+=a.n;n=(n%mod+mod)%mod;return n;}
			Modint operator-=(Modint a){n-=a.n;n=(n%mod+mod)%mod;return n;}
			Modint operator*=(Modint a){n=(n*a.n)%mod;return n;}
			Modint operator+(Modint a){return a+=*this;}
			Modint operator-(Modint a){return a-=*this;}
			Modint operator*(Modint a){return a*=*this;}
			Modint operator^(T a){
				if(a==0)return Modint(1);
				Modint res=((*this)*(*this))^(a/2);
				if(a%2)res=res*(*this);
				return res;
			}
			Modint operator^=(int a){Modint r=(*this)^a;n=r.n;return n;}
			Modint operator/(Modint a){return (*this)*(a^(mod-2));}
			Modint operator/=(Modint a){Modint r=(*this)/a;n=r.n;return n;}
		};
	};
	namespace String {
		namespace KMP {
			int kmp[MAXN];
			void gen(string s) {
				int j = 0;for (int i = 2; i * 1ull < s.length(); i++) {
					while (j != 0 && s[i] != s[j + 1])j = kmp[j];
					if (s[j + 1] == s[i])j++;
					kmp[i] = j;
				}
			}
			int find(string t, string p) {
				t = ' ' + t;p = ' ' + p;gen(p);int j = 0;
				for (int i = 1; i * 1ull < t.length(); i++) {while (j != 0 && t[i] != t[j + 1])j = kmp[j];
					if (p[j + 1] == t[i])j++;
					if (j * 1ull == p.length() - 1)return i - p.length() + 2;
				}return 0;
			}
		};
		int find_kmp(string t, string s) {return KMP::find(t, s) - 1;}//KMP查找，返回下标，未找到返回-1
	};
	namespace IO {
		template<typename T>
		void read(T& t) {
			T x = 0, f = 1;char c = getchar();
			while (!isdigit(c)) {if (c == '-') f = -1;c = getchar();}
			while (isdigit(c))x = (x << 3) + (x << 1) + (c^'0'), c = getchar();
			t = x * f;
		}
		template<typename T, int mod=1000000007>
		void mread(Anschluss_zeit::Math::Modint<T,mod>& t){
			T x = 0, f = 1;char c = getchar();
			while (!isdigit(c)) {if (c == '-') f = -1;c = getchar();}
			while (isdigit(c))x = (x << 3) + (x << 1) + (c^'0'), c = getchar();
			t = Anschluss_zeit::Math::Modint<T,mod>(x * f);
		}
		template<typename T>
		void print(T x) {if (x < 0) x = (~x + 1), putchar('-');if (x > 9) print(x / 10);putchar(x % 10 + '0');}
		template<typename T, int mod=1000000007>
		void print(Anschluss_zeit::Math::Modint<T,mod> x){print(x());}
		void print(string s) {int l = s.length();for (int i = 0; i < l; i++)putchar(s[i]);}
		void eoln(){putchar('\n');}
	};
	namespace Struct {
		template<typename T,int siz=MAXN>
		class SegmentTree {
			T sum[4*siz], lazy[4*siz];
			int ls(int x) {return x * 2;}
			int rs(int x) {return x * 2 + 1;}
			void maintain(int x) {sum[x] = sum[ls(x)] + sum[rs(x)];}
			void pushdown(int x, int L, int R) {
				if (lazy[x]) {
					sum[ls(x)] += (((L+R)>>1) - L + 1) * lazy[x];sum[rs(x)] += (R - ((L+R)>>1)) * lazy[x];
					lazy[ls(x)] += lazy[x];lazy[rs(x)] += lazy[x];lazy[x] = 0;
				}
			}
			void build(int x, int L, int R) {
				if (L == R) {sum[x] = a[L];return;}
				build(ls(x), L, ((L+R)>>1));build(rs(x), ((L+R)>>1) + 1, R);maintain(x);
			}
			void modify(int x, int L, int R, int l, int r, T val) {
				if (l <= L && R <= r) {sum[x] += (R - L + 1) * val;lazy[x] += val;return;}
				if (L != R)pushdown(x, L, R);
				if (l <= ((L+R)>>1))modify(ls(x), L, ((L+R)>>1), l, r, val);
				if (r > ((L+R)>>1))modify(rs(x), ((L+R)>>1) + 1, R, l, r, val);
				maintain(x);
			}
			T query(int x, int L, int R, int l, int r) {
				if (l <= L && R <= r) {return sum[x];}if (L != R)pushdown(x, L, R);
				T result = 0;if (l <= ((L+R)>>1))result += query(ls(x), L, ((L+R)>>1), l, r);
				if (r > ((L+R)>>1))result += query(rs(x), ((L+R)>>1) + 1, R, l, r);
				maintain(x);return result;
			}
		public:
			T a[siz];int N;
			void Modify(int l, int r, T val) {modify(1, 1, N, l, r, val);}
			void Build() {build(1, 1, N);}
			T Query(int l, int r) {return query(1, 1, N, l, r);}
		};
	};
};
using namespace Anschluss_zeit;
using namespace IO;
using namespace Math;

int a[100005],n,q,l=0,r;
int BLOCK_SIZE,o[100005];
int cnt[100005],ans;

struct Query{
	int l,r,id;
	bool operator<(const Query &t)const{
		return l/BLOCK_SIZE!=t.l/BLOCK_SIZE ? l/BLOCK_SIZE<t.l/BLOCK_SIZE : r<t.r;
	}
}Q[100005];

void Move(int pos,int flg){
	if(flg==1){
		cnt[a[pos]]++;
		if(cnt[a[pos]]==1)ans++;
	}
	else{
		cnt[a[pos]]--;
		if(cnt[a[pos]]==0)ans--;
	}
}

signed main() {
	read(n);read(q);
	BLOCK_SIZE=sqrt(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,q)read(Q[i].l),read(Q[i].r),Q[i].id=i;
	sort(Q+1,Q+1+q);
	rep(i,1,q){
		Query x=Q[i];
		while(l<x.l)Move(l++,-1);
		while(l>x.l)Move(--l,1);
		while(r<x.r)Move(++r,1);
		while(r>x.r)Move(r--,-1);
		o[x.id]=(ans==x.r-x.l+1?1:0);
	}
	rep(i,1,q) o[i]?Yes:No;
	return 0;
}
