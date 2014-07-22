#include "utility"
#include "set"
#include "cassert"
#include "iomanip"
#include "functional"
#include "cmath"
#include "iostream"
#include "sstream"
#include "ctime"
#include "algorithm"
#include "cstring"
#include "vector"
#include "bitset"
#include "list"
#include "map"
#include "cstdlib"
#include "stack"
#include "numeric"
#include "deque"
#include "queue"
#include "string"
#include "cstdio"
#include "cctype"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
int gcd(int a, int b) {
    return b==0?a:gcd(b, a%b);
}
class EllysCoprimesDiv2 {
public:
    int getCount(vector<int> numbers) {
        int out=0;
        sort(numbers.begin(), numbers.end());
        int g, g1, f;
        for (int i=1; i<numbers.size(); i++) {
            g=gcd(numbers[i], numbers[i-1]);
            if (g!=1) {
                f=0;
                for (int j=numbers[i-1]+1; j<numbers[i]; j++ ) {
                    g=gcd(j, numbers[i-1]);
                    g1 = gcd(numbers[i], j);
                    if (g==1 && g1==1) {
                        //cout<<j<<endl;
                        f=1;
                        break;
                    }
                }

                if (f==1) {
                    out++;
                } else {
                    out+=2;
                }
            }
            //cout<<numbers[i-1]<<", "<<numbers[i]<<": "<<g<<endl;
        }
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
            int numbers[] = {2200, 42, 2184, 17};
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = EllysCoprimesDiv2().getCount(vector<int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int numbers[] = {13, 1, 6, 20, 33};
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = EllysCoprimesDiv2().getCount(vector<int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int numbers[] = {7, 42};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = EllysCoprimesDiv2().getCount(vector<int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int numbers[] = {55780, 44918, 55653, 4762, 41536, 40083, 79260, 7374, 24124, 91858, 7856, 
 12999, 64025, 12706, 19770, 71495, 32817, 79309, 53779, 8421, 97984, 34586, 
 893, 64549, 77792, 12143, 52732, 94416, 54207, 51811, 80845, 67079, 14829, 
 25350, 22976, 23932, 62273, 58871, 82358, 13283, 33667, 64263, 1337, 42666};
            int expected_ = 15;

            clock_t start_           = clock();
            int received_ = EllysCoprimesDiv2().getCount(vector<int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: EllysCoprimesDiv2.exe -2 <EllysCoprimesDiv2.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> numbers;
        int numbers_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            numbers.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>numbers_sin; std::cin.ignore(10, '\n');
                numbers.push_back(numbers_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = EllysCoprimesDiv2().getCount(numbers);
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
