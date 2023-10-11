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

const int N = 2e5 + 5, TN = 1e6 + 5, Mod = 998244353, inf = INT_MAX, Inf = LONG_LONG_MAX;
inline int ksm(int a, int b);
inline int read();
string s;
int T = 1, ans = 0, n, m, a[N], b[N];

inline bool Check0(){
	int l1=INT_MAX,r1=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0) l1=min(i,l1),r1=max(i,r1);
	}
	if(r1-l1<=m){
		return false;
	}
	return true;
}

inline bool Check1(){
	int l1=INT_MAX,r1=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) l1=min(i,l1),r1=max(i,r1);
	}
	if(r1-l1<=m){
		return false;
	}
	return true;
}

inline void Subtask1() {
	int fck=0;
	for (int i = 1; i <= n; i++) {
		a[i] = s[i - 1] - '0';
		b[i] = a[i];
	}
	for (int i = 1; i <= n - m + 1; i++) {
		for (int j = i; j <= i + m - 1; j++) {
			a[j]=1;
		}
		F(j,1,n){
			if(a[j]==0) break;
			if(j==n){cout<<"win"<<endl;return;}
		}
		if(fck!=1&&Check0()) {fck=1;}
		for(int j = i;j<=i+m-1;j++){
			a[j]=0;
		}
		F(j,1,n){
			if(a[j]==1) break;
			if(j==n){cout<<"win"<<endl;return;}
		}
		if(fck!=1&&Check1()) {fck=1;}
		for (int j = i; j <= i + m - 1; j++)
			a[i] = b[i];
	}
	if(fck) cout<<"tie"<<endl;
	else cout<<"lose"<<endl;
	return;
}

signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	T = read();
	while (T--) {
		n = read(), m = read();
		cin >> s;
		if (n <= 1000) {
			Subtask1();
			continue;
		}
		int zero_number = 0, Lx_zero = 0, Max_Lx_zero = 0;
		for (int i = 0; i < s.size(); i++) {
			if (i == 0) {
				if (s[i] == '0') zero_number++, Lx_zero = 1;
				continue;
			}
			if (s[i] == '1') Lx_zero = 0;
			else zero_number++, Lx_zero++;
			Max_Lx_zero = max(Max_Lx_zero, Lx_zero);
		}
		if (Max_Lx_zero == zero_number && Max_Lx_zero == m) cout << "win" << endl;
		else cout << "tie" << endl;
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
