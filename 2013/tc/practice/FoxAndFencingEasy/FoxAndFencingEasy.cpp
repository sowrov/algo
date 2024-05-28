#include "cctype"
#include "bitset"
#include "cstring"
#include "deque"
#include "vector"
#include "fstream"
#include "string"
#include "cassert"
#include "sstream"
#include "ctime"
#include "map"
#include "iostream"
#include "cstdio"
#include "list"
#include "set"
#include "functional"
#include "stack"
#include "algorithm"
#include "queue"
#include "utility"
#include "cstdlib"
#include "numeric"
#include "cmath"
#include "iomanip"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class FoxAndFencingEasy {
public:
    string WhoCanWin(int mov1, int mov2, int d) {
        string out;
        if (d<=mov1 || mov2*2 < mov1) {
            return "Ciel";
        } else if (mov1*2 < mov2) {
            return "Liss";
        }
        return "Draw";
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
            int mov1 = 1;
            int mov2 = 58;
            int d = 1;
            string expected_ = "Ciel";

            clock_t start_           = clock();
            string received_ = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int mov1 = 100;
            int mov2 = 100;
            int d = 100000000;
            string expected_ = "Draw";

            clock_t start_           = clock();
            string received_ = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int mov1 = 100;
            int mov2 = 150;
            int d = 100000000;
            string expected_ = "Draw";

            clock_t start_           = clock();
            string received_ = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int mov1 = 100;
            int mov2 = 250;
            int d = 100000000;
            string expected_ = "Liss";

            clock_t start_           = clock();
            string received_ = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
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
    //Command line example: FoxAndFencingEasy.exe -2 <FoxAndFencingEasyIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int mov1;
        int mov2;
        int d;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>mov1; std::cin.ignore(10, '\n');
            std::cin>>mov2; std::cin.ignore(10, '\n');
            std::cin>>d; std::cin.ignore(10, '\n');
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = FoxAndFencingEasy().WhoCanWin(mov1, mov2, d);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("FoxAndFencingEasy.st", std::ios_base::app);
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
