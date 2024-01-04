#include <bits/stdc++.h>

using namespace std;

#define int long long

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const string stdFileName="dreamer";//std文件名
const string probId="data";//题目Id
const int dataNum=20;//数据组数
//输入输出数据形如data_1.in/data_1.out

#define __OPTION_NO_REDIRECT

//拼合输入文件名，勿动
string getInName(int x){
	stringstream name;
	name << "data/" << probId << "_" << x << ".in";
	return name.str();
}

//拼合输入文件名，勿动
string getOutName(int x){
	stringstream name;
	name << "data/" << probId << "_" << x << ".out";
	return name.str();
}

mt19937_64 _rnd(time(0));

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

#include "./lib/pollardrho.hpp"

//生成数据，x为数据编号
void Gen(int x){
	freopen(getInName(x).c_str(),"wb",stdout);
	//输出到 stdout 即可
	int N, K, flgB = 0, flgC = 0, T = 20;
	if (x == 1) K = 4, N = 80, T = 5;
	if (x == 2) K = 10, N = 1e6, T = 5;
	if (x == 3) K = 20, N = 1e12, T = 5;
	if (x == 4) K = 1, N = 1e18;
	if (x == 5) K = 1e3, N = 1e18;
	if (x == 6) K = 1e5, N = 1e18;
	if (x == 7) K = 1e6, N = 1e18, flgB = 1;
	if (x == 8) K = 1e6, flgB = 1;
	if (x == 9) K = 1e6, flgC = 1;
	if (x == 10) K = 1e6;
	printf("%lld\n", T);
	rep (i, 1, 20) {
		rerun:
		int k = rnd(max(1ll, (int) 0.9 * K), K), m = rnd(9e8, 1.14e9);
		if (flgC) {
			int r = rnd(1, 3);
			if (r == 1) m = 998244353;
			if (r == 2) m = 1000000007;
			if (r == 3) m = 19260817;
		}
		__int128 n = 0;
		if (x >= 8) {
			n = (__int128) 11741730;
			n *= 146078888479ll;
			n *= rnd(1, (__int128) 1e24 / n);
		}
		else {
			n = rnd(max(1ll, (int) 0.9 * N), N);
		}
		n = max((__int128) 1, n);
		vector <pair <__int128, __int128> > fac = PollardRhoSplit(n);
		if (flgC) {
			for (auto [a, b] : fac) {
				if (a == m) goto rerun;
			}
		}
		printf("%lld %lld\n", k, m);
		printf("%lld\n", fac.size());
		for (auto [a, b] : fac) {
			cerr << (long long) a << "^" << (flgB ? 1 : (long long) b) << " ";
			printf("%lld %lld\n", (long long) a, flgB ? 1 : (long long) b);
		}
		cerr << endl;
	}
}

signed main(){
	//拼合管道命令，勿动
	system(("g++ " + stdFileName + ".cpp -o " + stdFileName + " -std=c++17").c_str());
	system("mkdir data > nul");
	int i = 1, Start, End;
	while(1){
		cerr << "Generating Data " << i << endl; Gen(i);
#ifdef __OPTION_NO_REDIRECT
		string command = stdFileName +" " + getInName(i) + " " + getOutName(i);
#else
		string command = stdFileName + " < " + getInName(i) + " > " + getOutName(i);
#endif
		cerr << "Executing command: " << command << endl;
		Start = clock();
		system(command.c_str());
		End = clock();
		cerr << "Executing time: " << (double)(End - Start) / CLOCKS_PER_SEC << "sec" << endl;
		//if((double)(End - Start) / CLOCKS_PER_SEC > 2) break;
		++i;
		if(i > dataNum) break;
	}
}