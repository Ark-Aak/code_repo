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
int T = 1, ans = 0, n, l, r, m, a[TN << 1], Cn, head, tail, num1;

signed main() {
	freopen("kel.in","r",stdin);freopen("kel.out","w",stdout);
	while (T--) {
		memset(a, -1, sizeof a);
		n = read(), l = read(), r = read();
		Cn = n;
		F(i, 1, 2 * (r - l + 1)) {
			if (i % 2) a[i] = l;
			else a[i] = l + (i / 2) - 1;
		}
		n -= 2 * (r - l + 1);
		head = l + 1, tail = l + 1;
		int num3_1 = 0, num3_2 = 0;
		F(i, 2 * (r - l + 1) + 1, Cn) {
			if (head > r || tail > r) break;
			if (num3_1 != 1) {
				a[i] = head;
				num3_1++;
				continue;
			}
			if (num3_1 == 1 && num3_2 != 1 ) {
				a[i] = tail;
				num3_2++;
				//	tail++;
			}
			if (num3_2 == 1 && num3_1 == 1) {
				tail++;
				if (tail == r + 1) {
					head++;
					tail = head;
				}
				num3_1 = 0, num3_2 = 0;
			}
		}
		if (a[Cn] == -1&&a[Cn-1]==-1) cout << "Shinomiya";
		else {
			if(a[Cn]!=-1)F(i, 1, Cn) cout << a[i] << endl;
			if(a[Cn]==-1) {F(i,1,Cn-1) cout<<a[i]<<endl;cout<<l<<endl;}
		}
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
