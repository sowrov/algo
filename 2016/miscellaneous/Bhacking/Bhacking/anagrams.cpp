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


int main() {
	vector<string> ori, sstr, out;
	string str,str2;
	ori.clear();
	sstr.clear();
	out.clear();
	while (std::getline(cin, str)) {
		ori.push_back(str);
		str2 = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i]!=' ') {
				str2 += tolower(str[i]);
			}
		}
		sort(str2.begin(), str2.end());
		sstr.push_back(str2);
	}
	int length = ori.size();
	vector<std::vector<int>> map(length);
	for (int i = 0; i < length; i++) {
		if (sstr[i] == "") continue;
		map.at(i).push_back(i);
		for (int j = i+1; j < length; j++) {
			if (sstr[i] == sstr[j]) {
				map.at(i).push_back(j);
				sstr[j] = "";
			}
		}
	}
	vector<string>tmpstr;
	for (int i = 0; i < length; i++) {
		str = "";
		tmpstr.clear();
		for (int j = 0; j < map.at(i).size(); j++) {
			tmpstr.push_back(ori.at(map.at(i).at(j)));
		}
		if (tmpstr.size() > 0) {
			sort(tmpstr.begin(), tmpstr.end());
			for (int j = 0; j < tmpstr.size(); j++) {
				if (j > 0) {
					str += ",";
				}
				str += tmpstr[j];
			}
			out.push_back(str);
		}
	}
	sort(out.begin(), out.end());
	for (int i = 0; i < out.size(); i++) {
		cout << out.at(i) << endl;
	}
	return 0;
}
