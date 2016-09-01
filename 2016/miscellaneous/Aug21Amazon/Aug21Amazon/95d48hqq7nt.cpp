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

void dfs(vector<vector<int>>& res, int x, int y, int v) {
	if (x < 0 || y < 0 || x >= res.size() || y >= res[x].size()) {
		return;
	}
	if (res[x][y] == -1 || res[x][y] > (v + 1)) {
		res[x][y] = v + 1;

		dfs(res, x + 1, y, v+1);
		dfs(res, x-1, y, v+1);
		dfs(res, x, y+1, v + 1);
		dfs(res, x, y-1, v + 1);
	} else {
		return;
	}
}

vector < vector < int > > getLockerDistanceGrid(int cityLength, int cityWidth, vector < int > lockerXCoordinates, vector < int > lockerYCoordinates) {
	vector<vector<int>> res(cityLength, std::vector<int>(cityWidth, -1));

	for (int i = 0; i < lockerXCoordinates.size(); i++) {
		int x = lockerXCoordinates[i] - 1;
		int y = lockerYCoordinates[i] - 1;
		dfs(res, x, y, -1);
	}
	return res;
}

int main() {
	int x, y;
	int n, v;
	vector<int> xs, ys;

	cin >> x >> y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v;
		xs.push_back(v);
	}

	for (int i = 0; i < n; i++) {
		cin >> v;
		ys.push_back(v);
	}

	vector<vector<int>> res = getLockerDistanceGrid( y, x, xs, ys);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
		}
		cout << endl;
	}
	return 0;
}
