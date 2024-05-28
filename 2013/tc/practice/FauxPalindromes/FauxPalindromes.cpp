#include "functional"
#include "cctype"
#include "cstring"
#include "cassert"
#include "bitset"
#include "vector"
#include "cmath"
#include "list"
#include "deque"
#include "ctime"
#include "iomanip"
#include "cstdlib"
#include "algorithm"
#include "cstdio"
#include "sstream"
#include "string"
#include "queue"
#include "iostream"
#include "set"
#include "map"
#include "utility"
#include "numeric"
#include "stack"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class FauxPalindromes {
public:
    string classifyIt(string word) {
        string out;
        if (isPal(word)) {
            return "PALINDROME";
        } else if (isFlux(word)) {
            return "FAUX";
        }

        return "NOT EVEN FAUX";
    }

    bool isPal(string str) {
        for (int i=0; i<str.size()/2; i++) {
            if (str[i] != str[str.size()-1-i]) {
                return false;
            }
        }

        return true;
    }

    bool isFlux(string str) {
        string flux="";
        char ch = 0;

        for (int i=0; i<str.size(); i++) {
            if (ch!=str[i]) {
                ch = str[i];
                flux += str[i];
            }
        }

        return isPal(flux);
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
            string word = "ANA";
            string expected_ = "PALINDROME";

            clock_t start_           = clock();
            string received_ = FauxPalindromes().classifyIt(word);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string word = "AAAAANNAA";
            string expected_ = "FAUX";

            clock_t start_           = clock();
            string received_ = FauxPalindromes().classifyIt(word);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string word = "LEGENDARY";
            string expected_ = "NOT EVEN FAUX";

            clock_t start_           = clock();
            string received_ = FauxPalindromes().classifyIt(word);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string word = "XXXYTYYTTYX";
            string expected_ = "FAUX";

            clock_t start_           = clock();
            string received_ = FauxPalindromes().classifyIt(word);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string word = "TOPCOODEREDOOCPOT";
            string expected_ = "PALINDROME";

            clock_t start_           = clock();
            string received_ = FauxPalindromes().classifyIt(word);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            string word = "TOPCODEREDOOCPOT";
            string expected_ = "FAUX";

            clock_t start_           = clock();
            string received_ = FauxPalindromes().classifyIt(word);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 6: {
            string word = "XXXXYYYYYZZXXYYY";
            string expected_ = "NOT EVEN FAUX";

            clock_t start_           = clock();
            string received_ = FauxPalindromes().classifyIt(word);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: FauxPalindromes.exe -2 <FauxPalindromesIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        string word;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::getline(std::cin,word);
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = FauxPalindromes().classifyIt(word);
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
