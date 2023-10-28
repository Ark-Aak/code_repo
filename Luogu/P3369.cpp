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

mt19937 rnd(time(0));

struct node {
	int key, val, siz;
	node *ls, *rs;

	node(int val) {
		this -> val = val;
		this -> key = rnd();
		ls = nullptr, rs = nullptr;
	}

	void upd_siz() {
		siz = (ls ? ls -> siz : 0) + (rs ? rs -> siz : 0) + 1;
	}
};

pair <node*, node*> split(node* now, int val) {
	if (!now) return {nullptr, nullptr};
	if (now -> val <= val) {
		auto tmp = split(now -> rs, val);
		now -> rs = tmp.first;
		now -> upd_siz();
		return {now, tmp.second};
	}
	else {
		auto tmp = split(now -> ls, val);
		now -> ls = tmp.second;
		now -> upd_siz();
		return {tmp.first, now};
	}
}

tuple <node*, node*, node*> splitRk(node* now, int k) {
	if (!now) return {nullptr, nullptr, nullptr};
	int less_siz = (now -> ls ? now -> ls -> siz : 0);
	if (k <= less_siz) {
		node *l, *r, *mid;
		tie(l, mid, r) = splitRk(now -> ls, k);
		now -> ls = r;
		l -> upd_siz();
		r -> upd_siz();
		now -> upd_siz();
		return {l, mid, r};
	}
	else if (k == less_siz + 1) {
		node *l = now -> ls, *r = now -> rs;
		now -> ls = nullptr;
		now -> rs = nullptr;
		l -> upd_siz();
		r -> upd_siz();
		now -> upd_siz();
		return {l, now, r};
	}
	else {
		node *l, *r, * mid;
		tie(l, mid, r) = splitRk(now -> rs, k - less_siz - 1);
		now -> rs = l;
		l -> upd_siz();
		r -> upd_siz();
		now -> upd_siz();
		return {l, mid, r};
	}
}

node* merge(node* u, node* v) {
	if (!u && !v) return nullptr;
	if (!u && v) return v;
	if (u && !v) return u;
	if (u -> key < v -> key) {
		u -> rs = merge(u -> rs, v);
		u -> upd_siz();
		return u;
	}
	else {
		v -> ls = merge(u, v -> ls);
		v -> upd_siz();
		return v;
	}
}

int kth(node* now, int k) {
	node *l, *r, *mid;
	tie(l, mid, r) = splitRk(now, k);
	int res = mid -> val;
	merge(merge(l, mid), r);
	return res;
}

int rank(node* now, int val) {
	auto tmp = split(now, val);
	int res = (tmp.first ? tmp.first -> siz : 0) + 1;
	merge(tmp.first, tmp.second);
	return res;
}

int prev(node* now, int val) {
	auto tmp = split(now, val - 1);
	int res = kth(tmp.first, (tmp.first ? tmp.first -> siz : 0));
	now = merge(tmp.first, tmp.second);
	return res;
}

int nxt(node* now, int val) {
	auto tmp = split(now, val);
	int res = kth(tmp.second, 1);
	now = merge(tmp.first, tmp.second);
	return res;
}

void insert(node* now, int val) {
	auto l = split(now, val - 1);
	node *newNode = new node(val);
	merge(merge(l.first, newNode), l.second);
}

void del(node* now, int val) {
	node *l, *mid, *r;
	auto tmp1 = split(now, val);
	auto tmp2 = split(tmp1.first, val - 1);
	l = tmp2.first, mid = tmp2.second, r = tmp1.second;
	r = merge(l, r);
	delete mid;
}

int main() {

	return 0;
}
