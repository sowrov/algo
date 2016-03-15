#include <stdio.h>
#include <vector>
using namespace std;

int solutionWrong(vector<int> &A) {
	if (A.size() >= 23) {
		return 25;
	}
	int minv = 25, sum = 0;
	
	int size = A.size();
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			sum += (j - i + 1) * 2;
			printf("1 - %d %d\n", i, j);
			int nx = -1;
			for (int k = 0; k < size; k++) {
				if (A[k] <= nx) continue;
				if (k >= i && k <= j) {
					continue;
				}
				nx = A[k] + 6;
				printf("7 - %d %d\n",A[k], nx);
				if (k<i && nx > A[i]) {
					nx = A[i];
				}
				sum += 7;
			}
			if (sum < minv) {
				minv = sum;
			}
			sum = 0;
		}
	}
	sum = 0;
	int nx = -1;
	for (int k = 0; k < size; k++) {
		if (A[k] <= nx) continue;
		nx = A[k] + 6;
		sum += 7;
	}
	if (sum < minv) {
		minv = sum;
	}
	return minv;
}
int memo[30][30];

int dp(int st, int end, vector<int> &A) {
	if (st > end) return 0;
	if (end-st < 4) return (end-st+1)*2;
	if (memo[st][end] != -1) {
		return memo[st][end];
	}

	int minv = 25;

	int sum = 0;
	int nx = -1;
	
	for (int i = -1; i < end-st; i++) {
		sum = 0;
		sum += dp(st, st+i, A);
		int j = st + i + 1;
		if (j <= end) {
			nx = A[j] + 6;
			sum += 7;
			while (j < end && A[j] <= nx) {
				j++;
			}
			if (A[j] > nx) {
				sum += dp(j, end, A);
			}
		}
		
		if (sum < minv) {
			minv = sum;
		}
	}
	memo[st][end] = minv;

	return minv;
}

int solution(vector<int> &A) {
	memset(memo, -1, sizeof(memo));
	return dp(0, A.size()-1, A);
}

int main() {
	vector<int> vec1;
	int n, a, m;

	while (scanf("%d", &n) == 1) {
		if (n <= 0) {
			break;
		}
		vec1.clear();
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			vec1.push_back(a);
		}

		printf("%d\n",solution(vec1));
	}

	return 0;
}