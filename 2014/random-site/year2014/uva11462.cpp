#include <stdio.h>
#include <memory.h>

int main() {
    int arr[100];
    int n, a;

    while(scanf("%d", &n) && n) {
        memset(arr, 0, sizeof(arr));
        bool flg=0;
        for (int i=0; i<n; i++) {
            scanf("%d", &a);
            arr[a]++;
        }
        for (int i=1; i<100; i++) {
            for(int j=0; j<arr[i]; j++) {
                if (flg) printf(" ");
                printf("%d", i);
                flg=1;
            }
        }
        printf("\n");
    }
    return 0;
}
