#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define rep(i, s, t) for (int i = s; i <= t; ++i)
#define per(i, s, t) for (int i = t; i >= s; --i)

const int N = 1e5 + 5;

int n, k;
char s[N];
int pre[N];

void solve() {
	cin >> n >> k;
	cin >> (s+1);
	rep(i, 1, n) pre[i] = pre[i-1] + s[i] - '0';
	rep(i, k, n) {
		if(pre[i] - pre[i-k] == pre[n] || k-(pre[i]-pre[i-k]) == n-pre[n]) {
			cout << "win" << "\n";
			return;
		}
	}
	int p1, p2, p3, p4;
	rep(i, 1, n) if(s[i] == '0') {
		p1 = i;
		break;
	}
	rep(i, 1, n) if(s[i] == '1') {
		p2 = i;
		break;
	}
	per(i, 1, n) if(s[i] == '0') {
		p3 = i;
		break;
	}
	per(i, 1, n) if(s[i] == '1') {
		p4 = i;
		break;
	}
	rep(i, k, n) {
		if(pre[i] - pre[i-k] == k || pre[i] - pre[i-k] == 0) {
			cout << "tie" << "\n";
			return;
		}
	}
	if(p3 - p1 + 1 >= k+2 || p4 - p2 + 1 >= k+2) {
	    cout << "tie" << "\n";
	    return;
	}
	cout << "lose" << "\n";
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(15); 
	cerr << fixed << setprecision(15);

	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}
