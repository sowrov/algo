#include "stack"
#include "set"
#include "cassert"
#include "queue"
#include "deque"
#include "cstring"
#include "vector"
#include "string"
#include "utility"
#include "sstream"
#include "map"
#include "functional"
#include "bitset"
#include "cctype"
#include "ctime"
#include "numeric"
#include "cmath"
#include "list"
#include "cstdlib"
#include "cstdio"
#include "iostream"
#include "algorithm"
#include "iomanip"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class TheNumberGame {
public:
    string determineOutcome(int A, int B) {
        string out="Manao loses";
        char str[10];
        string a,b,br;
        sprintf(str, "%d", A);
        a=str;
        sprintf(str, "%d", B);
        b=str;
        br=b;
        reverse(br.begin(), br.end());

        if (a.find(b)!=string::npos || a.find(br)!=string::npos) {
            return "Manao wins";
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

    int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
            cerr << "    Expected: \"" << expected << "\"" << endl;
            cerr << "    Received: \"" << received << "\"" << endl;
        }

        return verdict == "PASSED";
    }

    int run_test_case(int casenum) {
        switch (casenum) {
        case 0: {
            int A = 45;
            int B = 4;
            string expected_ = "Manao wins";

            clock_t start_           = clock();
            string received_ = TheNumberGame().determineOutcome(A, B);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int A = 45;
            int B = 5;
            string expected_ = "Manao wins";

            clock_t start_           = clock();
            string received_ = TheNumberGame().determineOutcome(A, B);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int A = 99;
            int B = 123;
            string expected_ = "Manao loses";

            clock_t start_           = clock();
            string received_ = TheNumberGame().determineOutcome(A, B);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int A = 2356236;
            int B = 5666;
            string expected_ = "Manao loses";

            clock_t start_           = clock();
            string received_ = TheNumberGame().determineOutcome(A, B);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: TheNumberGame.exe -2 <TheNumberGame.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int A;
        int B;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>A; std::cin.ignore(10, '\n');
            std::cin>>B; std::cin.ignore(10, '\n');
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = TheNumberGame().determineOutcome(A, B);
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
