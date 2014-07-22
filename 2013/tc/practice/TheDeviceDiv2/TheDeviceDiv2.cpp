#include "string"
#include "cstring"
#include "cmath"
#include "bitset"
#include "functional"
#include "queue"
#include "iomanip"
#include "set"
#include "stack"
#include "numeric"
#include "sstream"
#include "vector"
#include "deque"
#include "algorithm"
#include "cctype"
#include "iostream"
#include "cassert"
#include "map"
#include "list"
#include "fstream"
#include "cstdio"
#include "utility"
#include "cstdlib"
#include "ctime"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class TheDeviceDiv2 {
public:
    string identify(vector<string> plates) {
        string out;
		for (int i=0;  i<plates[0].size(); i++) {
			int one=0, zero=0;
			for (int j=0; j<plates.size(); j++) {
				if (plates[j][i]=='1') {
					one++;
				} else {
					zero++;
				}
			}
			if(!(one>1 && zero>0)) {
				return "NO";
			}
		}
        return "YES";
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
            string plates[] = {"010", "011", "000"};
            string expected_ = "NO";

            clock_t start_           = clock();
            string received_ = TheDeviceDiv2().identify(vector<string>(plates, plates + (sizeof plates / sizeof plates[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string plates[] = {"1", "0", "1", "0"};
            string expected_ = "YES";

            clock_t start_           = clock();
            string received_ = TheDeviceDiv2().identify(vector<string>(plates, plates + (sizeof plates / sizeof plates[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string plates[] = {"11111"};
            string expected_ = "NO";

            clock_t start_           = clock();
            string received_ = TheDeviceDiv2().identify(vector<string>(plates, plates + (sizeof plates / sizeof plates[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string plates[] = {"0110011", "0101001", "1111010", "1010010"};
            string expected_ = "NO";

            clock_t start_           = clock();
            string received_ = TheDeviceDiv2().identify(vector<string>(plates, plates + (sizeof plates / sizeof plates[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string plates[] = {"101001011", "011011010", "010110010", "111010100", "111111111"};
            string expected_ = "YES";

            clock_t start_           = clock();
            string received_ = TheDeviceDiv2().identify(vector<string>(plates, plates + (sizeof plates / sizeof plates[0])));
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
    //Command line example: TheDeviceDiv2.exe -2 <TheDeviceDiv2.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<string> plates;
        string plates_sin;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            plates.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,plates_sin );
                plates.push_back(plates_sin);
            }
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = TheDeviceDiv2().identify(plates);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("TheDeviceDiv2.st", std::ios_base::app);
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
