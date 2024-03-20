#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define rep(i, a, b) for(register int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(register int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

struct Query {
	int opt, l, r, k;
} ask[100010];

int a[100010], n, cnt, q;
long long int s[100010];
bool flg = 1, flg2 = 1;

int main() {
	scanf("%d %d", &n, &q);
	rep (i, 1, n) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	rep (i, 1, q) {
		scanf("%d", &ask[i].opt);
		if(ask[i].opt == 1) {
			scanf("%d", &ask[i].k);
			cnt++;
			flg2 = 0;
		}
		else {
			scanf("%d %d", &ask[i].l, &ask[i].r);
			if (ask[i].l != 1 || ask[i].r != n) flg = 0;
		}
	}
	if (flg2 || (cnt <= 5250 && !flg)) {
		rep (i, 1, q) {
			if(ask[i].opt == 1) {
				rep (j, 1, n) {
					a[j] = abs(a[j] - ask[i].k);
					s[j] = s[j - 1] + a[j];
				}
			}
			else {
				printf("%lld\n", s[ask[i].r] - s[ask[i].l - 1]);
			}
		}
	}
	else {
		rep (i, 1, q) {
			if(ask[i].opt == 1) {
				rep (j, 1, n) a[j] = abs(a[j] - ask[i].k);
			}
			else {
				long long int res = 0;
				rep (j, ask[i].l, ask[i].r) res += a[j];
				printf("%lld\n", res);
			}
		}
	}
    return 0;
}
