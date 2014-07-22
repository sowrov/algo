#include "cmath"
#include "cstdlib"
#include "cctype"
#include "iomanip"
#include "cstring"
#include "cstdio"
#include "functional"
#include "stack"
#include "queue"
#include "fstream"
#include "sstream"
#include "cassert"
#include "vector"
#include "map"
#include "iostream"
#include "utility"
#include "bitset"
#include "list"
#include "ctime"
#include "string"
#include "set"
#include "deque"
#include "algorithm"
#include "numeric"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )
#define MaxP 31623

bool primef[MaxP];

vector<int>prime;
vector<int>Apf, Apc, Cpf, Cpc;
class BigFatInteger2 {
public:
    string isDivisible(int A, int B, int C, int D) {
        string div="divisible", nodiv="not divisible";
        Zclr(primef);
        prime.clear();
        for (int i=2; i*i<=MaxP; i++) {
            if(!primef[i]) {
                for (int j=i*i; j<=MaxP; j+=i) {
                    primef[j]=1;
                }
            }
        }
        for (int i=2; i<=MaxP; i++) {
            if (!primef[i]) {
                prime.push_back(i);
            }
        }
        Apf.clear();
        Apc.clear();
        Cpf.clear();
        Cpc.clear();

        factorize(A, Apf, Apc);
        factorize(C, Cpf, Cpc);

        if (Apf.size() < Cpf.size()) {
            return nodiv;
        }

        for (int i=0; i<Cpf.size(); i++) {
            bool found=false;
            for (int j=0; j<Apf.size(); j++) {
                if (Cpf[i]==Apf[j]) {
                    long long cc=Cpc[i], ac=Apc[j];
                    cc *= D;
                    ac *= B;
                    if (cc<=ac) {
                        found=true;
                    }
                    break;
                }
            }

            if (!found) {
                return nodiv;
            }
        }
        return div;
    }

    void factorize(int v, vector<int>&vp, vector<int>&vc) {
        int i=0, c;
        while(v>1 && i<prime.size()) {
            if (v%prime[i]==0) {
                c=0;
                while(v>1 && v%prime[i]==0) {
                    v/=prime[i];
                    c++;
                }
                vp.push_back(prime[i]);
                vc.push_back(c);
            }
            i++;
        }
        if (v>1) {
            vp.push_back(v);
            vc.push_back(1);
        }
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
            int A = 4;
            int B = 16;
            int C = 2;
            int D = 29;
            string expected_ = "divisible";

            clock_t start_           = clock();
            string received_ = BigFatInteger2().isDivisible(A, B, C, D);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int A = 2;
            int B = 1;
            int C = 6;
            int D = 1;
            string expected_ = "not divisible";

            clock_t start_           = clock();
            string received_ = BigFatInteger2().isDivisible(A, B, C, D);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int A = 1000000000;
            int B = 1000000000;
            int C = 1000000000;
            int D = 200000000;
            string expected_ = "divisible";

            clock_t start_           = clock();
            string received_ = BigFatInteger2().isDivisible(A, B, C, D);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int A = 8;
            int B = 100;
            int C = 4;
            int D = 200;
            string expected_ = "not divisible";

            clock_t start_           = clock();
            string received_ = BigFatInteger2().isDivisible(A, B, C, D);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int A = 999999937;
            int B = 1000000000;
            int C = 999999929;
            int D = 1;
            string expected_ = "not divisible";

            clock_t start_           = clock();
            string received_ = BigFatInteger2().isDivisible(A, B, C, D);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int A = 2;
            int B = 2;
            int C = 4;
            int D = 1;
            string expected_ = "divisible";

            clock_t start_           = clock();
            string received_ = BigFatInteger2().isDivisible(A, B, C, D);
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
    //Command line example: BigFatInteger2.exe -2 <BigFatInteger2.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int A;
        int B;
        int C;
        int D;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>A; std::cin.ignore(10, '\n');
            std::cin>>B; std::cin.ignore(10, '\n');
            std::cin>>C; std::cin.ignore(10, '\n');
            std::cin>>D; std::cin.ignore(10, '\n');
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = BigFatInteger2().isDivisible(A, B, C, D);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("BigFatInteger2.st", std::ios_base::app);
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
