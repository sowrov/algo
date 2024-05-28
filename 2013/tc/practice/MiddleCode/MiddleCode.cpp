#include "deque"
#include "sstream"
#include "cassert"
#include "fstream"
#include "cstring"
#include "cstdlib"
#include "cctype"
#include "set"
#include "iostream"
#include "vector"
#include "iomanip"
#include "algorithm"
#include "numeric"
#include "queue"
#include "bitset"
#include "string"
#include "stack"
#include "cstdio"
#include "utility"
#include "ctime"
#include "list"
#include "cmath"
#include "functional"
#include "map"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class MiddleCode {
public:
    string encode(string s) {
        string out="", a, b;
        int size = s.size();
        while(size>1) {
            if (size&1) {
                a=s.substr(0, size/2);
                b=s.substr(size/2+1);
                out += s[size/2];
            } else {
                int c, p;
                if(s[size/2-1]<s[size/2]) {
                    c=size/2-1;
                    p=size/2;
                } else {
                    c=size/2;
                    p=size/2+1;
                }
                a=s.substr(0, c);
                b=s.substr(p);
                out+=s[c];
            }
            s=a+b;
            size--;
        }
        out+=s;
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
            string s = "word";
            string expected_ = "ordw";

            clock_t start_           = clock();
            string received_ = MiddleCode().encode(s);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string s = "aaaaa";
            string expected_ = "aaaaa";

            clock_t start_           = clock();
            string received_ = MiddleCode().encode(s);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string s = "abacaba";
            string expected_ = "caabbaa";

            clock_t start_           = clock();
            string received_ = MiddleCode().encode(s);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string s = "shjegr";
            string expected_ = "ejghrs";

            clock_t start_           = clock();
            string received_ = MiddleCode().encode(s);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string s = "adafaaaadafawafwfasdaa";
            string expected_ = "afawadafawafaafsadadaa";

            clock_t start_           = clock();
            string received_ = MiddleCode().encode(s);
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
    //Command line example: MiddleCode.exe -2 <MiddleCodeIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        string s;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::getline(std::cin,s);
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = MiddleCode().encode(s);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("MiddleCode.st", std::ios_base::app);
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
