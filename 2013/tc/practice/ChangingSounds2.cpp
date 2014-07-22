#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;

class ChangingSounds {
public:
    bool possible[1001], poss_back[1001];

    int maxFinal(vector<int> changeIntervals, int beginLevel, int maxLevel) {
        memset(possible, 0, sizeof(possible));
        possible[beginLevel] = true;
        for (int i=0; i<changeIntervals.size(); i++) {
            memset(poss_back, 0, sizeof(poss_back));
            for (int j=0; j<=maxLevel; j++) {
                if (possible[j]) {
                    if (j+changeIntervals[i]<=maxLevel) poss_back[j+changeIntervals[i]]=1;
                    if (j-changeIntervals[i]>=0) poss_back[j-changeIntervals[i]]=1;
                }
            }
            memcpy(possible, poss_back, sizeof(poss_back));
        }
        int r=-1;
        for (int i=maxLevel; i>=0; i--) {
            if (possible[i]) {
                r = i; break;
            }
        }
        return r;
    }
};

