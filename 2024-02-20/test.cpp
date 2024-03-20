// ubsan: undefined
// accoders
#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}

template <typename _Tp>
void print(_Tp x) {
    if (x < 0)
        x = (~x + 1), putchar('-');
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

const int MAXN = 6e5 + 5;
int n, a[MAXN];
map<int, int> mp;
unordered_map<int, int> v[MAXN];

pair<int, int> calc(int x) { return make_pair(x, x - n + 1); }

signed main() {
    n = read();
    rep(i, 1, 2 * n - 1) a[i] = read();
    int sum = 0;
    rep(i, 1, n) sum = (sum + a[i]) % n;
    rep(i, 1, n) {
        mp[(a[i] + n - sum) % n] = 1;
        v[1][(a[i] + n - sum) % n] = i;
        mp[(a[i] - sum + n) % n] = 1;
        v[1][(a[i] - sum + n) % n] = i;
    }
    if (sum == 0) {
        rep(i, 1, n) print(i), putchar(32);
        return 0;
    }
    rep(i, 2, n) {
        int l = i, r = i + n - 1;
        sum -= a[l - 1];
        sum = (sum + a[r] + n) % n;
        if (sum == 0) {
            rep(i, l, r) { print(i), putchar(32); }
            return 0;
        }
        if (mp[a[r]]) {
            int L = mp[a[r]];
            int val = v[L][a[r]];
            bool flg = 1;
            rep(j, L, L + n - 1) {
                if (flg && j == val)
                    flg = 0, print(r), putchar(32);
                else
                    print(j), putchar(32);
            }
            return 0;
        }
        mp[(a[r] + n - sum) % n] = i;
        v[i][(a[r] + n - sum) % n] = r;
        mp[(a[r] - sum + n) % n] = i;
        v[i][(a[r] - sum + n) % n] = r;
    }
    return 0;
}
