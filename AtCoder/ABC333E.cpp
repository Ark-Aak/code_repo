#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const ll MAXN = 2e5 + 7;
ll n, K, g[MAXN], res;
struct node{
	ll t, x;
} a[MAXN];

map <ll, ll> ned;

int main(){
	cin >> n;
	rep (i, 1, n) {
		cin >> a[i].t >> a[i].x;
	}
	_rep (i, n, 1) {
		if(a[i].t==2){
			res++;
			ned[a[i].x]++;
		}
		else{
			if(ned[a[i].x]) {
				g[i] = 1;
				ned[a[i].x]--;
				res--;
			}
		}
		K = max(K, res);
	}
	bool flg = 0;
	for (auto i : ned) {
		if (i.second) flg = 1;
	}
	if (flg) {
		return puts("-1"), 0;
	}
	cout << K << endl;
	rep (i, 1, n) {
		if(a[i].t == 1) {
			cout << g[i] << " ";
		}
	}
	return 0;
}
