#include "map"
#include "cstdlib"
#include "cmath"
#include "stack"
#include "algorithm"
#include "iomanip"
#include "sstream"
#include "fstream"
#include "utility"
#include "iostream"
#include "cstdio"
#include "cstring"
#include "cassert"
#include "bitset"
#include "queue"
#include "numeric"
#include "functional"
#include "cctype"
#include "list"
#include "deque"
#include "string"
#include "set"
#include "vector"
#include "ctime"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )
map<string, bool>db;
string G;
class LittleElephantAndString {
public:
    int getNumber(string A, string B) {
        int out=0;
        string at, bt;
        at=A; bt=B;
        G=B;
        sort(at.begin(), at.end());
        sort(bt.begin(), bt.end());
        if (at.compare(bt)!=0) {
            return -1;
        }

        return memo(A);
    }

    int memo(string str) {
        if (str.compare(G)==0) {
            return 0;
        }
        if (db[str]==true) {
            return -1;
        }
        db[str]=true;
        string tmp;
        for (int i=1; i<str.size(); i++) {
            tmp=str[i];
            for (int j=0; j<i; j++) {
                tmp+=str[j];
            }
            for (int j=i+1; j<str.size(); j++) {
                tmp +=str[j];
            }
            int v=memo(tmp);
            if (v!=-1) {
                return v+1;
            }
        }
        return -1;
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
            string A = "ABC";
            string B = "CBA";
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = LittleElephantAndString().getNumber(A, B);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string A = "A";
            string B = "B";
            int expected_ = -1;

            clock_t start_           = clock();
            int received_ = LittleElephantAndString().getNumber(A, B);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string A = "AAABBB";
            string B = "BBBAAA";
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = LittleElephantAndString().getNumber(A, B);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            string B = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
            int expected_ = 25;

            clock_t start_           = clock();
            int received_ = LittleElephantAndString().getNumber(A, B);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string A = "A";
            string B = "A";
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = LittleElephantAndString().getNumber(A, B);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            string A = "DCABA";
            string B = "DACBA";
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = LittleElephantAndString().getNumber(A, B);
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
    //Command line example: LittleElephantAndString.exe -2 <LittleElephantAndStringIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        string A;
        string B;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::getline(std::cin,A);
            std::getline(std::cin,B);
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = LittleElephantAndString().getNumber(A, B);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("LittleElephantAndString.st", std::ios_base::app);
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
