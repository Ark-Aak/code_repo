#include "testlib.h";

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int T, n;
int a[200005], b[200005];
int ap[200005], bp[200005], hasSol[15];

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
	T = inf.readInt();
	rep (i, 1, T) hasSol[i] = ans.readInt();
	rep (__, 1, T) {
		n = inf.readInt();
		rep (i, 1, n) a[i] = inf.readInt();
		rep (i, 1, n) b[i] = inf.readInt();
		ap[1] = ouf.readInt();
		if (ap[1] == -1) {
			if (hasSol[__] == 1) quitf(_wa, "Wrong Answer, this testcase has solution but found -1.");
		}
		rep (i, 2, n) ap[i] = ouf.readInt();
		rep (i, 1, n) bp[i] = ouf.readInt();
	}
	quitf(_ok, "OK");
}