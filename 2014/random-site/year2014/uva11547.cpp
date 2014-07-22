#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        int v = n * 567;
        v /= 9;
        v += 7492;
        v *= 235;
        v /= 47;
        v -= 498;
        v = (abs(v) / 10);
        printf("%d\n", v%10);
    }
}