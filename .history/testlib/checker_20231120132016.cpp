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
	if (s.size() != n) quitf(_wa, "Wrong length");
	for (int i = 0; i < n; i++) {
		
	}
}