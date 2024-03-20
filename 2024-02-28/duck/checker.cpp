#include "testlib.h"
#define MAXN 1000

struct Place
{
	int r, c;
	Place(){}
	Place(int _r, int _c): r(_r), c(_c){}
};

const Place offs[8] = {
	{ 0, 3 }, { 0, -3 }, { 3, 0 }, { -3, 0 },
	{ 2, 2 }, { 2, -2 }, { -2, 2 }, { -2, -2 }
};

Place p[MAXN * MAXN];
bool vis[MAXN][MAXN], ap[MAXN * MAXN];

bool isCorr(int i, int j)
{
	int diffR = p[i].r - p[j].r, diffC = p[i].c - p[j].c;
	for (int i = 0; i < 8; i++)
		if (offs[i].r == diffR && offs[i].c == diffC)
			return true;
	return false;
}

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	int N = inf.readInt();
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
		{
			int k = ouf.readInt(1, N * N);
			if (ap[k - 1])
				quitf(_wa, "Number %d appears twice", k);
			p[k - 1] = Place(r, c); ap[k - 1] = true;
		}
	if (!(p[0].r == 0 && p[0].c == 0))
		quitf(_wa, "Not start at (1, 1)");
	vis[0][0] = true;
	for (int i = 1; i < N * N; i++)
	{
		if (vis[p[i].r][p[i].c])
			quitf(_wa, "Place (%d, %d) visited twice", p[i].r + 1, p[i].c + 1);
		if (!isCorr(i - 1, i))
			quitf(_wa, "Invalid move");
		vis[p[i].r][p[i].c] = true;
	}
	if (!isCorr(N * N - 1, 0))
		quitf(_wa, "Incorrect finish place");
	quitf(_ok, "Correct");
	return 0;
}
