#include "testlib.h"

using namespace std;

string s;

bool checkPalindrome(int l, int r) {
	while (l < r) {
		if (s[l] != s[r]) return false;
		l++, r--;
	}
	return true;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    s = ouf.readToken();
	int n = inf.readInt(), k = inf.readInt();
	for (auto c : s) {
		if (c < 'a' || c > 'z') quitf(_wa, "Invalid character");
	}
	if (s.size() != n) quitf(_wa, "Wrong length");
	int cnt = checkPalindrome(0, n - 1);
	for (int i = 0; i < n - 1; i++) {
		cnt += (checkPalindrome(0, i) && checkPalindrome(i + 1, n - 1));
	}
	if (cnt != k) quitf(_wa, "Wrong number of ways to split the string. Expected %d, found %d", k, cnt);
	quitf(_ok, "OK");
}