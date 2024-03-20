#include <bits/stdc++.h>

using namespace std;

#define int long long

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const string stdFileName="std";//std文件名
const string probId="brainwave";//题目Id
const int dataNum = 0;//数据组数
const int taskNum = 5;
const int taskDataNum[] = {1, 1, 1, 1, 1};
// 输入输出数据形如data_1-1.in/data_1-1.out

//#define __OPTION_NO_REDIRECT

//拼合输入文件名，勿动
string getInName(int x, int sub){
	if (sub == 0) return "data/" + probId + "_" + to_string(x) + ".in";
	else return "data/" + probId + "_" + to_string(sub) + "-" + to_string(x) + ".in";
}

//拼合输入文件名，勿动
string getOutName(int x, int sub){
	if (sub == 0) return "data/" + probId + "_" + to_string(x) + ".out";
	else return "data/" + probId + "_" + to_string(sub) + "-" + to_string(x) + ".out";
}

mt19937_64 _rnd(time(0));

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

vector <int> makeYes(int n) {
	vector <int> res;
	res.push_back(0);
	int l = rnd(3, n / 2), r = rnd(n / 2 + 1, n - 3);
	if (l > r) swap(l, r);
	rep (i, 1, n / 2) res.push_back(i);
	_rep (i, n / 2 + 1, 2) res.push_back(i);
	rep (i, l, r) res[i] -= 2;
	res.erase(res.begin());
	return res;
}

//生成数据，x为数据编号
void Gen(int x, int sub){
	freopen(getInName(x, sub).c_str(),"wb",stdout);
	//输出到 stdout 即可
	int T = 3, n;
	printf("%lld\n", T);
	rep (_i, 1, T) {
		bool isRandom = 0, isSp2 = 0;
		if (sub == 1) {
			n = 10;
		}
		else if (sub == 2) {
			n = 20;
		}
		else if (sub == 3) {
			n = rnd(4e4, 5e4) * 2;
			isRandom = 1;
		}
		else if (sub == 4) {
			n = rnd(4e4, 5e4);
			isSp2 = 1;
		}
		else {
			n = rnd(4e4, 5e4) * 2;
		}
		printf("%lld\n", n);
		if (isRandom) {
			rep (i, 1, n) {
				printf("%lld ", rnd(1, 1e9));
			}
		}
		else if (isSp2) {
			bool flg = 0;
			int cnt = 0;
			if (n & 1) n--, flg = 1;
			rep (i, 1, n / 2) {
				printf("%lld ", i);
				cnt++;
			}
			rep (i, 2, n / 2 + 1) {
				printf("%lld ", i);
				cnt++;
			}
			if (flg) cnt++, printf("%lld ", rnd(1, n / 2));
			if (flg) n++;
			assert(cnt == n);
		}
		else {
			vector <int> v;
			if (rnd(0, 1)) {
				int val = 0.6 * n;
				rep (i, 1, val) v.push_back(i);
				n -= val;
				rep (i, 1, n) v.push_back(rnd(1, val));
			}
			else v = makeYes(n);
			shuffle(v.begin(), v.end(), _rnd);
			for (auto V : v) {
				printf("%lld ", V);
			}
		}
		printf("\n");
	}
}

signed main(){
	//拼合管道命令，勿动
	system(("g++ " + stdFileName + ".cpp -o " + stdFileName + " -O2 -std=c++17 -Wl,--stack=51200000000").c_str());
	system("mkdir data > nul");
	int i = 1, sub = 1, Start, End;
	while(1){
		string command;
		if (taskNum == 0) {
			cerr << "Generating Data " << i << endl; Gen(i, 0);
#ifdef __OPTION_NO_REDIRECT
			command = stdFileName + " " + getInName(i, 0) + " " + getOutName(i, 0);
#else
			command = stdFileName + " < " + getInName(i, 0) + " > " + getOutName(i, 0);
#endif
		}
		else {
			cerr << "Generating Data task " << sub << " data " << i << endl; Gen(i, sub);
#ifdef __OPTION_NO_REDIRECT
			command = stdFileName + " " + getInName(i, sub) + " " + getOutName(i, sub);
#else
			command = stdFileName + " < " + getInName(i, sub) + " > " + getOutName(i, sub);
#endif
		}
		cerr << "Executing command: " << command << endl;
		Start = clock();
		system(command.c_str());
		End = clock();
		cerr << "Executing time: " << (double)(End - Start) / CLOCKS_PER_SEC << "sec" << endl;
		//if((double)(End - Start) / CLOCKS_PER_SEC > 2) break;
		++i;
		if (taskNum > 0) {
			if (i > taskDataNum[sub - 1]) {
				i = 1;
				++sub;
				if (sub > taskNum) break;
			}
		}
		else if(i > dataNum) break;
	}
}