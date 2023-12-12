#include <bits/stdc++.h>

using namespace std;

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

mt19937 _rnd(time(0));

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

pair <int, int> arr[1000005];

vector <pair <int, int> > tree(int n, bool chain, bool flower, int tn){
	//n -> 节点数 chain -> 链 flower -> 菊花 tn -> 树高
	vector <pair <int, int> > edges;
	if (flower) {
		rep (i, 2, n) edges.push_back(make_pair(1, i));
	}
	else if (!chain) {
		rep (i, 1, tn) arr[i].first = i, arr[i].second = i + 1;
		rep (i, tn + 1, n - 1) arr[i].first = i + 1, arr[i].second = rnd(1, i);
		shuffle(arr + 1, arr + n, _rnd);
		rep (i, 1, n - 1) {
			edges.push_back(arr[i]);
		}
	}
	else rep (i, 1, n - 1) edges.push_back({i, i + 1});
	return edges;
}