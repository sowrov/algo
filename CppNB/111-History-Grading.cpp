#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int order[21];
int sorder[21];
int memo[21];

bool inOrder(int s, int t, int n){
    for (int i=0; i<n; i++) {
        if (order[i]==s) {
            return false;
        } else if (order[i]==t) {
            return true;
        }
    }
    return false;
}
int dp(int n) {
    memset(memo, 0, sizeof(memo));
    memo[0]=1;
    int maxv=1;
    for (int i=1; i<n; i++) {
        for (int j=i-1; j>=0; j--) {
            if (inOrder(sorder[i], sorder[j], n) && memo[j]>=memo[i]) {
                memo[i] = memo[j]+1;
                maxv = max(memo[i], maxv);
            }
        }
        if (memo[i]==0) {
            memo[i]=1;
        }
    }
    return maxv;
}
int main() {
    int n, v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        order[v-1]=i;
    }
    while (scanf("%d", &v) == 1) {
        sorder[v-1]=0;
        for (int i = 1; i < n; i++) {
            scanf("%d", &v);
            sorder[v-1]=i;
        }
        printf("%d\n", dp(n));
    }
    return 0;
}