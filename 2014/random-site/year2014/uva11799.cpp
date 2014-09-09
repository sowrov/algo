#include <stdio.h>

int main() {
	int T, N, m=0, c;

	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d", &N);
		m = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &c);
			if (c>m) {
				m = c;
			}
		}
		printf("Case %d: %d\n", cas, m);
	}
	return 0;
}