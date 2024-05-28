#include "ctime"
#include "list"
#include "vector"
#include "string"
#include "iostream"
#include "sstream"
#include "queue"
#include "utility"
#include "functional"
#include "deque"
#include "numeric"
#include "stack"
#include "set"
#include "cstdlib"
#include "cstdio"
#include "cmath"
#include "map"
#include "bitset"
#include "cassert"
#include "cctype"
#include "cstring"
#include "iomanip"
#include "fstream"
#include "algorithm"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class FibonacciDiv2 {
public:
    int find(int N) {
        int out=0;
        int a=0, b=1;
        int v;
        if (N==0 || N==1) return 0;

        for (int i=2;;i++) {
            v=a+b;
            a=b;
            b=v;
            if (v>N) {
                break;
            }
        }

        return min(N-a, b-N);
    }
};
// <editor-fold defaultstate="collapsed" desc="Generated Code">
namespace otocoder {
    int run_test_case(int );
    bool run_full_test();
    // _currentCaseNo<-1 to run full test set, _currentCaseNo=-1 (default) to run all sample test cases,
    // _currentCaseNo>-1 value to run specific sample case
    void run_test(int _currentCaseNo = -1, bool quiet = false) {
        if (_currentCaseNo < -1) {
            if (!run_full_test()) {
                cerr << "Illegal inputs in full test cases!" << endl;
            }
            return;
        }
        if (_currentCaseNo > -1) {
            if (run_test_case(_currentCaseNo) == -1 && !quiet) {
                cerr << "Illegal input! Test case " << _currentCaseNo << " does not exist." << endl;
            }
            return;
        }

        int _correctResCount = 0, total = 0;
        for (int i=0;; ++i) {
            int x = run_test_case(i);
            if (x == -1) {
                if (i >= 100) break;
                continue;
            }
            _correctResCount += x;
            ++total;
        }

        if (total == 0) {
            cerr << "No test cases run." << endl;
        } else if (_correctResCount < total) {
            cerr << "Some cases FAILED (passed " << _correctResCount << " of " << total << ")." << endl;
        } else {
            cerr << "All " << total << " tests passed!" << endl;
        }
    }

    int verify_case(int _currentCaseNo, const int &expected, const int &received, clock_t elapsed) { 
        cerr << "Example " << _currentCaseNo << "... "; 

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

    int run_test_case(int _currentCaseNo) {
        switch (_currentCaseNo) {
        case 0: {
            int N = 1;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = FibonacciDiv2().find(N);
            return verify_case(_currentCaseNo, expected_, received_, clock()-start_);
        }
        case 1: {
            int N = 13;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = FibonacciDiv2().find(N);
            return verify_case(_currentCaseNo, expected_, received_, clock()-start_);
        }
        case 2: {
            int N = 15;
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = FibonacciDiv2().find(N);
            return verify_case(_currentCaseNo, expected_, received_, clock()-start_);
        }
        case 3: {
            int N = 19;
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = FibonacciDiv2().find(N);
            return verify_case(_currentCaseNo, expected_, received_, clock()-start_);
        }
        case 4: {
            int N = 1000000;
            int expected_ = 167960;

            clock_t start_           = clock();
            int received_ = FibonacciDiv2().find(N);
            return verify_case(_currentCaseNo, expected_, received_, clock()-start_);
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
    //Command line example: FibonacciDiv2.exe -2 <FibonacciDiv2IO.txt
    bool run_full_test() {
        int _totalTestCases, _totalArrayItems, _currentCaseNo, _correctResCount=0;
        int N;
        int expected_;

        std::cin>>_totalTestCases; std::cin.ignore(10, '\n');
        for (int i=0; i<_totalTestCases; i++) {
            std::cin>>_currentCaseNo; std::cin.ignore(10, '\n');
            std::cin>>N; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = FibonacciDiv2().find(N);
            _correctResCount += verify_case(_currentCaseNo, expected_, received_, clock()-start_);
        }//end of _totalTestCases for loop

        if (_totalTestCases == 0) {
            cerr << "No test cases run." << endl;
        } else if (_correctResCount < _totalTestCases) {
            cerr << "Some cases FAILED (passed " << _correctResCount << " of " << _totalTestCases << ")." << endl;
        } else {
            cerr << "All " << _totalTestCases << " tests passed!" << endl;
            std::ofstream ofs("FibonacciDiv2.st", std::ios_base::app);
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
