#include "bitset"
#include "iostream"
#include "vector"
#include "utility"
#include "cstdlib"
#include "fstream"
#include "list"
#include "cmath"
#include "sstream"
#include "queue"
#include "deque"
#include "numeric"
#include "stack"
#include "functional"
#include "set"
#include "cstring"
#include "iomanip"
#include "string"
#include "map"
#include "ctime"
#include "cstdio"
#include "cassert"
#include "cctype"
#include "algorithm"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )
int dp[16][16];

class ColorfulRoad {
public:
    int getMin(string road) {
        char pre[26];
        pre['R'-'A']='B';
        pre['G'-'A']='R';
        pre['B'-'A']='G';
        int out;
        Nclr(dp);
        dp[0][0]=0;
        for (int i=1; i<road.size(); i++) {
            for (int j=i-1; j>=0; j--) {
                if (pre[road[i]-'A']==road[j]) {
                    int minV = findMin(j);
                    if (minV!=-1) {
                        dp[j][i]=minV+(i-j)*(i-j);
                    }                
                }/* else if (road[i]!=road[j]) {
                    break;
                }*/
            }
        }
        return findMin(road.size()-1);
    }

    int findMin(int d) {
        int minV=1e9;
        for (int k=0; k<=d; k++) {
            if (dp[k][d]!=-1) {
                minV=min(minV, dp[k][d]);
            }
        }
        return minV==1e9?-1:minV;
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
            string road = "RGGGB";
            int expected_ = 8;

            clock_t start_           = clock();
            int received_ = ColorfulRoad().getMin(road);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string road = "RGBRGBRGB";
            int expected_ = 8;

            clock_t start_           = clock();
            int received_ = ColorfulRoad().getMin(road);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string road = "RBBGGGRR";
            int expected_ = -1;

            clock_t start_           = clock();
            int received_ = ColorfulRoad().getMin(road);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string road = "RBRRBGGGBBBBR";
            int expected_ = 50;

            clock_t start_           = clock();
            int received_ = ColorfulRoad().getMin(road);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string road = "RG";
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = ColorfulRoad().getMin(road);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            string road = "RBRGBGBGGBGRGGG";
            int expected_ = 52;

            clock_t start_           = clock();
            int received_ = ColorfulRoad().getMin(road);
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
    //Command line example: ColorfulRoad.exe -2 <ColorfulRoadIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        string road;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::getline(std::cin,road);
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = ColorfulRoad().getMin(road);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("ColorfulRoad.st", std::ios_base::app);
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
