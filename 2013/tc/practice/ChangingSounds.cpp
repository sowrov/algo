#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;

class ChangingSounds {
public:
    int dp[1001][51];
    vector <int> cInter;
    int maxL;
    int maxFinal(vector<int> changeIntervals, int beginLevel, int maxLevel) {
        memset(dp, -1, sizeof(dp));
        cInter = changeIntervals;
        printf("%d\n",cInter.size());
        maxL = maxLevel;
        return memo(beginLevel,0);
    }

    int memo(int level, int ind) {
        if (level > maxL || level<0 ) return -1;
        if (ind==cInter.size()) return level;

        if (dp[level][ind]!=-1) return dp[level][ind];
        
        int v = max (memo(level+cInter[ind], ind+1), memo(level-cInter[ind], ind+1));
        dp[level][ind] = v;
        return v;
    }
};

int main() {
    ChangingSounds cs;
    vector <int> lev;
    lev.push_back(5);
    lev.push_back(3);
    lev.push_back(7);
    printf("out: %d\n",cs.maxFinal (lev, 5, 10));
    return 0;
}

