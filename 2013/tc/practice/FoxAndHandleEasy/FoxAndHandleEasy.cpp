#include "cassert"
#include "cstring"
#include "cstdio"
#include "list"
#include "stack"
#include "deque"
#include "utility"
#include "iomanip"
#include "ctime"
#include "bitset"
#include "map"
#include "functional"
#include "sstream"
#include "numeric"
#include "queue"
#include "vector"
#include "cctype"
#include "iostream"
#include "cmath"
#include "cstdlib"
#include "algorithm"
#include "string"
#include "set"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class FoxAndHandleEasy {
public:
    string isPossible(string S, string T) {
        int p=0;
        while(true) {
            string out="";
            int pos = T.find(S, p);
            if (pos == string::npos) {
                return "No";
            }

            for (int i=0; i<pos; i++) {
                out += T[i];
            }
            for (int i=pos+S.size(); i<T.size(); i++) {
                out += T[i];
            }
            if (out==S) return "Yes";
            p++;
            //printf("%s\n",out.c_str());
        }
        //return out==S?"Yes":"No";
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
            string S = "Ciel";
            string T = "CieCiell";
            string expected_ = "Yes";

            clock_t start_           = clock();
            string received_ = FoxAndHandleEasy().isPossible(S, T);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string S = "Ciel";
            string T = "FoxCiel";
            string expected_ = "No";

            clock_t start_           = clock();
            string received_ = FoxAndHandleEasy().isPossible(S, T);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string S = "FoxCiel";
            string T = "FoxFoxCielCiel";
            string expected_ = "Yes";

            clock_t start_           = clock();
            string received_ = FoxAndHandleEasy().isPossible(S, T);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string S = "FoxCiel";
            string T = "FoxCielCielFox";
            string expected_ = "No";

            clock_t start_           = clock();
            string received_ = FoxAndHandleEasy().isPossible(S, T);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string S = "Ha";
            string T = "HaHaHaHa";
            string expected_ = "No";

            clock_t start_           = clock();
            string received_ = FoxAndHandleEasy().isPossible(S, T);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            string S = "TheHandleCanBeVeryLong";
            string T = "TheHandleCanBeVeryLong";
            string expected_ = "No";

            clock_t start_           = clock();
            string received_ = FoxAndHandleEasy().isPossible(S, T);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 6: {
            string S = "Long";
            string T = "LongLong";
            string expected_ = "Yes";

            clock_t start_           = clock();
            string received_ = FoxAndHandleEasy().isPossible(S, T);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: FoxAndHandleEasy.exe -2 <FoxAndHandleEasyIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        string S;
        string T;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::getline(std::cin,S);
            std::getline(std::cin,T);
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = FoxAndHandleEasy().isPossible(S, T);
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
