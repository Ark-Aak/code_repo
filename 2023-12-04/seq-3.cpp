#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[100005];
int st[200005][19];

void Init() {
    m = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '(')
            st[m++][0] = i;
    for (int i = m; i < 2 * m; i++) st[i][0] = st[i - m][0] + n;
    for (int i = 0; i < 2 * m; i++) st[i][0] -= 2 * i;
    for (int i = 1; i <= 18; i++)
        for (int j = 0; j + (1 << (i - 1)) < 2 * m; j++)
            st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
}

inline int Ask(int l, int r) {
    int len = log2(r - l + 1);
    return min(st[l][len], st[r - (1 << len) + 1][len]);
}

int read() {
	int w = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (!(ch ^ 45)) f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		w = (w << 3) + (w << 1) + (ch ^ 48);
		ch = getchar();
	}
	return w * f;
}

inline long long int f(int k, int i) {
    int l, r;
    if (n >= 2 * m)
        l = i, r = min(i + k, l + m - 1);
    else
        l = max(i, i + k - m + 1), r = i + k;
    int v;
    if (l >= 0)
        v = l / m;
    else
        v = (l + 1) / m - 1;
    int len = r - l;
    l = (l % m + m) % m;
    r = l + len;
    return Ask(l, r) + v * (n - 2 * m) + 2ll * i + k;
}
inline int sol(int x, int k) {
    int l = -1e9, r = 1e9;
    while (l < r) {
        int mid = (l + r + 1ll) / 2;
        if (f(k, mid) <= x) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T= read();
	while (T--) {
		char c = getchar();
		while (c != '(' && c != ')') c = getchar();
		n = 0;
		do {
			s[n++] = c;
		} while ((c = getchar()) ==  '(' || c == ')');
        Init();
        int Q = read();
        while (Q--) {
            int k = read(), l = read(), r = read();
            if (m)
                cout << sol(r, k) - sol(l - 1, k) << "\n";
            else cout << "0\n";
        }
    }
    return 0;
}
