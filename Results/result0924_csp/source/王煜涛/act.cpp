#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

struct node {
    int a, b;

    bool operator < (const node & t) const { return a == t.a? b < t.b : a < t.a; }
}nd[N];

int n, q, a[N], b[N];
set<node> s;

int main() {
    freopen("act.in", "r", stdin);
    freopen("act.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i], s.insert({a[i], b[i]});
    if(q == 0) return 0;
    if(n == 0) {
        int x, y;
        while(q--) {
            cin >> x >> y;
            if(!((x + y) & 1)) cout << "Bob" << endl;
            else cout << "Alice" << endl;
        }
    }else {
        sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
        int x, y;
        while(q--) {
            cin >> x >> y;
            node t; t.a = x, t.b = y;
            if(s.find(t) != s.end() || (x == 0 && y == 0)) cout << "Bob" << endl;
            else {
                int t1 = lower_bound(a + 1, a + 1 + n, x) - a, t2 = lower_bound(b + 1, b + 1 + n, y) - b;
                if(a[t1] == x || b[t2] == y) cout << "Alice" << endl;
                else cout << "Alice" << endl;
            }
        }
    }
    return 0;
}
/*
6 6
6 3
6 2
1 2


4 5
1 2
*/