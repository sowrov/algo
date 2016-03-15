#include <string>
#include <stdio.h>
using namespace std;

int solution(string &str) {
	// write your code in C++11 (g++ 4.8.2)
	int len = 0, upper = 0, maxv=0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			if (upper == 1) {
				if (len>maxv) {
					maxv = len;
				}
			}
			len = 0; upper = 0;
		}
		else {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				upper = 1;
			}
			len++;
		}
	}
	if (upper == 1) {
		if (len>maxv) {
			maxv = len;
		}
	}
	return maxv==0?-1:maxv;
}

int main() {
	char str[1000];

	while (1) {
		scanf("%s", str); 
		string s = str;
		printf("%d\n", solution(s));
	}
	return 0;
}