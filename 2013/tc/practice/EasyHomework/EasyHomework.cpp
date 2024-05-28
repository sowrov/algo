#include "cctype"
#include "algorithm"
#include "set"
#include "cmath"
#include "string"
#include "sstream"
#include "cstring"
#include "functional"
#include "utility"
#include "queue"
#include "bitset"
#include "ctime"
#include "cassert"
#include "stack"
#include "list"
#include "deque"
#include "iomanip"
#include "cstdlib"
#include "vector"
#include "cstdio"
#include "iostream"
#include "numeric"
#include "map"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class EasyHomework {
public:
    string determineSign(vector<int> A) {
        string out;
        bool s=true;
        for (int i=0; i<A.size(); i++) {
            if (A[i]==0) {
                return "ZERO";
            }
            if (A[i]<0) {
                s = !s;
            }
        }

        return s?"POSITIVE":"NEGATIVE";
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
            int A[] = {5, 7, 2};
            string expected_ = "POSITIVE";

            clock_t start_           = clock();
            string received_ = EasyHomework().determineSign(vector<int>(A, A + (sizeof A / sizeof A[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int A[] = {-5, 7, 2};
            string expected_ = "NEGATIVE";

            clock_t start_           = clock();
            string received_ = EasyHomework().determineSign(vector<int>(A, A + (sizeof A / sizeof A[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int A[] = {5, 7, 2, 0};
            string expected_ = "ZERO";

            clock_t start_           = clock();
            string received_ = EasyHomework().determineSign(vector<int>(A, A + (sizeof A / sizeof A[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int A[] = {3, -14, 159, -26};
            string expected_ = "POSITIVE";

            clock_t start_           = clock();
            string received_ = EasyHomework().determineSign(vector<int>(A, A + (sizeof A / sizeof A[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int A[] = {-1000000000};
            string expected_ = "NEGATIVE";

            clock_t start_           = clock();
            string received_ = EasyHomework().determineSign(vector<int>(A, A + (sizeof A / sizeof A[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int A[] = {123, -456, 789, -101112, 131415, 161718, 192021, 222324, 252627, 282930, 313233, 343536, 373839, 404142, 434445, 464748, 495051, 525354, 555657};
            string expected_ = "POSITIVE";

            clock_t start_           = clock();
            string received_ = EasyHomework().determineSign(vector<int>(A, A + (sizeof A / sizeof A[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: EasyHomework.exe -2 <EasyHomeworkIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> A;
        int A_sin;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            A.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>A_sin; std::cin.ignore(10, '\n');
                A.push_back(A_sin);
            }
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = EasyHomework().determineSign(A);
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
