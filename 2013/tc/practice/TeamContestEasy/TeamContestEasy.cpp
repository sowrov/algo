#include "numeric"
#include "algorithm"
#include "functional"
#include "cstring"
#include "iomanip"
#include "sstream"
#include "bitset"
#include "cassert"
#include "iostream"
#include "ctime"
#include "string"
#include "list"
#include "deque"
#include "set"
#include "map"
#include "cmath"
#include "cctype"
#include "stack"
#include "queue"
#include "utility"
#include "vector"
#include "cstdlib"
#include "cstdio"
#include "iterator"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

bool comp(int a, int b) {
    return a>b;
}

class TeamContestEasy {
public:
    int worstRank(vector<int> strength) {
        int out;
        vector<int>oth;
        oth.assign(strength.begin()+3, strength.end());

        sort(oth.begin(), oth.end(), comp);

        bool flg[oth.size()];
        memset(flg, 0, sizeof(flg));
        int mst = strength[0]+strength[1]+strength[2] - min(strength[0], min(strength[1], strength[2]));
        int big=0;
        bool found;
        for (int i=0;i<oth.size(); i++ ) {
            if (!flg[i]) {
                flg[i]=1;
                found=0;
                for (int j=oth.size()-1; !found && j>=0; j--) {
                    if (!flg[j]) {
                        if (oth[i]+oth[j] > mst) {
                            flg[j] = 1;
                            for (int k=oth.size()-1; !found && k>=0; k--) {
                                if (!flg[k]) {
                                    flg[k] = 1;
                                    big++;
                                    found = 1;
                                }
                            }

                        }
                    }
                }
                if (!found) {
                    break;
                }
            }
        }

        return big+1;
    }
};

// <editor-fold defaultstate="collapsed" desc="Generated Code">
namespace otocoder {
    int run_test_case(int );
    bool run_full_test();
    // casenum<-1 to run full test set, casenum=-1 (default) to run all sample test cases,
    // casenum>-1 value to run specific sample case
    void run_test(int casenum = -1, bool quiet = false) {
        if (casenum < -1) {
            if (!run_full_test()) {
                cerr << "Illegal inputs in full test cases!" << endl;
            }
            return;
        }
        if (casenum > -1) {
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

    int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
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
            int strength[] = {5, 7, 3, 5, 7, 3, 5, 7, 3};
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = TeamContestEasy().worstRank(vector<int>(strength, strength + (sizeof strength / sizeof strength[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int strength[] = {5, 7, 3};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = TeamContestEasy().worstRank(vector<int>(strength, strength + (sizeof strength / sizeof strength[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int strength[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = TeamContestEasy().worstRank(vector<int>(strength, strength + (sizeof strength / sizeof strength[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int strength[] = {2, 2, 1, 1, 3, 1, 3, 2, 1, 3, 1, 2, 1, 2, 1};
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = TeamContestEasy().worstRank(vector<int>(strength, strength + (sizeof strength / sizeof strength[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int strength[] = {45, 72, 10, 42, 67, 51, 33, 21, 8, 51, 17, 72};
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = TeamContestEasy().worstRank(vector<int>(strength, strength + (sizeof strength / sizeof strength[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int strength[] = {570466, 958327, 816467, 17, 403, 953808, 734850, 5824, 917784, 921731, 161921, 1734, 823437, 3218, 81, 932681, 2704, 981643, 1232, 475, 873323, 6558, 45660, 1813, 4714, 224, 
32301, 28081, 6728, 17055, 561, 15146, 842613, 5559, 1860, 783, 989, 2811, 20664, 112531, 1933, 866794, 805528, 53821, 2465, 137385, 39, 2007};
            int expected_ = 6;

            clock_t start_           = clock();
            int received_ = TeamContestEasy().worstRank(vector<int>(strength, strength + (sizeof strength / sizeof strength[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 6: {
            int strength[] = {610297, 849870, 523999, 6557, 976530, 731458, 7404, 795100, 147040, 110947, 159692, 40785, 4949, 2903, 1688, 37278, 620703, 28156, 16823, 1159, 12132, 971379, 5916, 1159, 988589, 
12215, 133, 1490, 911360, 920059, 544070, 40249, 514852, 852, 745070, 1105, 715897, 714696, 589133, 698317, 5683, 631612, 16453, 101000, 764881, 101, 2053, 754661};
            int expected_ = 10;

            clock_t start_           = clock();
            int received_ = TeamContestEasy().worstRank(vector<int>(strength, strength + (sizeof strength / sizeof strength[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: TeamContestEasy.exe -2 <TeamContestEasy.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> strength;
        int strength_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            strength.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>strength_sin; std::cin.ignore(10, '\n');
                strength.push_back(strength_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = TeamContestEasy().worstRank(strength);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
        }
        return true;
    }

}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        otocoder::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            otocoder::run_test(atoi(argv[i]));
    }
}
// </editor-fold>
