#include "functional"
#include "cctype"
#include "cmath"
#include "sstream"
#include "cassert"
#include "vector"
#include "algorithm"
#include "cstring"
#include "ctime"
#include "iomanip"
#include "stack"
#include "numeric"
#include "iostream"
#include "queue"
#include "cstdlib"
#include "utility"
#include "list"
#include "bitset"
#include "string"
#include "cstdio"
#include "map"
#include "deque"
#include "set"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class WindowWasher {
public:
    int dp[51][1001];
    int recur(int p, int w, int h, vector<int>&wt) {
        if (dp[p][w] != -1) return dp[p][w];
        if (p+1==wt.size()) {
            return w*h*wt[p];
        }
        int minV = M31, v;
        for (int pa = 0; pa<=w; pa++) {
            v = max (pa*h*wt[p], recur(p+1, w-pa, h, wt));
            if (v<minV) minV = v;
        }
        dp[p][w] = minV;
        return minV;
    }
    int fastest(int width, int height, vector<int> washTimes) {
        Nclr(dp);
        return recur(0, width, height, washTimes);
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
            int width = 10;
            int height = 10;
            int washTimes[] = {60};
            int expected_ = 6000;

            clock_t start_           = clock();
            int received_ = WindowWasher().fastest(width, height, vector<int>(washTimes, washTimes + (sizeof washTimes / sizeof washTimes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int width = 10;
            int height = 10;
            int washTimes[] = {60, 60};
            int expected_ = 3000;

            clock_t start_           = clock();
            int received_ = WindowWasher().fastest(width, height, vector<int>(washTimes, washTimes + (sizeof washTimes / sizeof washTimes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int width = 10;
            int height = 10;
            int washTimes[] = {60, 30};
            int expected_ = 2100;

            clock_t start_           = clock();
            int received_ = WindowWasher().fastest(width, height, vector<int>(washTimes, washTimes + (sizeof washTimes / sizeof washTimes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int width = 1000;
            int height = 1000;
            int washTimes[] = {1000};
            int expected_ = 1000000000;

            clock_t start_           = clock();
            int received_ = WindowWasher().fastest(width, height, vector<int>(washTimes, washTimes + (sizeof washTimes / sizeof washTimes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int width = 421;
            int height = 936;
            int washTimes[] = {111, 56, 931, 22, 445, 90, 14, 222};
            int expected_ = 2450448;

            clock_t start_           = clock();
            int received_ = WindowWasher().fastest(width, height, vector<int>(washTimes, washTimes + (sizeof washTimes / sizeof washTimes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int width = 25;
            int height = 25;
            int washTimes[] = {1, 625};
            int expected_ = 625;

            clock_t start_           = clock();
            int received_ = WindowWasher().fastest(width, height, vector<int>(washTimes, washTimes + (sizeof washTimes / sizeof washTimes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 6: {
            int width = 12;
            int height = 754;
            int washTimes[] = {728, 734, 147, 464, 6, 703, 254};
            int expected_ = 54288;

            clock_t start_           = clock();
            int received_ = WindowWasher().fastest(width, height, vector<int>(washTimes, washTimes + (sizeof washTimes / sizeof washTimes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: WindowWasher.exe -2 <WindowWasherIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int width;
        int height;
        vector<int> washTimes;
        int washTimes_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>width; std::cin.ignore(10, '\n');
            std::cin>>height; std::cin.ignore(10, '\n');
            washTimes.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>washTimes_sin; std::cin.ignore(10, '\n');
                washTimes.push_back(washTimes_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = WindowWasher().fastest(width, height, washTimes);
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
