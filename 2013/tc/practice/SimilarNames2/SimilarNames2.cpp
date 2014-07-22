#include "iostream"
#include "cassert"
#include "queue"
#include "cstring"
#include "fstream"
#include "numeric"
#include "set"
#include "cmath"
#include "iomanip"
#include "sstream"
#include "map"
#include "cstdlib"
#include "list"
#include "ctime"
#include "stack"
#include "utility"
#include "algorithm"
#include "functional"
#include "string"
#include "deque"
#include "cstdio"
#include "vector"
#include "bitset"
#include "cctype"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )
#define Mod 1000000007

int dp[50][50];
vector <string>nam;

class SimilarNames2 {
public:
    int count(vector<string> names, int L) {
        long long out=0;
        nam = names;
        Nclr(dp);
        
        if (L==1) {
            return fact(nam.size());
        }

        for (int i=0; i<nam.size(); i++) {
            out += memo(i, L-1);
            out %= Mod;
        }
        out *= fact(nam.size()-L);

        return out%Mod;
    }

    int fact(int n) {
        long long v=1;
        for (int i=2; i<=n; i++) {
            v *= i;
            v %= Mod;
        }
        return v;
    }

    int memo(int p, int n) {
        if (n==0) {
            return 1;
        }
        int &res = dp[p][n];
        if (res!=-1) return res;
        
        long long out=0;
        for (int i=0; i<nam.size(); i++) {
            if (i==p) continue;
            if (nam[i].size()>nam[p].size() && nam[i].compare(0, nam[p].size(), nam[p])==0) {
                out += memo(i, n-1);
                out %= Mod;
            }
        }
        res = out;
        return res;
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
            string names[] = {"kenta", "kentaro", "ken"};
            int L = 2;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = SimilarNames2().count(vector<string>(names, names + (sizeof names / sizeof names[0])), L);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string names[] = {"hideo", "hideto", "hideki", "hide"};
            int L = 2;
            int expected_ = 6;

            clock_t start_           = clock();
            int received_ = SimilarNames2().count(vector<string>(names, names + (sizeof names / sizeof names[0])), L);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string names[] = {"aya", "saku", "emi", "ayane", "sakura", "emika", "sakurako"};
            int L = 3;
            int expected_ = 24;

            clock_t start_           = clock();
            int received_ = SimilarNames2().count(vector<string>(names, names + (sizeof names / sizeof names[0])), L);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string names[] = {"taro", "jiro", "hanako"};
            int L = 2;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = SimilarNames2().count(vector<string>(names, names + (sizeof names / sizeof names[0])), L);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string names[] = {"alice", "bob", "charlie"};
            int L = 1;
            int expected_ = 6;

            clock_t start_           = clock();
            int received_ = SimilarNames2().count(vector<string>(names, names + (sizeof names / sizeof names[0])), L);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            string names[] = {"ryota", "ryohei", "ryotaro", "ryo", "ryoga", "ryoma", "ryoko", "ryosuke", "ciel", "lun", "ryuta", "ryuji", "ryuma", "ryujiro", "ryusuke", "ryutaro", "ryu", "ryuhei", "ryuichi", "evima"};
            int L = 3;
            int expected_ = 276818566;

            clock_t start_           = clock();
            int received_ = SimilarNames2().count(vector<string>(names, names + (sizeof names / sizeof names[0])), L);
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
    //Command line example: SimilarNames2.exe -2 <SimilarNames2.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<string> names;
        string names_sin;
        int L;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            names.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,names_sin );
                names.push_back(names_sin);
            }
            std::cin>>L; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = SimilarNames2().count(names, L);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("SimilarNames2.st", std::ios_base::app);
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
