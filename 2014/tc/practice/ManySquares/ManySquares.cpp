#include "cstring"
#include "string"
#include "cmath"
#include "utility"
#include "deque"
#include "cassert"
#include "stack"
#include "cstdlib"
#include "iostream"
#include "queue"
#include "numeric"
#include "iomanip"
#include "cstdio"
#include "cctype"
#include "vector"
#include "bitset"
#include "list"
#include "map"
#include "ctime"
#include "fstream"
#include "set"
#include "algorithm"
#include "functional"
#include "sstream"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class ManySquares {
    int stick[1001];
public:
    int howManySquares(vector<int> sticks) {
        int out=0;
        Zclr(stick);
        for (int i=0; i<sticks.size(); i++) {
            stick[sticks[i]]++;
        }

        for (int i=1; i<=1000; i++) {
            out += stick[i]/4;
        }
        return out;
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
            int sticks[] = {1, 1, 2, 2, 1, 1, 2};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = ManySquares().howManySquares(vector<int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int sticks[] = {3, 1, 4, 4, 4, 10, 10, 10, 10};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = ManySquares().howManySquares(vector<int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int sticks[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 3, 3};
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = ManySquares().howManySquares(vector<int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int sticks[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = ManySquares().howManySquares(vector<int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int sticks[] = {1, 1, 1, 2, 1, 1, 1, 3, 1, 1, 1};
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = ManySquares().howManySquares(vector<int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int sticks[] = {2, 2, 4, 4, 8, 8};
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = ManySquares().howManySquares(vector<int>(sticks, sticks + (sizeof sticks / sizeof sticks[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    const std::string currentDateTime() {
        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
        return buf;
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: ManySquares.exe -2 <ManySquares.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> sticks;
        int sticks_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            sticks.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>sticks_sin; std::cin.ignore(10, '\n');
                sticks.push_back(sticks_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = ManySquares().howManySquares(sticks);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("ManySquares.st", std::ios_base::app);
            ofs<<currentDateTime()<<std::endl;
            ofs.close();
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
