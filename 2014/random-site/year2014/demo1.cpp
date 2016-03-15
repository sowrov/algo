#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
	long long* f = new long long[A.size()];
	long long* b = new long long[A.size()];
	f[0] = (A[0]);
	for (int i = 1; i < A.size(); i++) {
		f[i] = (f[i-1]+A[i]);
	}
	b[A.size() - 1] = (A[A.size() - 1]);
	for (int i = A.size() - 2; i >= 0; i--) {
		b[i] = b[i + 1] + A[i];
	}
	int out = 0;
	for (int i = 0; i < A.size(); i++) {
		if (i == 0) {
			if (b[i + 1] == 0) {
				return 0;
			}
		} if (i == A.size() - 1) {
			if (f[i - 1] == 0) {
				return i;
			}
		}
		else {
			if (f[i - 1] == b[i + 1]) {
				return i;
			}
		}
	}
	return -1;
}

int main() {
	vector<int> vec1, vec2;
	int n,a, m;

	while (scanf("%d %d", &n, &m) == 2) {
		if (n <= 0) {
			break;
		}
		vec1.clear();
		vec2.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			vec1.push_back(a);
		}

		for (int i = 0; i < m; i++) {
			scanf("%d", &a);
			vec2.push_back(a);
		}
		vector<int> mrg(vec1.size()+vec2.size());
		merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), mrg.begin());

		for (int i = 0; i < mrg.size(); i++) {
			printf("%d ", mrg[i]);
		}
		printf("\n");
		//printf("%d\n",solution(vec));
	}

	return 0;
}

