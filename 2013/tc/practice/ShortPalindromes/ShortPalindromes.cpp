#include "iomanip"
#include "cmath"
#include "map"
#include "bitset"
#include "functional"
#include "queue"
#include "cstdlib"
#include "list"
#include "cassert"
#include "set"
#include "utility"
#include "cstring"
#include "string"
#include "cstdio"
#include "cctype"
#include "deque"
#include "algorithm"
#include "numeric"
#include "sstream"
#include "iostream"
#include "stack"
#include "ctime"
#include "vector"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class ShortPalindromes {
public:
    string mStr[26][26];
    string str;
    int mNum[26][26];

    int findPal(int s, int e) {
        if (s>e) return 0;
        if (s==e) {
            mStr[s][e] = str[s];
            return 1;
        }

        if (mNum[s][e]!=-1) {
            return mNum[s][e];
        }
        string t1, t2;
        int n1, n2;
        if (str[s]==str[e]) {
            t1=str[s];
            
            n1 = findPal(s+1, e-1);
            if (n1>0) { 
                t1 += mStr[s+1][e-1];
            }
            t1+=str[e];
            mStr[s][e] = t1;
            mNum[s][e] = n1+2;
        } else {
            n1 = findPal(s, e-1);
            n2 = findPal(s+1, e);
            if (n1>0 && n2<=0 || (n1>0 && n2>0 && n1<n2)) {
                t1 = str[e];
                t1 += mStr[s][e-1] +str[e];
                mStr[s][e] = t1;
                mNum[s][e] = n1+2;
            }
            
            if (n1<=0 && n2>0 || (n1>0 && n2>0 && n2<n1)) {
                t1 = str[s];
                t1 += mStr[s+1][e] + str[s];
                mStr[s][e] = t1;
                mNum[s][e] = n2+2;
            }

            if (n1>0 && n2>0 && n1==n2) {
                t1 = str[e];
                t1 += mStr[s][e-1] + str[e];

                t2 = str[s];
                t2 += mStr[s+1][e] + str[s];
                mNum[s][e] = n1+2;

                if (t1<t2) {
                    mStr[s][e] = t1;
                } else {
                    mStr[s][e] = t2;
                }
            }
        }
        return mNum[s][e];
    }

    string shortest(string base) {
        string out;
        Nclr(mNum);
        str = base;

        findPal(0, str.length()-1);
        return mStr[0][str.length()-1];
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
            string base = "RACE";
            string expected_ = "ECARACE";

            clock_t start_           = clock();
            string received_ = ShortPalindromes().shortest(base);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string base = "TOPCODER";
            string expected_ = "REDTOCPCOTDER";

            clock_t start_           = clock();
            string received_ = ShortPalindromes().shortest(base);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string base = "Q";
            string expected_ = "Q";

            clock_t start_           = clock();
            string received_ = ShortPalindromes().shortest(base);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string base = "MADAMIMADAM";
            string expected_ = "MADAMIMADAM";

            clock_t start_           = clock();
            string received_ = ShortPalindromes().shortest(base);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string base = "ALRCAGOEUAOEURGCOEUOOIGFA";
            string expected_ = "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA";

            clock_t start_           = clock();
            string received_ = ShortPalindromes().shortest(base);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: ShortPalindromes.exe -2 <ShortPalindromes.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        string base;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::getline(std::cin,base);
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = ShortPalindromes().shortest(base);
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
