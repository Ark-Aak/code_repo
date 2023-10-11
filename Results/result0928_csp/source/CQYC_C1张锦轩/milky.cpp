#include <bits/stdc++.h>
using namespace std;

char s[1000003];
int n;
long long m[1000003], mi[1000003], mil[1000003], milk[1000003], milky[1000003], p = 1ll << 32;
int q, l, r;
long long m1[1000003], mi1[1000003], mil1[1000003], milk1[1000003], milky1[1000003];
long long ilky[1000003], lky[1000003], ky[1000003], y[1000003], sum[1000003];
long long solve(int l, int r) {
	m1[l - 1] = mi1[l - 1] = mil1[l - 1] = milk1[l - 1] = milky1[l - 1] = 0;
	for (int i = l; i <= r; ++i) {
		m1[i] = m1[i - 1];
		mi1[i] = mi1[i - 1];
		mil1[i] = mil1[i - 1];
		milk1[i] = milk1[i - 1];
		milky1[i] = milky1[i - 1];
		if (s[i] == 'm') {
			m1[i] += 1;
			m1[i] %= p;
		} else if (s[i] == 'i') {
			mi1[i] += m1[i];
			mi1[i] %= p;
		} else if (s[i] == 'l') {
			mil1[i] += mi1[i];
			mil1[i] %= p;
		} else if (s[i] == 'k') {
			milk1[i] += mil1[i];
			milk1[i] %= p;
		} else if (s[i] == 'y') {
			milky1[i] += milk1[i];
			milky1[i] %= p;
		}
	}
	return milky1[r];
}

int main() {
	freopen("milky.in", "r", stdin);
	freopen("milky.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) {
		m[i] = m[i - 1];
		mi[i] = mi[i - 1];
		mil[i] = mil[i - 1];
		milk[i] = milk[i - 1];
		milky[i] = milky[i - 1];
		if (s[i] == 'm') {
			m[i] += 1;
			m[i] %= p;
		} else if (s[i] == 'i') {
			mi[i] += m[i];
			mi[i] %= p;
		} else if (s[i] == 'l') {
			mil[i] += mi[i];
			mil[i] %= p;
		} else if (s[i] == 'k') {
			milk[i] += mil[i];
			milk[i] %= p;
		} else if (s[i] == 'y') {
			milky[i] += milk[i];
			milky[i] %= p;
		}
	}
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &l, &r);
		if (l == 1) printf("%lld\n", milky[r]);
		else printf("%lld\n", solve(l, r));
	}
}

