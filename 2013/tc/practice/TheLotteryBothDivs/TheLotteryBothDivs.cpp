#include "map"
#include "cstdio"
#include "list"
#include "set"
#include "utility"
#include "cassert"
#include "ctime"
#include "sstream"
#include "cstdlib"
#include "stack"
#include "queue"
#include "vector"
#include "deque"
#include "iomanip"
#include "functional"
#include "iostream"
#include "fstream"
#include "bitset"
#include "cmath"
#include "cstring"
#include "algorithm"
#include "string"
#include "cctype"
#include "numeric"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

map<string, bool>db;
map<string, bool>::iterator mi;

bool comp(string a, string b) {
    return a.size()<b.size();
}
class TheLotteryBothDivs {
public:
    double find(vector<string> gs) {
        double out;
        db.clear();
        sort(gs.begin(), gs.end(), comp);
        string tstr;

        for (int i=0; i<gs.size(); i++) {
            tstr="";
            bool found=false;
            for (int j=gs[i].size()-1; j>=0; j--) {
                tstr += gs[i][j];
                if (db.find(tstr)!=db.end()) {
                    found=true;
                    break;
                }
            }
            if (!found) {
                //cout<<gs[i]<<endl;
                db[tstr]=true;
            }
        }

        long long t=0, mx=1e9;
        int ml=9;
        for (mi=db.begin(); mi!=db.end(); mi++) {
            int len = mi->first.size();
            int v=1;
            for (int i=1; i<=(ml-len); i++) {
                v*=10;
            }
            t+=v;
            //cout<<v<<endl;
        }
        return t*1.0/mx;
    }
};

// <editor-fold defaultstate="collapsed" desc="Generated Code">
namespace otocoder {
#ifndef isinf
#define isinf(x) (!_finite(x))
#define isnan(x) _isnan(x)
#endif
    static const double epsilon = 1e-9; static bool compareDouble(double expected, double result) { return (fabs(expected - result) <= epsilon * fmax(1.0, fmax(fabs(expected), fabs(result)))); }
    double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }

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

    int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
        cerr << "Example " << casenum << "... "; 

        string verdict;
        vector<string> info;
        char buf[100];

        if (elapsed > CLOCKS_PER_SEC / 200) {
            sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
            info.push_back(buf);
        }

        if (compareDouble(expected, received)) {
            verdict = "PASSED";
            double rerr = moj_relative_error(expected, received); 
            if (rerr > 0) {
                sprintf(buf, "relative error %.3e", rerr);
                info.push_back(buf);
            }
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
            string goodSuffixes[] = {"4"};
            double expected_ = 0.1;

            clock_t start_           = clock();
            double received_ = TheLotteryBothDivs().find(vector<string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string goodSuffixes[] = {"4", "7"};
            double expected_ = 0.2;

            clock_t start_           = clock();
            double received_ = TheLotteryBothDivs().find(vector<string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string goodSuffixes[] = {"47", "47"};
            double expected_ = 0.01;

            clock_t start_           = clock();
            double received_ = TheLotteryBothDivs().find(vector<string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string goodSuffixes[] = {"47", "58", "4747", "502"};
            double expected_ = 0.021;

            clock_t start_           = clock();
            double received_ = TheLotteryBothDivs().find(vector<string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string goodSuffixes[] = {"8542861", "1954", "6", "523", "000000000", "5426", "8"};
            double expected_ = 0.201100101;

            clock_t start_           = clock();
            double received_ = TheLotteryBothDivs().find(vector<string>(goodSuffixes, goodSuffixes + (sizeof goodSuffixes / sizeof goodSuffixes[0])));
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
    //Command line example: TheLotteryBothDivs.exe -2 <TheLotteryBothDivsIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<string> goodSuffixes;
        string goodSuffixes_sin;
        double expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            goodSuffixes.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,goodSuffixes_sin );
                goodSuffixes.push_back(goodSuffixes_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            double received_ = TheLotteryBothDivs().find(goodSuffixes);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("TheLotteryBothDivs.st", std::ios_base::app);
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
