#include <cstdio>
#include <cstring>
extern "C" {
void srand(unsigned int seed) {
	fprintf(stderr, "function srand is banned\n");
	throw 1;
}
int rand() {
	fprintf(stderr, "function rand is banned\n");
	throw 1;
	return 0;
}
int system(const char *command) {
	fprintf(stderr, "function system is banned\n");
	throw 1;
	return 0;
}
}