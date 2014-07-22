#include "deque"
#include "vector"
#include "iostream"
#include "cstdlib"
#include "iomanip"
#include "list"
#include "cmath"
#include "sstream"
#include "cctype"
#include "cstdio"
#include "stack"
#include "map"
#include "cassert"
#include "algorithm"
#include "queue"
#include "bitset"
#include "cstring"
#include "string"
#include "fstream"
#include "functional"
#include "numeric"
#include "utility"
#include "ctime"
#include "set"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class BoxesOfBooks {
public:
    int boxes(vector<int> weights, int maxWeight) {
		if (weights.size()==0) return 0;
        int out=0, v=0;
		for (int i=0; i<weights.size(); i++) {
			v+= weights[i];
			if (v>maxWeight) {
				v=weights[i];
				out++;
			}
		}
        return out+1;
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
            int weights[] = {5, 5, 5, 5, 5, 5};
            int maxWeight = 10;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = BoxesOfBooks().boxes(vector<int>(weights, weights + (sizeof weights / sizeof weights[0])), maxWeight);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int weights[] = {51, 51, 51, 51, 51};
            int maxWeight = 100;
            int expected_ = 5;

            clock_t start_           = clock();
            int received_ = BoxesOfBooks().boxes(vector<int>(weights, weights + (sizeof weights / sizeof weights[0])), maxWeight);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int weights[] = {1, 1, 1, 7, 7, 7};
            int maxWeight = 8;
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = BoxesOfBooks().boxes(vector<int>(weights, weights + (sizeof weights / sizeof weights[0])), maxWeight);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int weights[] = {12, 1, 11, 2, 10, 3, 4, 5, 6, 6, 1};
            int maxWeight = 12;
            int expected_ = 6;

            clock_t start_           = clock();
            int received_ = BoxesOfBooks().boxes(vector<int>(weights, weights + (sizeof weights / sizeof weights[0])), maxWeight);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int weights[] = {};
            int maxWeight = 7;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = BoxesOfBooks().boxes(vector<int>(), maxWeight);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int weights[] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 
							 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 
							 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 
							 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 
							 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
            int maxWeight = 1000;
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = BoxesOfBooks().boxes(vector<int>(weights, weights + (sizeof weights / sizeof weights[0])), maxWeight);
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
    //Command line example: BoxesOfBooks.exe -2 <BoxesOfBooks.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> weights;
        int weights_sin;
        int maxWeight;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            weights.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>weights_sin; std::cin.ignore(10, '\n');
                weights.push_back(weights_sin);
            }
            std::cin>>maxWeight; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = BoxesOfBooks().boxes(weights, maxWeight);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("BoxesOfBooks.st", std::ios_base::app);
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
