#include <stdio.h>

int main() {
	int T, N, L, H, c, c1;

	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d %d", &N, &c);
		L=H= 0;
		for (int i = 1; i < N; i++) {
			scanf("%d", &c1);
			if (c1>c) H++;
			if (c1 < c) L++;
			c = c1;
		}
		printf("Case %d: %d %d\n", cas, H, L);
	}
	return 0;
}