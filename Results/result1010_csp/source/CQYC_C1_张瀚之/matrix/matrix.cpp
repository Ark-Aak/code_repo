#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, m, ans = 2e9;
bool b[25][N];

void Not(bool *b) {
    for (int i = 0; i < m; i++) b[i] ^= 1;
}

int main() {
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        char ch[N];
        scanf("%s", ch);
        for (int j = 0; j < m; j++) b[i][j] = ch[j] == 49;
    }
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 1; j <= n; j++)
            if (i & 1 << j - 1) Not(b[j]);
        int sum[N];
        memset(sum, 0, sizeof sum);
        for (int j = 1; j <= n; j++)
            for (int k = 0; k < m; k++)
                sum[k + 1] += b[j][k];
        for (int j = 1; j <= m; j++) sum[0] += min(sum[j], n - sum[j]);
        ans = min(ans, sum[0]);
        for (int j = 1; j <= n; j++)
            if (i & 1 << j - 1) Not(b[j]);
    }
    printf("%d", ans);
    return 0;
}
