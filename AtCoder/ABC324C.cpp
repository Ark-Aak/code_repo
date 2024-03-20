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

ll n;
string s,t;
vector<ll>ans;

int main(){
	cin >> n >> t;
	rep (i, 1, n) {
		cin >> s;
		ll ns = s.size(), nt = t.size();
		if(abs(ns - nt) > 1) {
			continue;
		}
		if(t == s){
			ans.push_back(i);
			continue;
		}
		if(ns > nt){
			ll pp = 0;
			rep (_i, 0, nt - 1) {
				if(pp == 1 && t[_i] != s[_i + pp]){
					break;
				}
				if(t[_i] != s[_i + pp]) pp = 1;
				if(t[_i] != s[_i + pp]) {
					break;
				}
				if (_i == nt - 1){
					ans.push_back(i);
				}
			}
			continue;
		}
		if(ns < nt){
			ll pp = 0;
			rep (_i, 0, ns - 1) {
				if(pp == 1 && t[_i + pp] != s[_i]){
					break;
				}
				if(t[_i + pp] != s[_i]) pp=1;
				if(t[_i + pp] != s[_i]){
					break;
				}
				if(_i == ns - 1) ans.push_back(i);
			}
			continue;
		}
		ll ss = 0;
		rep (_i, 0, ns - 1) {
			if(s[_i] != t[_i]) ss++;
		}
		if(ss == 1){
			ans.push_back(i);
		}
	}
	cout << (ans.size()) << endl;
	for(auto j : ans) cout << j << " ";
	return 0;
}
