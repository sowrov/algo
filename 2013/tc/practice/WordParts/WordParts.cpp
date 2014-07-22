#include "iomanip"
#include "cassert"
#include "ctime"
#include "utility"
#include "sstream"
#include "map"
#include "stack"
#include "queue"
#include "list"
#include "cctype"
#include "string"
#include "iostream"
#include "vector"
#include "set"
#include "deque"
#include "cstring"
#include "bitset"
#include "algorithm"
#include "cstdlib"
#include "functional"
#include "numeric"
#include "cstdio"
#include "cmath"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class WordParts {
public:
    int partCount(string original, string compound) {
        int out[52], count;
        int len = compound.length();
        int orLen = original.length();
        int sLen;
        Nclr(out);

        cout<<"Ori: "<<original<<" comp: "<<compound<<endl;

        out[0] = 0;
        string str;
        size_t pos1, pos2;
        for (int i=0; i<len; i++) {
            if(out[i]!=-1) {
                for (int j=i+1; j<=len; j++) {
                    sLen = j-i;
                    str = compound.substr(i, sLen);
                    pos1 = original.find(str);
                    pos2 = original.rfind(str);
                    if (pos1 != string::npos) {
                        //cout<<"Str: "<<str<<endl;
                        if ((pos1 == 0) || (orLen-pos2 == sLen)) {
                            //cout<<"Found: "<<str<<"_ "<<sLen<<endl;
                            count = out[i]+1;
                            out[j] = out[j]==-1?count: min(out[j], count);
                        }
                    }
                }
            }
        }
        return out[len];
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
            string original = "ANTIDISESTABLISHMENTARIANISM";
            string compound = "ANTIDISIANISMISM";
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = WordParts().partCount(original, compound);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string original = "ANTIDISESTABLISHMENTARIANISM";
            string compound = "ESTABLISHMENT";
            int expected_ = -1;

            clock_t start_           = clock();
            int received_ = WordParts().partCount(original, compound);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string original = "TOPCODERDOTCOM";
            string compound = "TOMTMODERDOTCOM";
            int expected_ = 5;

            clock_t start_           = clock();
            int received_ = WordParts().partCount(original, compound);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string original = "HELLO";
            string compound = "HELLOHEHELLOLOHELLO";
            int expected_ = 5;

            clock_t start_           = clock();
            int received_ = WordParts().partCount(original, compound);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string original = "DONTFORGETTHEEMPTYCASE";
            string compound = "";
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = WordParts().partCount(original, compound);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            string original = "BAAABA";
            string compound = "BAAABAAA";
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = WordParts().partCount(original, compound);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 6: {
            string original = "ABBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABB";
            string compound = "BBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABAA";
            int expected_ = 17;

            clock_t start_           = clock();
            int received_ = WordParts().partCount(original, compound);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: WordParts.exe -2 <WordParts.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        string original;
        string compound;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::getline(std::cin,original);
            std::getline(std::cin,compound);
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = WordParts().partCount(original, compound);
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
