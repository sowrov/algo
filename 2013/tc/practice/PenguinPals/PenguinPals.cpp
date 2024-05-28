#include "utility"
#include "sstream"
#include "cassert"
#include "algorithm"
#include "bitset"
#include "cstdlib"
#include "iomanip"
#include "iostream"
#include "cmath"
#include "cstring"
#include "queue"
#include "cctype"
#include "numeric"
#include "deque"
#include "list"
#include "string"
#include "set"
#include "cstdio"
#include "vector"
#include "functional"
#include "stack"
#include "ctime"
#include "map"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class PenguinPals {
public:
    int dp[51][51];
    string col;
    int findM(int s, int e) {
        if (s>=e) return 0;
        if (dp[s][e]!=-1) return dp[s][e];

        int out=-1, maxo=-1;
        for (int i=s+1; i<=e; i++) {
            if (col[i]==col[s] ) {
                out=0;
                if(i==s+1) {
                    out = 1+findM(s+2, e);
                } else {
                    out=1;
                    out += findM(s+1, i-1);
                    out += findM(i+1, e);
                }
                maxo=max(out, maxo);
            }
        }
        if (maxo==-1) {
            maxo = (e-s)/2;
        }
        dp[s][e] = maxo;
        return maxo;
    }
    int findMaximumMatching(string colors) {
        col=colors;
        Nclr(dp);
        return findM(0, col.size()-1);
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
            string colors = "RRBRBRBB";
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = PenguinPals().findMaximumMatching(colors);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string colors = "RRRR";
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = PenguinPals().findMaximumMatching(colors);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string colors = "BBBBB";
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = PenguinPals().findMaximumMatching(colors);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string colors = "RBRBRBRBR";
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = PenguinPals().findMaximumMatching(colors);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string colors = "RRRBRBRBRBRB";
            int expected_ = 5;

            clock_t start_           = clock();
            int received_ = PenguinPals().findMaximumMatching(colors);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            string colors = "R";
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = PenguinPals().findMaximumMatching(colors);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 6: {
            string colors = "RBRRBBRB";
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = PenguinPals().findMaximumMatching(colors);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 7: {
            string colors = "RBRBBRBRB";
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = PenguinPals().findMaximumMatching(colors);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: PenguinPals.exe -2 <PenguinPalsIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        string colors;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::getline(std::cin,colors);
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = PenguinPals().findMaximumMatching(colors);
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
