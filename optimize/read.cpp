#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

struct IO {
#define MAXSIZE (1 << 20)
	char buf[MAXSIZE], *p1, *p2;
	char pbuf[MAXSIZE], *pp;

	IO() : p1(buf), p2(buf), pp(pbuf) {}
	~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }

	char gc() {
		if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
		return p1 == p2 ? ' ' : *p1++;
	}

	bool blank(char ch) {
		return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}

	template <class T>
	inline void read(T &x) {
		double tmp = 1;
		bool sign = 0;
		x = 0;
		char ch = gc();
		for (; !isdigit(ch); ch = gc())
			if (ch == '-') sign = 1;
		for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
		if (ch == '.')
			for (ch = gc(); isdigit(ch); ch = gc())
				tmp /= 10.0, x += tmp * (ch - '0');
		if (sign) x = -x;
	}

	void push(const char &c) {
		if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
		*pp++ = c;
	}

	template <class T>
	void write(T x) {
		if (x < 0) x = -x, push('-');
		static T sta[35];
		T top = 0;
		do sta[top++] = x % 10, x /= 10; while (x);
		while (top) push(sta[--top] + '0');
	}

	template <class T>
	void write(T x, char lastChar) {
		write(x), push(lastChar);
	}
} io;

int n;
ll sum;

signed main() {
	io.read(n);
	for (int i = 0; i < (n >> 3); i++) {
		cerr << "???" << endl;
		int x;
		io.read(x);
		sum += x;
		io.read(x);
		sum += x;
		io.read(x);
		sum += x;
		io.read(x);
		sum += x;
		io.read(x);
		sum += x;
		io.read(x);
		sum += x;
		io.read(x);
		sum += x;
		io.read(x);
		sum += x;
	}
	for (int i = ((n >> 3) << 3); i < n; i++) {
		int x;
		io.read(x);
	}
	return 0;
}
