#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

using namespace std;
using namespace __gnu_pbds;

tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tr[200005];
map <int, int> m;
int n, q, tot, c[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		if (m[c[i]] == 0) m[c[i]] = ++tot;
		c[i] = m[c[i]];
		tr[c[i]].insert(i);
	}
	while (q --> 0) {
		char ch;
		cin >> ch;
		if (ch == 'Q') {
			int A,B,X;
			cin >> A >> B >> X;
			if (m[X] == 0) m[X] = ++tot;
			X = m[X];
			cout << (tr[X].order_of_key(B) - tr[X].order_of_key(A - 1)) << endl;
		}
		else {
			int A, X;
			cin >> A >> X;
			if (m[X] == 0) m[X] = ++tot;
			X = m[X];
			assert(tr[c[A]].erase(A));
			c[A] = X;
			tr[X].insert(A);
		}
	}
	return 0;
}
