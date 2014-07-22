#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;
int memo[100001];
class NewCoins {
public:
    int minCoins(vector <int> price) {
        sort(price.begin(), price.end());
        int x, ones=0, minVal=1<<29, val, cval,sqrv;
        vector <int>xs, primes;
        while(price[ones]==1) ones++;
        memset(memo, -1, sizeof(memo));
        int maxP = price[price.size()-1];
        sqrv=sqrt(maxP);
        for (int i=2; i<=sqrv; i++) {
            if (memo[i]==-1) {
                primes.push_back(i);
                int k=2;
                for (int j=i*k; j<=maxP; j=i*k) {
                    memo[j]=1;
                    k++;
                }
            }
        }
        for (int i=sqrv; i<=maxP; i++) {
            if (memo[i]==-1) primes.push_back(i);
        }
        //for (int i=ones; i<price.size(); i++) {
        for (int i=0; i<primes.size(); i++) {
            //x=price[i]; 
            x=primes[i];
            val = 0;
            xs.clear(); xs.push_back(x);
            memset(memo, -1, sizeof(memo));
            memo[x] = 1;
            printf("--Starting from %d--\n",x);
            for (int j=ones; j<price.size(); j++) {
                
            } 
            if (val < minVal) {
                minVal = val;
            }
        }
        return (minVal!=1<<29?minVal:0)+ones;
    }
};
int main () {
    vector<int> vec;
    int n, v;
    while (scanf("%d", &n)==1) {
        vec.clear();
        while (n-->0) {
            scanf("%d", &v);
            vec.push_back(v);
        }
        NewCoins newCoins;
        printf("%d\n",newCoins.minCoins(vec));
    }
    return 0;
}

