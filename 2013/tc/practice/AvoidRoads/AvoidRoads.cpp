#include "utility"
#include "iostream"
#include "cassert"
#include "ctime"
#include "string"
#include "deque"
#include "cctype"
#include "cmath"
#include "stack"
#include "iomanip"
#include "functional"
#include "cstdlib"
#include "algorithm"
#include "queue"
#include "numeric"
#include "cstring"
#include "set"
#include "map"
#include "vector"
#include "cstdio"
#include "sstream"
#include "bitset"
#include "list"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class AvoidRoads {
public:
    long long numWays(int width, int height, vector<string> bad) {
        long long matrix [width+1][height+1];
        unsigned long long v;
        unsigned long long maxV = 1;
        maxV <<= 63;
        maxV -= 1;
        bool flagUp[width+1][height+1];
        bool flagBack[width+1][height+1];
        Zclr(matrix);
        Zclr(flagUp);
        Zclr(flagBack);
        matrix[0][0] = 1;
        int x[2], y[2];
        for (int i=0; i<bad.size(); i++) {
            sscanf(bad[i].c_str(), "%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);

            if (x[0] == x[1]) { //up
                if (y[0]>y[1]) flagUp[x[0]][y[0]] = true;
                else flagUp[x[1]][y[1]] = true;
            }
            if (y[0] == y[1]) { //back
                if (x[0]>x[1]) flagBack[x[0]][y[0]] = true;
                else flagBack[x[1]][y[1]] = true;
            }

        }
        for (int i=0; i<=width; i++) {
            for (int j=0; j<=height; j++) {
                v = matrix[i][j];
                v += ( ((j-1) < 0 || flagUp[i][j] )? 0 : matrix[i][j-1]) 
                   + ( ((i-1) < 0 || flagBack[i][j]) ? 0: matrix[i-1][j] );
                v %= maxV;
                matrix[i][j] = v;
                //2printf("%d ", matrix[i][j]);
            }
            //printf("\n");
        }

        return matrix[width][height];
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

    int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
            int width = 6;
            int height = 6;
            string bad[] = {"0 0 0 1", "6 6 5 6"};
            long long expected_ = 252LL;

            clock_t start_           = clock();
            long long received_ = AvoidRoads().numWays(width, height, vector<string>(bad, bad + (sizeof bad / sizeof bad[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int width = 1;
            int height = 1;
            string bad[] = {};
            long long expected_ = 2LL;

            clock_t start_           = clock();
            long long received_ = AvoidRoads().numWays(width, height, vector<string>());
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int width = 35;
            int height = 31;
            string bad[] = {};
            long long expected_ = 6406484391866534976LL;

            clock_t start_           = clock();
            long long received_ = AvoidRoads().numWays(width, height, vector<string>());
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int width = 2;
            int height = 2;
            string bad[] = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
            long long expected_ = 0LL;

            clock_t start_           = clock();
            long long received_ = AvoidRoads().numWays(width, height, vector<string>(bad, bad + (sizeof bad / sizeof bad[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: AvoidRoads.exe -2 <AvoidRoadsIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int width;
        int height;
        vector<string> bad;
        string bad_sin;
        long long expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>width; std::cin.ignore(10, '\n');
            std::cin>>height; std::cin.ignore(10, '\n');
            bad.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,bad_sin );
                bad.push_back(bad_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            long long received_ = AvoidRoads().numWays(width, height, bad);
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
