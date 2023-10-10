#include <bits/stdc++.h>
#include <windows.h>

typedef long long ll;

std::mt19937 _rnd(time(0));
std::mt19937_64 _rnd_64(time(0));

namespace Rand{
	int rand_int(int l,int r){return abs((int)_rnd())%(r-l+1)+l;}
	ll rand_long(ll l,ll r){return abs((ll)_rnd_64())%(r-l+1)+l;}
	int rand_bool(){return rand_int(0,1);}
	char rand_lower_alpha(){return char('a'+rand_int(0,25));}
	char rand_upper_alpha(){return char('A'+rand_int(0,25));}
	char rand_alpha(){return char((rand_int(0,1) ? 'A' : 'a') + rand_int(0,25));}
	std::string rand_lower_string(int len){
		std::string ret;
		for(int i=0;i<len;i++)ret += rand_lower_alpha();
		return ret;
	}
	std::string rand_upper_string(int len){
		std::string ret;
		for(int i=0;i<len;i++)ret += rand_upper_alpha();
		return ret;
	}
	std::string rand_string(int len){
		std::string ret;
		for(int i=0;i<len;i++)ret += rand_alpha();
		return ret;
	}
};

namespace IO{
	template<typename T>
	void _print(T x) {std::cout << x;}
	void print(){}
	void eoln(){putchar('\n');}
	template<typename T,typename... Types>
	void print(T first, Types... args){_print(first);sizeof...(args) ? putchar(' '),print(args...) : print(args...);}
	template<typename T,typename... Types>
	void println(T first, Types... args){print(first,args...);eoln();}
}

