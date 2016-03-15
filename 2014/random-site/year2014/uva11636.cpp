#include <stdio.h>

int main() {
	int cas = 1, v;
	while (scanf("%d", &v) == 1) {
		if (v < 0) {
			break;
		}
		int line = 1, out=0;
		while (line < v) {
			line += line;
			out++;
		}

		printf("Case %d: %d\n",cas++, out);
	}
	return 0;
}