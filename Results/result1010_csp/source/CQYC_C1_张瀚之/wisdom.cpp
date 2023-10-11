#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, m, k;
long long a[5005][5005];
long long sum;

int main() {
    freopen("wisdom.in", "r", stdin);
    freopen("wisdom.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = (i - 1) * m + j;
    while (k--) {
        char select;
        int x, y;
        cin >> select >> x >> y;
        if (select == 82) {
            for (int i = 1; i <= m; i++) a[x][i] = (a[x][i] * y) % mod;
        }
        else {
            for (int i = 1; i <= n; i++) a[i][x] = (a[i][x] * y) % mod;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum = (sum + a[i][j]) % mod;
    printf("%lld", sum);
    return 0;
}
