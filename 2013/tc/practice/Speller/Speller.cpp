#include "vector"
#include "algorithm"
#include "cstdio"
#include "functional"
#include "cstring"
#include "ctime"
#include "utility"
#include "cmath"
#include "string"
#include "iomanip"
#include "numeric"
#include "stack"
#include "deque"
#include "cctype"
#include "cassert"
#include "queue"
#include "sstream"
#include "list"
#include "iostream"
#include "cstdlib"
#include "set"
#include "bitset"
#include "map"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class Speller {
public:
    int value(string number) {
        int out=-1;
        string ones[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};//9
        string teen[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};//10
        string tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};//8
        string mNum[] = {"twenty-one", "twenty-two", "twenty-three", "twenty-four", "twenty-five", "twenty-six", "twenty-seven", "twenty-eight", "twenty-nine", "thirty-one", "thirty-two", "thirty-three", "thirty-four", "thirty-five", "thirty-six", "thirty-seven", "thirty-eight", "thirty-nine", "forty-one", "forty-two", "forty-three", "forty-four", "forty-five", "forty-six", "forty-seven", "forty-eight", "forty-nine", "fifty-one", "fifty-two", "fifty-three", "fifty-four", "fifty-five", "fifty-six", "fifty-seven", "fifty-eight", "fifty-nine", "sixty-one", "sixty-two", "sixty-three", "sixty-four", "sixty-five", "sixty-six", "sixty-seven", "sixty-eight", "sixty-nine", "seventy-one", "seventy-two", "seventy-three", "seventy-four", "seventy-five", "seventy-six", "seventy-seven", "seventy-eight", "seventy-nine", "eighty-one", "eighty-two", "eighty-three", "eighty-four", "eighty-five", "eighty-six", "eighty-seven", "eighty-eight", "eighty-nine", "ninety-one", "ninety-two", "ninety-three", "ninety-four", "ninety-five", "ninety-six", "ninety-seven", "ninety-eight", "ninety-nine"}; //72
        int minM=100000;
        int v = match(ones, 9, number, minM);
        if(v==-2) out = -1;
        if (v>-1) out = v+1;

        v = match(teen, 10, number, minM);
        if (v>-1) {
            v+=10;
            out=v;
        }
        if(v==-2) out = -1;

        v = match(tens, 8, number, minM);
        if (v>-1) {
            v *= 10;
            v += 20;
            out = v;
        }
        if(v==-2) out = -1;

        v = match(mNum, 72, number, minM);
        if(v>-1) {
            out = (v%9+1) + ((v/9)*10+20);
        }
        if(v==-2) out = -1;
        return out;
    }

    int match(string* arr, int size, string number, int& minM) {
        int cm;
        int ind=-1;
        for(int i=0; i<size; i++) {
            cm = 100000;
            if (arr[i].length() == number.length()) {
                cm = 0;
                for (int j=0; j<number.length(); j++) {
                    if (arr[i][j]!=number[j]) {
                        cm++;
                    }
                }
            }
            if (cm == minM && cm != 100000) {
                ind = -2;
            }

            if (cm<minM) {
                minM = cm;
                ind = i;
            }
        }
        return ind;
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
            string number = "forty-two";
            int expected_ = 42;

            clock_t start_           = clock();
            int received_ = Speller().value(number);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string number = "FORTY-TWO";
            int expected_ = -1;

            clock_t start_           = clock();
            int received_ = Speller().value(number);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string number = "eightene";
            int expected_ = 18;

            clock_t start_           = clock();
            int received_ = Speller().value(number);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string number = "fi";
            int expected_ = -1;

            clock_t start_           = clock();
            int received_ = Speller().value(number);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: Speller.exe -2 <SpellerIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        string number;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::getline(std::cin,number);
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = Speller().value(number);
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
