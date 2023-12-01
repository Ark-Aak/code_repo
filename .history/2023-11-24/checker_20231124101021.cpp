#include "testlib.h"

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int T, n;
int a[200005], b[200005];
int p[200005], hasSol[15];

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
	T = inf.readInt();
	rep (i, 1, T) hasSol[i] = ans.readInt();
	rep (__, 1, T) {
		n = inf.readInt();
		rep (i, 1, n) a[i] = inf.readInt();
		rep (i, 1, n) b[i] = inf.readInt();
		p[1] = ouf.readInt();
		if (p[1] == -1) {
			if (hasSol[__] == 1)
				quitf(_wa, "Wrong Answer at testcase %d, this testcase has solution but found -1.", __);
			else continue;
		}
		rep (i, 2, n) p[i] = ouf.readInt();
		int suma = 0;
		int sumb = 0;
		int tsuma = 0;
		int tsumb = 0;
		rep (i, 1, n) {
			if (p[i]) suma += a[i];
			if (p[i]) sumb += b[i];
			if (!p[i]) tsuma += a[i];
			if (!p[i]) tsumb += b[i];
		}
		if (suma != tsuma || sumb != tsumb)
			quitf(_wa, "Wrong Answer at testcase %d, found %d, %d, %d, %d", __, suma, tsuma, sumb, tsumb);
	}
	quitf(_ok, "OK");
}