#pragma warning ( disable : 4786)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <bitset>
#include <deque>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 2147483647
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class SpaceWarDiv1 {
public:
    long long minimalFatigue( vector <int> gs, vector <int> es, vector<long long> ec ) {
        for (int i=0; i<es.size(); i++) {
            int c=0;
            for (int j=0; j<gs.size(); j++) {
                if (es[i]>gs[j]) {
                    c++;
                }
            }
            if (c==gs.size()) {
                return -1;
            }
        }
        vector<long long> F(gs.size(), 0);
        vector<long long> E(gs.size(), 0);
        vector<bool>flg(es.size(), 0);
        sort (gs.begin(), gs.end());
        for (int i=0; i<gs.size(); i++) {
            for (int j=0; j<es.size(); j++) {
                if (!flg[j] && gs[i]>=es[j]) {
                    F[i] += ec[j];
                    flg[j]=true;
                }
            }
        }
        long long total=0;
        for (int i=0; i<es.size();i++) {
            total += ec[i];
        }
        long long avg = total/gs.size();
        for (int i=0; i<gs.size()-1; i++) {
            if (F[i]>avg) {
                E[i] = F[i]-avg;
                F[i+1] += E[i];
                F[i]=avg;
            }
        }
        for (int i=gs.size()-1; i>0; i--) {
            if (F[i]>avg) {
                long long v = F[i]-avg;
                if (v>=E[i-1]) {
                    F[i] -= E[i-1];
                    F[i-1] += E[i-1];
                }else {
                    F[i] -= v;
                    F[i-1] += v;
                }
            }
        }

        long long mxF=0;

        for (int i=0; i<gs.size(); i++) {
            if (F[i]>mxF) {
                mxF = F[i];
            }
        }

        return mxF;
    }
};

// <editor-fold defaultstate="collapsed" desc="Generated Code">
namespace moj_harness {
    int run_test_case(int);
    void run_test(int casenum = -1, bool quiet = false) {
        if (casenum != -1) {
            if (run_test_case(casenum) == -1 && !quiet) {
                cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
            }
            return;
        }
        
        int correct = 0, total = 0;
        for (int i=0;; ++i) {
            int x = run_test_case(i);
            if (x == -1) {
                if (i >= 100) break;
                continue;
            }
            correct += x;
            ++total;
        }
        
        if (total == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < total) {
            cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
        } else {
            cerr << "All " << total << " tests passed!" << endl;
        }
    }
    
    int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
        cerr << "Example " << casenum << "... "; 
        
        string verdict;
        vector<string> info;
        char buf[100];
        
        if (elapsed > CLOCKS_PER_SEC / 200) {
            sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
            info.push_back(buf);
        }
        
        if (expected == received) {
            verdict = "PASSED";
        } else {
            verdict = "FAILED";
        }
        
        cerr << verdict;
        if (!info.empty()) {
            cerr << " (";
            for (int i=0; i<(int)info.size(); ++i) {
                if (i > 0) cerr << ", ";
                cerr << info[i];
            }
            cerr << ")";
        }
        cerr << endl;
        
        if (verdict == "FAILED") {
            cerr << "    Expected: " << expected << endl; 
            cerr << "    Received: " << received << endl; 
        }
        
        return verdict == "PASSED";
    }

    int run_test_case(int casenum) {
        switch (casenum) {
        case 0: {
            int magicalGirlStrength[] = {2, 3, 5};
            int enemyStrength[]       = {1, 3, 4};
            long long enemyCount[]    = {2, 9, 4};
            long long expected__      = 7;

            clock_t start__           = clock();
            long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 1: {
            int magicalGirlStrength[] = {2, 3, 5};
            int enemyStrength[]       = {1, 1, 2};
            long long enemyCount[]    = {2, 9, 4};
            long long expected__      = 5;

            clock_t start__           = clock();
            long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 2: {
            int magicalGirlStrength[] = {14, 6, 22};
            int enemyStrength[]       = {8, 33};
            long long enemyCount[]    = {9, 1};
            long long expected__      = -1;

            clock_t start__           = clock();
            long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 3: {
            int magicalGirlStrength[] = {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417};
            int enemyStrength[]       = {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307};
            long long enemyCount[]    = {20626770196420LL, 45538527263992LL, 52807114957507LL, 17931716090785LL, 65032910980630LL, 88711853198687LL, 26353250637092LL, 61272534748707LL, 89294362230771LL, 52058590967576LL, 60568594469453LL, 23772707032338LL, 43019142889727LL, 39566072849912LL, 78870845257173LL, 68135668032761LL, 36844201017584LL, 10133804676521LL, 6275847412927LL, 37492167783296LL};
            long long expected__      = 75030497287405LL;

            clock_t start__           = clock();
            long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }

        // custom cases

        /*
        case 4: {
            int magicalGirlStrength[] = ;
            int enemyStrength[]       = ;
            long long enemyCount[]    = ;
            long long expected__      = ;

            clock_t start__           = clock();
            long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        //*/
        /*
        case 5: {
            int magicalGirlStrength[] = ;
            int enemyStrength[]       = ;
            long long enemyCount[]    = ;
            long long expected__      = ;

            clock_t start__           = clock();
            long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        //*/
        /*
        case 6: {
            int magicalGirlStrength[] = ;
            int enemyStrength[]       = ;
            long long enemyCount[]    = ;
            long long expected__      = ;

            clock_t start__           = clock();
            long long received__      = SpaceWarDiv1().minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength + (sizeof magicalGirlStrength / sizeof magicalGirlStrength[0])), vector <int>(enemyStrength, enemyStrength + (sizeof enemyStrength / sizeof enemyStrength[0])), vector<long long>(enemyCount, enemyCount + (sizeof enemyCount / sizeof enemyCount[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        //*/
        default:
            return -1;
        }
    }
}


int main(int argc, char *argv[]) {
    if (argc == 1) {
        moj_harness::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            moj_harness::run_test(atoi(argv[i]));
    }
}
// </editor-fold>
