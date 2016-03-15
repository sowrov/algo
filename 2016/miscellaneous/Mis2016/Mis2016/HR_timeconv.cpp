#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string ap;
	char str[3];
	int h, m, s;
	scanf("%d:%d:%d%s", &h, &m, &s, str);
	printf("%02d %02d %02d - %s",h, m, s, str);
	return 0;
}
