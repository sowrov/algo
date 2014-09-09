#include <stdio.h>
#include <math.h>

int main() {
	int L, H;
	while (scanf("%d %d", &L, &H)==2 && L && H) {
		int Ls = sqrt((double)L);
		int Hs = sqrt((double)H);
		int c = Hs - Ls;
		if (Ls*Ls == L) {
			c++;
		}
		printf("%d\n", c);
	}
	return 0;
}