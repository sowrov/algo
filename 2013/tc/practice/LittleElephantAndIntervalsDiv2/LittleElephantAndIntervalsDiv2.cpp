#include "map"
#include "sstream"
#include "cctype"
#include "stack"
#include "ctime"
#include "vector"
#include "cstring"
#include "functional"
#include "cstdlib"
#include "cassert"
#include "iomanip"
#include "cmath"
#include "fstream"
#include "iostream"
#include "deque"
#include "cstdio"
#include "numeric"
#include "utility"
#include "bitset"
#include "set"
#include "algorithm"
#include "string"
#include "queue"
#include "list"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

map<string, bool>db;

class LittleElephantAndIntervalsDiv2 {
public:
    int getNumber(int M, vector<int> L, vector<int> R) {
        int out=0;
        db.clear();
        vector<string>vstr, vtstr;
        string str;
        for (int i=0; i<M; i++) {
            str+="W";
        }
        vstr.push_back(str);

        for (int i=0; i<L.size(); i++) {
            vtstr.clear();
            for (int j=0; j<vstr.size(); j++) {
                string bstr=vstr[j];
                string wstr=bstr;
                for (int k=L[i]-1; k<=R[i]-1; k++) {
                    bstr[k]='B';
                    wstr[k]='W';
                }
                vtstr.push_back(bstr);
                vtstr.push_back(wstr);
            }

            vstr.clear();
            for (int j=0; j<vtstr.size(); j++) {
                vstr.push_back(vtstr[j]);
                //printf("%s\n", vstr[j].c_str());
            }
            //printf("\n");
        }
        
        for (int i=0; i<vstr.size(); i++) {
            //printf("%s\n", vstr[i].c_str());
            if (!db[vstr[i]]) {
                out++;
            }
            db[vstr[i]]=true;
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
            int M = 4;
            int L[] = {1, 2, 3};
            int R[] = {1, 2, 3};
            int expected_ = 8;

            clock_t start_           = clock();
            int received_ = LittleElephantAndIntervalsDiv2().getNumber(M, vector<int>(L, L + (sizeof L / sizeof L[0])), vector<int>(R, R + (sizeof R / sizeof R[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int M = 3;
            int L[] = {1, 1, 2};
            int R[] = {3, 1, 3};
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = LittleElephantAndIntervalsDiv2().getNumber(M, vector<int>(L, L + (sizeof L / sizeof L[0])), vector<int>(R, R + (sizeof R / sizeof R[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int M = 100;
            int L[] = {47};
            int R[] = {74};
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = LittleElephantAndIntervalsDiv2().getNumber(M, vector<int>(L, L + (sizeof L / sizeof L[0])), vector<int>(R, R + (sizeof R / sizeof R[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int M = 100;
            int L[] = {10, 20, 50};
            int R[] = {20, 50, 100};
            int expected_ = 8;

            clock_t start_           = clock();
            int received_ = LittleElephantAndIntervalsDiv2().getNumber(M, vector<int>(L, L + (sizeof L / sizeof L[0])), vector<int>(R, R + (sizeof R / sizeof R[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int M = 42;
            int L[] = {5, 23, 4, 1, 15, 2, 22, 26, 13, 16};
            int R[] = {30, 41, 17, 1, 21, 6, 28, 30, 15, 19};
            int expected_ = 512;

            clock_t start_           = clock();
            int received_ = LittleElephantAndIntervalsDiv2().getNumber(M, vector<int>(L, L + (sizeof L / sizeof L[0])), vector<int>(R, R + (sizeof R / sizeof R[0])));
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
    //Command line example: LittleElephantAndIntervalsDiv2.exe -2 <LittleElephantAndIntervalsDiv2.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int M;
        vector<int> L;
        int L_sin;
        vector<int> R;
        int R_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>M; std::cin.ignore(10, '\n');
            L.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>L_sin; std::cin.ignore(10, '\n');
                L.push_back(L_sin);
            }
            R.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>R_sin; std::cin.ignore(10, '\n');
                R.push_back(R_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = LittleElephantAndIntervalsDiv2().getNumber(M, L, R);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("LittleElephantAndIntervalsDiv2.st", std::ios_base::app);
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
