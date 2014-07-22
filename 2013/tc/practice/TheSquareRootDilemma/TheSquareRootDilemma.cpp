#include "cassert"
#include "utility"
#include "string"
#include "list"
#include "cstdio"
#include "cmath"
#include "queue"
#include "iostream"
#include "cstring"
#include "cctype"
#include "functional"
#include "numeric"
#include "deque"
#include "iomanip"
#include "algorithm"
#include "vector"
#include "bitset"
#include "set"
#include "map"
#include "cstdlib"
#include "sstream"
#include "stack"
#include "ctime"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class TheSquareRootDilemma {
public:
    int countPairs(int N, int M) {
        int out=0, di;
        double d;
        if (M<N) {
            M ^= N;
            N ^= M;
            M ^= N;
        }
        vector<int>fn;
        int x=1;
        while(x*x<=M) {
            fn.push_back(x*x);
            x++;
        }

        for (int i=1; i<=N; i++) {
            int j=-1;
            for (int k=1; k<fn.size(); k++) {
                if (i%fn[k]==0) {
                    j=k;
                    //break;
                }
                if (fn[k]>i) break;
            }
            x=i;
            if (j>-1) {
                x /= fn[j];
            } else {
                j=0;
            }
            int v;
            for (int k=j; k<fn.size(); k++) {
                v=x*fn[k];
                if (v>M) break;
                if (v<=N && v!=i){
                    //cout<<"2 = "<<i<<", "<<v<<endl;
                    out+=2;
                }
                else {
                    //cout<<"1 = "<<i<<", "<<v<<endl;
                    out++;
                }
            }
        }
        //for (int i=1; i<=N; i++) {
        //    if (i<=M) out++;//for i==j
        //    for (int j=i+1; j<=M; j++) {
        //        d = sqrt(i)+sqrt(j);
        //        d *= d;
        //        di = round(d);

        //        if ( fabs(d-di)<Eps) {
        //            cout<<i<<", "<<j<<endl;
        //            if (j<=N) {
        //                out++;
        //                cout<<j<<", "<<i<<endl;
        //            }
        //            out++;
        //        }
        //    }
        //}
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
            int N = 77777;
            int M = 77777;
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = TheSquareRootDilemma().countPairs(N, M);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int N = 10;
            int M = 1;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = TheSquareRootDilemma().countPairs(N, M);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int N = 3;
            int M = 8;
            int expected_ = 5;

            clock_t start_           = clock();
            int received_ = TheSquareRootDilemma().countPairs(N, M);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int N = 100;
            int M = 100;
            int expected_ = 310;

            clock_t start_           = clock();
            int received_ = TheSquareRootDilemma().countPairs(N, M);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: TheSquareRootDilemma.exe -2 <TheSquareRootDilemma.io
    bool run_full_test() {
        int testCase, caseNo, correct=0;
        int N;
        int M;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>N; std::cin.ignore(10, '\n');
            std::cin>>M; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = TheSquareRootDilemma().countPairs(N, M);
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
