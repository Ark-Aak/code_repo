#include <bits/stdc++.h>
#include "testlib.h"
#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);
	int n = inf.readInt();
	string s = inf.readToken();
	s = ' ' + s;
	int k = ouf.readInt();
	int ansk = ans.readInt();
	if (k != ansk) {
		quitf(_wa, "Expected %d, found %d", ansk, k);
	}
	rep (i, 1, k) {
		int l, r;
		char ch;
		l = ouf.readInt();
		r = ouf.readInt();
		ch = ouf.readChar();
		cerr << l << " " << r << " " << ch << endl;
		while (!isalpha(ch)) ch = ouf.readChar();
		if (l < 1 || r > n * 3 || l > r) {
			quitf(_wa, "Invalid range [%d, %d]", l, r);
		}
		rep (j, l, r) s[j] = ch;
	}
	int cnt[3] = { 0 };
	rep (i, 1, n * 3) {
		if (s[i] == 'A') cnt[0]++;
		if (s[i] == 'B') cnt[1]++;
		if (s[i] == 'C') cnt[2]++;
	}
	if (cnt[0] != n || cnt[1] != n || cnt[2] != n) {
		quitf(_wa, "Invalid string");
	}
	quitf(_ok, "Accepted");
}
