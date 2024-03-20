#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int a[100005], b[100005], n;
map <int, int> buc;

int main(int argc, char** argv) {
	registerLemonChecker(argc, argv);
	int T = inf.readInt();
	for (int __ = 1; __ <= T; __++) {
		buc.clear();
		n = inf.readInt();
		memset(b, 0, sizeof b);
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++) a[i] = inf.readInt();
		for (int i = 1; i <= n; i++) buc[a[i]]++;
		string sol = ans.readToken();
		string tsol = ouf.readToken();
		if (sol == "YES" && tsol == "Toolazytospray") quitf(_wa, "Too lazy to spray #1 on %d, read %s", __, tsol.c_str());
		if (sol == "NO" && tsol != "Toolazytospray") quitf(_wa, "Too lazy to spray #2 on %d, read %s", __, tsol.c_str());
		if (sol == "NO") continue;
		// tsol 转数字到 b[1]
		for (auto c : tsol) {
			if (!isdigit(c)) continue;
			b[1] = b[1] * 10 + c - '0';
		}
		for (int i = 2; i <= n; i++) b[i] = ouf.readInt();
		for (int i = 1; i <= n; i++) buc[b[i]]--;
		for (auto it : buc) if (it.second) quitf(_wa, "Too lazy to spray #3 on %d with b[1] = %d", __, b[1]);
		b[n + 1] = b[1];
		for (int i = 1; i <= n; i++) {
			if (abs(b[i] - b[i + 1]) != 1) quitf(_wa, "Too lazy to spray #4 on %d", __);
		}
	}
	quitf(_ok, "Accepted");
}
