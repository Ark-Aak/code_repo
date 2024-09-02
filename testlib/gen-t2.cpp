#include <bits/stdc++.h>

using namespace std;

#define _rep(i, a, b) for (int i = (a); i >= (b); i--)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long

const string stdFileName = "std"; //std文件名
const string probId = "data"; //题目Id
const int dataNum = 0; //数据组数
const int taskNum = 5;
const int taskDataNum[] = { 50, 5, 50, 50, 50 };

string getInName(int x, int sub) {
	if (sub == 0) return "data/" + probId + "_" + to_string(x) + ".in";
	else return "data/" + probId + "_" + to_string(sub) + "-" + to_string(x) + ".in";
}

string getOutName(int x, int sub) {
	if (sub == 0) return "data/" + probId + "_" + to_string(x) + ".out";
	else return "data/" + probId + "_" + to_string(sub) + "-" + to_string(x) + ".out";
}

mt19937_64 _rnd(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { uniform_int_distribution <ll> dt(l, r); return dt(_rnd); }

string getRandomToken(int len, char base = 'a', int siz = 26) {
	string res;
	rep (i, 1, len) res += base + rnd(0, siz - 1);
	return res;
}

string hack(int len, vector <char> &hack) {
	string res;
	rep (i, 1, len) res += hack[rnd(0, hack.size() - 1)];
	return res;
}

vector <char> hack1 = { 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z'};
vector <char> hack2 = { 'k'};
vector <char> hack3 = { 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'y', 'y', 'y', 'y', 'z', 'z', 'z', 'z'};
vector <char> hack4 = { 'y', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z', 'z'};

//生成数据，x为数据编号
void Gen(int x, int sub) {
	ignore = freopen(getInName(x, sub).c_str(),"wb",stdout);
	int n = 0, q = 0;
	bool flg1 = 0, flg2 = 0;
	if (sub == 1) n = rnd(90, 100), q = rnd(90, 100);
	if (sub == 2) n = rnd(4e5, 5e5), q = rnd(9e4, 1e5), flg1 = 1;
	if (sub == 3) n = rnd(4e5, 5e5), q = 10;
	if (sub == 4) n = rnd(9e4, 1e5), q = rnd(4e4, 5e4), flg2 = 1;
	if (sub == 5) n = rnd(4e5, 5e5), q = rnd(9e4, 1e5);
	if (flg2) {
		if (x & 1) cout << hack(n, hack3) << endl;
		else cout << getRandomToken(n, 'x', 3) << endl;
	}
	else {
		if (x == 1) cout << hack(n, hack2) << endl;
		else if (x == 2) cout << getRandomToken(n, 'u', 1) << endl;
		else if (x % 4 == 1) cout << hack(n, hack1) << endl;
		else if (x % 4 == 2) cout << hack(n, hack3) << endl;
		else if (x % 4 == 3) cout << hack(n, hack4) << endl;
		else cout << getRandomToken(n) << endl;
	}
	cout << q << endl;
	rep (i, 1, q) {
		int l, r, offset = 0;
		if (i % 4 == 3 || i % 4 == 2) {
			l = rnd(1, 5);
			r = rnd(6, 10);
			offset = rnd(0, n - 10);
		}
		else if (i % 4 == 0) {
			l = rnd(1, n / 10);
			r = rnd(n * 9 / 10, n);
		}
		else {
			l = rnd(1, n);
			r = rnd(1, n);
			if (l > r) swap(l, r);
		}
		if (x == 2 && rnd(0, 5)) {
			l = rnd(1, n - 63);
			int k = rnd(1, (n - l + 1) / 64);
			r = l + k * 64 - 1;
			assert((r - l + 1) % 64 == 0);
			offset = 0;
		}
		if (l > r) swap(l, r);
		if (flg1) r = l;
		cout << l + offset << " " << r + offset << endl;
		assert(l <= r && r + offset <= n && l >= 1);
	}
}

signed main(){
	ignore = system(("g++ " + stdFileName + ".cpp -o " + stdFileName + " -O2 -std=c++17").c_str());
	ignore = system("mkdir data");
	int i = 1, sub = 1;
	while (1) {
		string command = "";
		#ifdef __linux__
		command = "ulimit -s unlimited && ./";
		#endif
		if (taskNum == 0) {
			cerr << "Generating testcase " << i << endl; Gen(i, 0);
			command += stdFileName + "<" + getInName(i, 0) + ">" + getOutName(i, 0);
		}
		else {
			cerr << "Generating subtask " << sub << " testcase " << i << endl; Gen(i, sub);
			command += stdFileName + "<" + getInName(i, sub) + ">" + getOutName(i, sub);
		}
		int st = clock(); ignore = system(command.c_str()); int ed = clock();
		fprintf(stderr, "Time: %.2lfs\n", 1.0 * (ed - st) / CLOCKS_PER_SEC); ++i;
		if (taskNum > 0) {
			if (i > taskDataNum[sub - 1]) {
				i = 1, ++sub;
				if (sub > taskNum) break;
			}
		}
		else if(i > dataNum) break;
	}
}
