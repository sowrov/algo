#include "set"
#include "cstring"
#include "cassert"
#include "bitset"
#include "algorithm"
#include "cstdlib"
#include "functional"
#include "vector"
#include "ctime"
#include "cctype"
#include "utility"
#include "stack"
#include "queue"
#include "string"
#include "deque"
#include "cstdio"
#include "numeric"
#include "sstream"
#include "map"
#include "list"
#include "cmath"
#include "iomanip"
#include "iostream"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class CucumberMarket {
public:
    string check(vector<int> price, int budget, int k) {
        string out;
        sort(price.begin(), price.end());
        do{
            int v=0;
            for (int i=0; i<k; i++) {
                v+=price[i];
            }
            if (v>budget) return "NO";
        } while(next_permutation(price.begin(), price.end()));
        
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
            int price[] = {1000, 1, 10, 100};
            int budget = 1110;
            int k = 3;
            string expected_ = "YES";

            clock_t start_           = clock();
            string received_ = CucumberMarket().check(vector<int>(price, price + (sizeof price / sizeof price[0])), budget, k);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int price[] = {1000, 1, 10, 100};
            int budget = 1109;
            int k = 3;
            string expected_ = "NO";

            clock_t start_           = clock();
            string received_ = CucumberMarket().check(vector<int>(price, price + (sizeof price / sizeof price[0])), budget, k);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int price[] = {33, 4};
            int budget = 33;
            int k = 1;
            string expected_ = "YES";

            clock_t start_           = clock();
            string received_ = CucumberMarket().check(vector<int>(price, price + (sizeof price / sizeof price[0])), budget, k);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int price[] = {1, 1, 1, 1, 1, 1};
            int budget = 2;
            int k = 4;
            string expected_ = "NO";

            clock_t start_           = clock();
            string received_ = CucumberMarket().check(vector<int>(price, price + (sizeof price / sizeof price[0])), budget, k);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int price[] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
            int budget = 10000;
            int k = 9;
            string expected_ = "YES";

            clock_t start_           = clock();
            string received_ = CucumberMarket().check(vector<int>(price, price + (sizeof price / sizeof price[0])), budget, k);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: CucumberMarket.exe -2 <CucumberMarket.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> price;
        int price_sin;
        int budget;
        int k;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            price.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>price_sin; std::cin.ignore(10, '\n');
                price.push_back(price_sin);
            }
            std::cin>>budget; std::cin.ignore(10, '\n');
            std::cin>>k; std::cin.ignore(10, '\n');
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = CucumberMarket().check(price, budget, k);
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
