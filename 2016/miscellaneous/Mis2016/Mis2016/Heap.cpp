#include <stdio.h>
int arr[20];

void heapfy(int i, int length) {
	bool conti = false;
	do {
		conti = false;
		int c1 = 2 * i + 1;
		int c2 = 2 * i + 2;
		if (c1 < length && c2 <length && arr[c1]<arr[c2]) {
			int x = arr[c2];
			arr[c2] = arr[c1];
			arr[c1] = x;
		}
		if (c1<length && arr[i] < arr[c1]) {
			int x = arr[i];
			arr[i] = arr[c1];
			arr[c1] = x;
			conti = true;
			i = c1;
		} else if (c2<length && arr[i] < arr[c2]) {
			int x = arr[i];
			arr[i] = arr[c2];
			arr[c2] = x;
			conti = true;
			i = c2;
		}
	} while (conti);
}

void makeMaxHeap(int n) {
	for (int i = 1; i < n; i++) {
		int p = (i - 1) / 2;
		int pi = i;
		while (arr[p] < arr[pi]) {
			int x = arr[p];
			arr[p] = arr[pi];
			arr[pi] = x;
			pi = p;
			p = (pi - 1) / 2;
		}
	}
}

void heapSort(int length) {
	for (int i = length-1; i > 0; i--) {
		int x = arr[i];
		arr[i] = arr[0];
		arr[0] = x;
		heapfy(0, i - 1);
	}
}
void show(int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {

	int n, v;
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &v);
			arr[i] = v;
		}
		makeMaxHeap(n);
		show(n);
		heapSort(n);
		show(n);
	}
	return 0;
}