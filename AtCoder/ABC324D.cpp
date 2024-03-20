#include <bits/stdc++.h>

#define rep(i, a, b) for (auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for (auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template <typename _Tp>
void read(_Tp &first) {
    _Tp x = 0, f = 1;
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
    first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
    if (x < 0) x = (~x + 1), putchar('-');
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

#define int ll

const int N = 2e7 + 5;
int n, m, T = 1, a[N], b[N], ans;
unordered_map<int, int> ma;
string s;
void Init() {
    rep (i, 0, 10) {
        int sum = i * i, res = 0;
        int k = sum;
        
        while (k) {
            int x = k % 10;
            b[x]++;
            k /= 10;
            res++;
        }
        ans++;
        rep(j, 0, 9) {
            if (a[j] == b[j] || (a[j] >= b[j] && j == 0))
                continue;
            cout<<j<<" "<<a[j];
            ans--;
            break;
        }
        rep(j, 0, 9) b[j] = 0;
    //	cout<<ans;
	}
}

signed main() {
    cin >> n;
    cin >> s;
    rep (i, 0, n - 1) {
        a[s[i] - '0']++;
    }
    Init();
    cout << ans;
    return 0;
}
