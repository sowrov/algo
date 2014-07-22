#include "algorithm"
#include "set"
#include "fstream"
#include "map"
#include "cctype"
#include "sstream"
#include "functional"
#include "ctime"
#include "iomanip"
#include "cstdio"
#include "string"
#include "deque"
#include "queue"
#include "list"
#include "cassert"
#include "stack"
#include "cstdlib"
#include "cstring"
#include "vector"
#include "numeric"
#include "utility"
#include "cmath"
#include "bitset"
#include "iostream"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class WolfDelaymaster {
public:
    string check(string str) {
        string out;
        int st=0;
        bool valid = 1;
        while(st< str.size()) {
            valid &= isValid(str, st);
        }
        if (valid) {
            return "VALID";
        }
        return "INVALID";
    }
    bool isValid(string str, int& st) {
        int w = count(str, 'w', st);
        int o = count(str, 'o', st);
        int l = count(str, 'l', st);
        int f = count(str, 'f', st);

        return w==o && o==l && l==f;
    }

    int count(string& str, char ch, int& st) {
        int c=0;
        while(str[st]==ch && st <str.size()) {
            c++;
            st++;
        }
        return c;
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
            string str = "wolf";
            string expected_ = "VALID";

            clock_t start_           = clock();
            string received_ = WolfDelaymaster().check(str);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string str = "wwolfolf";
            string expected_ = "INVALID";

            clock_t start_           = clock();
            string received_ = WolfDelaymaster().check(str);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string str = "wolfwwoollffwwwooolllfffwwwwoooollllffff";
            string expected_ = "VALID";

            clock_t start_           = clock();
            string received_ = WolfDelaymaster().check(str);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string str = "flowolf";
            string expected_ = "INVALID";

            clock_t start_           = clock();
            string received_ = WolfDelaymaster().check(str);
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
    //Command line example: WolfDelaymaster.exe -2 <WolfDelaymaster.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        string str;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::getline(std::cin,str);
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = WolfDelaymaster().check(str);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("WolfDelaymaster.st", std::ios_base::app);
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
