#include "numeric"
#include "cassert"
#include "deque"
#include "utility"
#include "list"
#include "cstdio"
#include "stack"
#include "set"
#include "iostream"
#include "cmath"
#include "bitset"
#include "cctype"
#include "cstdlib"
#include "queue"
#include "vector"
#include "map"
#include "iomanip"
#include "string"
#include "cstring"
#include "ctime"
#include "sstream"
#include "functional"
#include "algorithm"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class RobotHerbDiv2 {
public:
    int getdist(int T, vector<int> a) {
        int out;
        int dir[4][2]={{0,1}, {1,0}, {0,-1}, {-1, 0}};
        int x, y;
        int dx, dy;
        x=y=0;
        int d=0;

        for (int i=0; i<T; i++) {
            for (int j=0; j<a.size(); j++) {
                x+=dir[d][0]*a[j];
                y+=dir[d][1]*a[j];
                //cout<<x<<" "<<y<<endl;
                d = (d+a[j])%4;
            }
        }
        return abs(x)+abs(y);
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
            int T = 1;
            int a[] = {1, 2, 3};
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = RobotHerbDiv2().getdist(T, vector<int>(a, a + (sizeof a / sizeof a[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int T = 100;
            int a[] = {1};
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = RobotHerbDiv2().getdist(T, vector<int>(a, a + (sizeof a / sizeof a[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int T = 5;
            int a[] = {1, 1, 2};
            int expected_ = 10;

            clock_t start_           = clock();
            int received_ = RobotHerbDiv2().getdist(T, vector<int>(a, a + (sizeof a / sizeof a[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int T = 100;
            int a[] = {400000};
            int expected_ = 40000000;

            clock_t start_           = clock();
            int received_ = RobotHerbDiv2().getdist(T, vector<int>(a, a + (sizeof a / sizeof a[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: RobotHerbDiv2.exe -2 <RobotHerbDiv2.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int T;
        vector<int> a;
        int a_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>T; std::cin.ignore(10, '\n');
            a.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>a_sin; std::cin.ignore(10, '\n');
                a.push_back(a_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = RobotHerbDiv2().getdist(T, a);
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
