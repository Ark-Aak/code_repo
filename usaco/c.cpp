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

int T, n;
struct node {
    int h, a, t, w;
} a[200005];

bool cmp(node x, node y) {
    return x.t < y.t;
}

bool cmp2(node x, node y) {
    return x.h > y.h;
}

vector<int> ans;

signed main() {
	read(T);
    while (T--) {
        int n;
		read(n);
        for (int i = 1; i <= n; i++) read(a[i].h);
 	    for (int i = 1; i <= n; i++) read(a[i].a);
        for (int i = 1; i <= n; i++) read(a[i].t);
        if (n > 2 && n <= 50) {
            sort(a + 1, a + n + 1, cmp2);
            int flag = 0;
            if (!flag)
				rep (i, 0, 1e6) {
                    sort(a + 1, a + n + 1, cmp2);
                    int fl = 0;
					rep (j, 1, n) {
                        a[j].w = 0;
						rep (k, 1, n) {
                            if (a[k].h > a[j].h) {
                                a[j].w++;
                            }
                        }
                        if (a[j].w != a[j].t) {
                            fl++;
                            break;
                        }
                    }
                    if (!fl) {
                        flag = 1;
                        ans.push_back(i);
                        break;
                    }
					rep (j, 1, n) a[j].h += a[j].a;
                }
            if (!flag) ans.push_back(-1);
            continue;
        }
        sort(a + 1, a + n + 1, cmp);
        int l = 0, r = 1e18;
        for (int i = 1; i < n; i++) {
            if (a[i].h == a[i + 1].h) {
                if (a[i].a > a[i + 1].a)
                    l = max(l, 1ll);
                else
                    r = -1e18;
            }
            if (a[i].h > a[i + 1].h) {
                if (a[i].a < a[i + 1].a) {
                    int t = (a[i].h - a[i + 1].h + (a[i + 1].a - a[i].a) - 1) / (a[i + 1].a - a[i].a);
                    r = min(r, t);
                }
            }
            else {
                if (a[i].a > a[i + 1].a) {
                    int t = (a[i + 1].h - a[i].h + (a[i].a - a[i + 1].a) - 1) / (a[i].a - a[i + 1].a);
                    if (a[i].h + a[i].a * t == a[i + 1].h + a[i + 1].a * t)
                        t++;
                    l = max(l, t);
                }
                else r = -1e18;
            }
        }
        if (l > r) ans.push_back(-1ll);
        else ans.push_back(l);
    }
	for (auto v : ans) print(v), putchar(10);
    return 0;
}
