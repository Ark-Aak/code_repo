#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F(i, a, b) for (int i = a; i <= b; i++)
#define R(i, a, b) for (int i = a; i >= b; i--)

#define mk(a, b) make_pair(a, b)
#define inv(x) ksm(x, Mod - 2)
#define mem(a, b) memset(a, b, sizeof a)

#define De(x) cerr << "------------------" << x << "--------------" << endl
#define Debug() cerr << "----------------------------------------" << endl
#define lson(x) x << 1
#define rson(x) x << 1 | 1

const int N = 2e5 + 5, TN = 1e6 + 5, Mod = 1e9 + 7, inf = INT_MAX, Inf = LONG_LONG_MAX;
inline int ksm(int a, int b);
inline int read();
string s;
int T = 1, ans = 0, n, m, a[N], u, v, in[N], f[3005][3005], num[TN<<1], MaxDeg;

bool b[TN<<1];

vector <int> vm;

inline void Subtask1() {
	F(i, 1, n)
	F(j, i + 1, n)
	ans = (ans + (in[i] ^ in[j]) * (in[i] | in[j]) * (in[i] & in[j])) % Mod;
	cout << ans;
	return;
}

inline void Subtask2() {
	F(i, 1, 2000)
	F(j, 1, 2000)
	f[i][j] = (i ^ j) * (i | j) * (i & j) % Mod;
	F(i, 1, n) num[in[i]]++;
	F(i, 1, 2000)
	F(j, i + 1, 2000)
	ans = (ans + (f[i][j]) * num[i] * num[j] + Mod) % Mod;
	cout << ans << endl;
	return;
}

inline void Subtask3() {
	F(i,1,n){
		num[in[i]]++;
		if(b[in[i]]) continue;
		b[in[i]]=1;
		vm.push_back(in[i]);
	}
	sort(vm.begin(),vm.end());
	int len=vm.size()-1;
	F(i,0,len){
		F(j,i+1,len){
			int x=vm[i],y=vm[j];
			ans=ans+((x&y)*(x|y)*(x^y))%Mod*num[x]*num[y];
			ans=ans%Mod;
		}
	}
	cout<<ans;
	return;
}

signed main() {
	freopen("gen.in", "r", stdin);
	freopen("gen.out", "w", stdout);
	while (T--) {
		n = read(), m = read();
		F(i, 1, m) {
			u = read(), v = read();
			in[v]++, in[u]++;
			MaxDeg = max(MaxDeg, in[v]);
			MaxDeg = max(MaxDeg, in[u]);
		}
		if (n <= 2000) {
			Subtask1();
			return 0;
		}
		if (MaxDeg <= 2000) {
			Subtask2();
			return 0;
		}
		Subtask3();
	}
	return 0;
}
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			f *= -1;
		c = getchar();
	}
	while (c <= '9' && c >= '0') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline int ksm(int a, int b) {
	int aa = 1;
	while (b) {
		if (b & 1)
			aa *= a, aa %= Mod;
		a *= a;
		a %= Mod;
		b >>= 1;
	}
	return aa;
}
