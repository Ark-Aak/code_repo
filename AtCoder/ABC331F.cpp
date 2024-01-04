#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

const ull B = 1e8+7;
const int MAXN = 1e6+10;

#define lson (k << 1)
#define rson ((k << 1 | 1))

char str[MAXN];
ull Pow[MAXN];

class Node{
public:
    int l, r;
    ull Lv, Rv;
    Node() {
		l = r = 0;
    	Lv = Rv = 0;
	}

    int len() {
        return r - l + 1;
    }

    int mid() {
        return (l + r) >> 1;
    }
};

Node tree[MAXN << 2];

void init() {
    Pow[0] = 1;
    rep (i, 1, 1e6) Pow[i] = Pow[i - 1] * B;
}

void PushUp(int k) {
    int L = tree[lson].len();
    int R = tree[rson].len();
    tree[k].Lv = tree[lson].Lv + tree[rson].Lv * Pow[L];
    tree[k].Rv = tree[lson].Rv * Pow[R] + tree[rson].Rv;
}

void Build(int L, int R, int k) {
    tree[k].l = L;
    tree[k].r = R;
    if(L == R) {
        tree[k].Lv = (ull) str[L];
        tree[k].Rv = (ull) str[L];
        return;
    }
    int mid = (L + R) >> 1;
    Build(L, mid, lson);
    Build(mid + 1, R, rson);
    PushUp(k);
}
void Update(int p, int k){
    if(tree[k].l == tree[k].r && tree[k].l == p) {
        tree[k].Lv = (ull) str[p];
        tree[k].Rv = (ull) str[p];
        return;
    }
    int mid = tree[k].mid();
    if(p <= mid) Update(p, lson);
    else Update(p, rson);
    PushUp(k);
}
ull QueryL(int L, int R, int k, int &len) {
    if(L <= tree[k].l && tree[k].r <= R) {
        ull temp = tree[k].Lv * Pow[len];
        len += tree[k].len();
        return temp;
    }
    int mid = tree[k].mid();
    ull res = 0;
    if(L <= mid) res += QueryL(L,R,lson,len);
    if(R > mid) res += QueryL(L,R,rson,len);
    return res;
}

ull QueryR(int L,int R,int k,int &len){
    if(L <= tree[k].l && tree[k].r <= R){
        ull temp = tree[k].Rv * Pow[len];
        len += tree[k].len();
        return temp;
    }
    int mid = tree[k].mid();
    ull res = 0;
    if(R > mid) res += QueryR(L, R, rson, len);
    if(L <= mid) res += QueryR(L, R, lson, len);
    return res;
}

int N;

int main() {
    init();
    int Q;
	cin >> N;
    scanf("%d", &Q);
    scanf("%s", str + 1);
    Build(1, N, 1);
    while(Q--) {
		int op; read(op);
        if(op == 2){
            int l, r;
            scanf("%d %d", &l, &r);
            int len = 0;
            ull Lv = QueryL(l, r, 1, len);
            len = 0;
            ull Rv = QueryR(l, r, 1, len);
            if(Lv == Rv) printf("Yes\n");
            else printf("No\n");
        }
        else{
            int op; char ch;
            scanf("%d %c", &op, &ch);
            str[op] = ch;
            Update(op,1);
        }
    }
    return 0;
}
