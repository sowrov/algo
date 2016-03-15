#include <stdio.h>
int solution(int v) {
	int last = 0, cou = 0, maxv = 0;
	while (v>0) {
		if (v & 1) {
			if (last == 1) {
				if (cou > maxv) {
					maxv = cou;
				}
			}
			last = 1;
			cou = 0;
		}
		else if (last == 1) {
			cou++;
		}
		v >>= 1;
	}
	return maxv;
}

int main() {
	int v;
	while (scanf("%d", &v)==1) {
		if (v < 0) break;
		printf("%d\n",solution(v));
		
	}
	return 0;
}