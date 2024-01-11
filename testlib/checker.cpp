#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
	string ansString = ouf.readLine();
	for (auto &c : ansString) {
		c = tolower(c);
	}
	if (ansString.find("lmx") != string::npos && ansString.find("zqh") != string::npos) {
		quitf(_ok, "OK, link is https://lanzouw.com/iba8T1k0v3gh");
	}
	else quitf(_wa, "WA, your string is %s", ansString.c_str());
    return 0;

}