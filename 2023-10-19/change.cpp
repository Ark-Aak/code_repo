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

#define int ll

int T;
int n;

bool isVariable(string s) {
	return s[0] == 'x';
}

int getVariableId(string s) {
	if (s[0] != 'x') return 0;
	int res = 0;
	rep (i, 1, (int) s.size() - 1) {
		res = (res << 3) + (res << 1) + (s[i] ^ 48);
	}
	return res;
}

namespace ExpressionsTree {
	struct node {
		int type, val, varId;
		node *ls, *rs;

		node(int _type): type(_type), val(0), varId(0) {ls = nullptr, rs = nullptr;}
		node(int _type, int _varId): type(_type), val(0), varId(_varId) {ls = nullptr, rs = nullptr;}
	};

	node* root = nullptr;
}

using ExpressionsTree::node;
using ExpressionsTree::root;

const int MAXN = 5e5 + 5;
stack <node*> stk;
bitset <MAXN> vars;
bool target;

bool calculate(node* u) {
	if (u == nullptr) return false;
	bool vls = false, vrs = false;
	if (u -> type != 1) {
		if (u -> ls) vls = calculate(u -> ls);
		if (u -> rs) vrs = calculate(u -> rs);
		if (u -> type == 2) return (u -> val = (vls || vrs));
		else return (u -> val = (vls && vrs));
	}
	else return (u -> val = vars[u -> varId]);
	return false;
}

void release(node *u) {
	if (u == nullptr) return;
	if (u -> ls) release(u -> ls);
	if (u -> rs) release(u -> rs);
	delete u;
	u = nullptr;
}

int solve(node *u, bool target) {
	if (u == nullptr) return 0;
	if (u -> type == 1) return (u -> val != target);
	if (u -> ls == nullptr) return 0;
	if (u -> rs == nullptr) return 0;
	int type = u -> type;
	bool nVal = u -> val;
	if (nVal == target) return 0;
	int res = 0;
	if (type == 2) {
		if (target == false) {
			res = solve(u -> ls, false) + solve(u -> rs, false);
		}
		else {
			res = min(solve(u -> ls, true), solve(u -> rs, true));
		}
	}
	else {
		if (target == false) {
			res = min(solve(u -> ls, false), solve(u -> rs, false));
		}
		else {
			res = solve(u -> ls, true) + solve(u -> rs, true);
		}
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("change.in", "r", stdin);
	frepoen("change.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin >> T;
	while (T --> 0) {
		release(root);
		root = nullptr;
		cin >> n;
		string s;
		rep (i, 1, 2 * n - 1) {
			cin >> s;
			if (isVariable(s)) {
				stk.push(new node(1, getVariableId(s)));
			}
			else {
				node *ea, *eb;
				ea = stk.top(), stk.pop();
				eb = stk.top(), stk.pop();
				int type = 0;
				if (s[0] == '|') type = 2;
				else type = 3;
				node *newNode = new node(type);
				newNode -> ls = ea;
				newNode -> rs = eb;
				stk.push(newNode);
			}
		}
		rep (i, 1, n) {
			bool val;
			cin >> val;
			vars[i] = val;
		}
		root = stk.top();
		while (stk.size()) stk.pop();
		target = (!calculate(root));
		cout << solve(root, target) << "\n";
	}
	return 0;
}
