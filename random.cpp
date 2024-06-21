#include <bits/stdc++.h>

using namespace std;

const int mask = 147744151;
typedef unsigned long long ull;
const ull pg1 = 0x1BCDEF998244353F;
const ull pe2 = 0x1400000007CCCCCF;
const ull pn3 = 0xFE7CBAFEDCBA123F;
const ull ps4 = 0x7777CD777777777F;
const ull ph5 = 0x404040404040404F;
const ull pi6 = 0x123456789111111F;
const ull pn7 = 0x1A2B3C4D5E6FFFFF;

ull shift(ull val) {
	val ^= mask;
	val = (val ^ (val << 14)) & pg1;
	val = (val ^ (val >> 7)) & pe2;
	val = (val ^ (val << 7)) & pn3;
	val = (val ^ (val << 4)) & ps4;
	val = (val ^ (val >> 41)) & ph5;
	val = (val ^ (val >> 5)) & pi6;
	val = (val ^ (val << 1)) & pn7;
	val ^= mask;
	return val;
}

ull seed = /* 比赛结束时 Adchory 的粉丝数 */;

int main() {
	mt19937_64 rnd(seed);
	ull val = shift(rnd()) % 100 + 1;
	printf("%llu\n", val);
}
