#include <bits/stdc++.h>

#define SP putc(' ')
#define EL putc('\n')
char getc();
void putc(char c);
template <typename T>
void read(T &);
template <typename T>
void write(const T &);

typedef std::pair<int, int> pii;
typedef long long int ll;
typedef std::tuple<int, int, int> ti;
const int N = 300005;
const int B = 570;
const int iinf = 1e9 + 7;

namespace Big_Part {
	ll query();
} // namespace Big_Part

namespace Small_Part {
	int calc[(N >> 9) + 5][(N >> 9) + 5];
	std::vector<ti> Vl[(N >> 9) + 5], Vr[(N >> 9) + 5];
	void update(int t);
	ll query();
} // namespace Small_Part

std::vector<pii> segr[N];
int S[N], k;
int l[N], r[N], w[N], tim;
int n, q;

int main()
{
	read(n), read(q);
	for (int i = 0; i <= (n >> 9) + 1; ++i)
	{
		for (int j = 0; j <= (n >> 9) + 1; ++j)
		{
			Small_Part::calc[i][j] = iinf;
		}
	}
	ll lasans = 0;
	for (int i = 1; i <= q; ++i)
	{
		int op;
		read(op);
		lasans %= iinf;
		if (op == 1)
		{
			++tim;
			read(l[tim]), read(r[tim]), read(w[tim]);
			l[tim] ^= lasans, r[tim] ^= lasans;
			segr[r[tim]].push_back({l[tim], w[tim]});
			Small_Part::update(tim);
		}
		else
		{
			read(k);
			for (int i = 1; i <= k; ++i)
			{
				read(S[i]);
				S[i] ^= lasans;
			}
			std::sort(S + 1, S + k + 1);
			if (k > B)
				lasans = Big_Part::query();
			else
				lasans = Small_Part::query();
			if (lasans > 9e14)
				lasans = 0;
			write(lasans), EL;
		}
	}
	return 0;
}

namespace Big_Part {
	namespace Block {
		int B2, shift;
		ll w1[N], w2[N];
		void init(int k) {
			memset(w1, 0x3f, sizeof(w1));
			shift = 1;
			//二进制意义下的块长
			while ((1 << (shift << 1)) < k) ++shift;
			memset(w2, 0x3f, sizeof(w2));
			//只清空整块
		}
		void update(int x, ll w) {
			for (int i = (x >> shift) - 1; ~i; --i)
				w2[i] = std::min(w2[i], w);//整块后缀最小值
			for (int i = x >> shift << shift; i <= x; ++i)
				w1[i] = std::min(w1[i], w);//块内后缀最小值
		}
		ll query(int x) { return std::min(w1[x], w2[x >> shift]); }
	} // namespace Block
	int pos[N];
	ll query() {
		Block::init(k);
		Block::update(1, 0);
		pos[n + 1] = k + 1;//边界条件
		//pos：后方离他最近的S的下标
		for (int i = n, j = k; i >= 1; --i)
			if (S[j] == i) pos[i] = j, --j;
			else pos[i] = pos[i + 1];
		//线段树优化dp，分块版
		for (int i = 1, j = S[1]; i <= k; ++i) {
			ll dp = 1e15;
			while (j <= n && (i == k || j < S[i + 1])) {
				//segr:r,{l,w}
				for (pii p : segr[j])
					dp = std::min(dp, Block::query(pos[p.first]) + p.second);
				++j;
			}
			if (i == k) return dp;
			if (dp <= 9e14) Block::update(i + 1, dp);//合法修改
		}
		return -1;
	}
} // namespace Big_Part

namespace Small_Part
{
	void update(int t)//插入排序
	{
		int lp = l[t] >> 9, rp = r[t] >> 9;//块编号
		Vl[lp].insert(std::lower_bound(Vl[lp].begin(), Vl[lp].end(), ti{l[t], r[t], w[t]}, [](ti i, ti j)
									   { return std::get<1>(i) > std::get<1>(j); }),
					  {l[t], r[t], w[t]});
		//排序右端点
		Vr[rp].insert(std::lower_bound(Vr[rp].begin(), Vr[rp].end(), ti{l[t], r[t], w[t]}, [](ti i, ti j)
									   { return std::get<0>(i) < std::get<0>(j); }),
					  {l[t], r[t], w[t]});
		//排序左端点
		for (int i = rp; i >= lp; --i)
			calc[i][lp] = std::min(calc[i][lp], w[t]);
			//calc r l 一个区间块的区间最小值
	}
	ll dp[N];
	int dis[B + 5][B + 5];
	ll query()
	{
		for (int i = 1; i <= k; ++i)//初始化
		{
			for (int j = 1; j <= i; ++j)
			{
				dis[i][j] = iinf;
			}
		}
		S[k + 1] = n + 1;
		for (int i = 1; i <= k; ++i)//左端点
		{
			int now = iinf;
			int j = k;
			for (ti t : Vl[S[i] >> 9])//块编号>>9
			{
				int l, r, w;
				std::tie(l, r, w) = t;//解开
				while (S[j] > r)
				{
					dis[j][i] = now;
					--j;
					//dis j i 表示 大小为 s[j]  s[i] 区间内的w最小值
				}
				if (j < i)
					break;
				if (l <= S[i] && w < now)
					now = w;
			}
			while (j >= i)
			{
				dis[j][i] = now;
				--j;
			}
			now = iinf, j = 1;
			for (ti t : Vr[S[i] >> 9])
			{
				int l, r, w;
				std::tie(l, r, w) = t;
				while (S[j] < l)
				{
					dis[i][j] = std::min(dis[i][j], now);
					++j;
				}
				if (j > i)
					break;
				if (r >= S[i] && w < now)
					now = w;
			}
			while (j <= i)
			{
				dis[i][j] = std::min(dis[i][j], now);
				++j;
			}
		}
		dp[0] = 0;
		for (int i = 1; i <= k; ++i)
		{
			dp[i] = 1e15;
			int rp = (S[i] >> 9) + 1;//右块
			int t = 0;
			int now = iinf;
			for (int j = 1; j <= i; ++j)
			{
				while ((S[j] >> 9) > t)
				{
					now = std::min(now, calc[rp][t]);
					++t;
				}
				now = std::min(now, dis[i][j]);
				if (now <= 1e9)
					dp[i] = std::min(dp[i], dp[j - 1] + now);
			}
		}
		return dp[k];
	}
} // namespace Small_Part

const int SIZE = 1 << 21;
char getc() {
	static char buf[SIZE], *p1 = buf, *p2 = buf;
	return (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++;
}
void putc(char c) {
	static char buf[SIZE], *p1 = buf, *p2 = buf + SIZE - 1;
	static class flusher {
	public:
		~flusher() { fwrite(buf, 1, p1 - buf, stdout); }
	} _flusher;
	*p1++ = c;
	if (p1 == p2) {
		fwrite(buf, 1, p1 - buf, stdout);
		p1 = buf;
	}
}
template <typename T>
void read(T &Re) {
	T k = 0;
	char ch = getc();
	int flag = 1;
	while (!std::isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getc();
	}
	while (std::isdigit(ch))
		k = k * 10 + ch - '0', ch = getc();
	Re = flag * k;
}
template <typename T>
void write(const T &Wr) {
	if (Wr < 0) putc('-'), write(-Wr);
	else if (Wr < 10) putc(Wr + '0');
	else write(Wr / 10), putc((Wr % 10) + '0');
}
