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

#define clrz(_arr) memset(_arr, 0, sizeof(_arr))
#define clrm(_arr) memset(_arr, -1, sizeof(_arr))
#define P31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

bool comp(char a, char b) {
	return a > b;
}
int main() {
	int t, mswt;
	string str, minStr, tmp;
	cin >> t;
	while (t--) {
		minStr = "";
		cin >> str;
		int i = str.length();
		mswt = -1;
		tmp = str;
		while (i-->0) {
			int swt = -1;
			for (int j = i - 1; j >= 0; j--) {
				if (tmp[j] < tmp[i]) {
					char ch = tmp[j];
					tmp[j] = tmp[i];
					tmp[i] = ch;
					swt = j;
					break;
				}
			}
			if (swt != -1) {
				if (swt>mswt) {
					sort(tmp.begin() + swt + 1, tmp.end());
					if (minStr == "" || tmp < minStr) {
						minStr = tmp;
					}
					mswt = swt;
				}
				tmp = str;
			}
		}
		if (minStr == "") {
			cout << "no answer" << endl;
		} else {
			cout << minStr << endl;
		}
	}
	return 0;
}
