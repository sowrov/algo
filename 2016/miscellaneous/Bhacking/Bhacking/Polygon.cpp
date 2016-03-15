#include "iomanip"
#include "vector"
#include "utility"
#include "cstring"
#include "numeric"
#include "set"
#include "ctime"
#include "fstream"
#include "cstdlib"
#include "bitset"
#include "cctype"
#include "map"
#include "algorithm"
#include "cassert"
#include "cstdio"
#include "string"
#include "list"
#include "sstream"
#include "iostream"
#include "deque"
#include "stack"
#include "cmath"
#include "queue"
#include "functional"

using namespace std;


int main() {
	int a, b, c, d;
	int s, r, p;
	s = r = p = 0;
	while (scanf("%d %d %d %d", &a, &b, &c, &d) == 4) {
		if (a==b && b==c && c==d && a>0 && b>0 && c>0 && d>0) {
			s++;
		} else if (a == c && b == d && a>0 && b>0 && c>0 && d>0) {
			r++;
		} else {
			p++;
		}
	}
	printf("%d %d %d\n",s, r, p);
	return 0;
}
