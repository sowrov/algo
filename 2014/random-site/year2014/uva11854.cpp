#include <stdio.h>

int main() {
	int a, b, c;

	while (scanf("%d %d %d", &a, &b, &c) == 3) {
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		if (a > c) {
			a ^= c;
			c ^= a;
			a ^= c;
		}
		if (b > c) {
			b ^= c;
			c ^= b;
			b ^= c;
		}
		if (a*a + b*b == c*c) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}
	return 0;
}