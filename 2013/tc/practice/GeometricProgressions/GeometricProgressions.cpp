#include "fstream"
#include "utility"
#include "vector"
#include "cstdlib"
#include "ctime"
#include "cassert"
#include "map"
#include "functional"
#include "cmath"
#include "sstream"
#include "list"
#include "set"
#include "bitset"
#include "cstdio"
#include "iostream"
#include "cctype"
#include "stack"
#include "iomanip"
#include "string"
#include "deque"
#include "cstring"
#include "algorithm"
#include "queue"
#include "numeric"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )
#define MaxN 22361

vector<int>prime, b1p, b2p, q1p, q2p;
map<int, int>b1m, b2m;
map<int, int>::iterator iiit;
map<string, bool>db;
char arr[100];

class GeometricProgressions {
    bool flg[MaxN];
public:
    int count(int b1, int q1, int n1, int b2, int q2, int n2) {
        int out;
        prime.clear();
        db.clear();

        Zclr(flg);
        int sn = sqrt(MaxN);

        for (int i=2; i<=sn; i++) {
            if (!flg[i]) {
                int k=2;
                for (int j=i*k; j<MaxN;) {
                    flg[j]=1;
                    k++;
                    j=i*k;
                }
            }
        }
        for (int i=2; i<MaxN; i++) {
            if (!flg[i]) {
                prime.push_back(i);
            }
        }
        primeF(b1, b1p);
        primeF(q1, q1p);
        primeF(b2, b2p);
        primeF(q2, q2p);


        for (int j=0; j<n1; j++) {
            b1m.clear();
            for (int i=0; i<b1p.size(); i+=2) {
                b1m[b1p[i]]=b1p[i+1];
            }

            for (int i=0; i<q1p.size(); i+=2) {
                int v = b1m[q1p[i]];
                if (q1p[i]==1) {
                    b1m[1]=1;
                } else {
                    b1m[q1p[i]]=v+(q1p[i+1]*j);
                }
            }
            string str="";
            for (iiit=b1m.begin(); iiit!=b1m.end(); iiit++) {
                int v=iiit->first;
                int w=iiit->second;
                if (v==0 || w==0) {
                    str="0";
                    break;
                }
                sprintf(arr, "%d^", v);
                if (str!="") {
                    str += "*";
                }
                str += arr;
                sprintf(arr, "%d", w);
                str += arr;
            }
            //printf("%s\n", str.c_str());
            if (str!="")
                db[str]=true;

        }
        for (int j=0; j<n2; j++) {
            b1m.clear();
            for (int i=0; i<b2p.size(); i+=2) {
                b1m[b2p[i]]=b2p[i+1];
            }

            for (int i=0; i<q2p.size(); i+=2) {
                int v = b1m[q2p[i]];
                if (q2p[i]==1) {
                    b1m[1]=1;
                } else {
                    b1m[q2p[i]]=v+(q2p[i+1]*j);
                }
            }
            string str="";
            for (iiit=b1m.begin(); iiit!=b1m.end(); iiit++) {
                int v=iiit->first;
                int w=iiit->second;
                if (v==0 || w==0) {
                    str="0";
                    break;
                }
                sprintf(arr, "%d^", v);
                if (str!="") {
                    str += "*";
                }
                str += arr;
                sprintf(arr, "%d", w);
                str += arr;
            }
            if (str!="")
                db[str]=true;
            //printf("%s\n", str.c_str());

        }

        return db.size();
    }

    void primeF(int n, vector<int>&p) {
        p.clear();
        int i=0;
        while(n>1 && i<prime.size()) {
            if (n%prime[i]==0) {
                int c=0;
                while(n%prime[i]==0 && n>1) {
                    n/=prime[i];
                    c++;
                }
                p.push_back(prime[i]);
                p.push_back(c);
            }
            i++;
        }
        if (n>1) {
            p.push_back(n);
            p.push_back(1);
        }
        if (p.empty()) {
            p.push_back(n);
            p.push_back(1);
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
            int b1 = 3;
            int q1 = 2;
            int n1 = 5;
            int b2 = 6;
            int q2 = 2;
            int n2 = 5;
            int expected_ = 6;

            clock_t start_           = clock();
            int received_ = GeometricProgressions().count(b1, q1, n1, b2, q2, n2);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int b1 = 9;
            int q1 = 0;
            int n1 = 5;
            int b2 = 2;
            int q2 = 1;
            int n2 = 5;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = GeometricProgressions().count(b1, q1, n1, b2, q2, n2);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int b1 = 1;
            int q1 = 1;
            int n1 = 1;
            int b2 = 0;
            int q2 = 0;
            int n2 = 1;
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = GeometricProgressions().count(b1, q1, n1, b2, q2, n2);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int b1 = 3;
            int q1 = 4;
            int n1 = 100500;
            int b2 = 48;
            int q2 = 1024;
            int n2 = 1000;
            int expected_ = 100500;

            clock_t start_           = clock();
            int received_ = GeometricProgressions().count(b1, q1, n1, b2, q2, n2);
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
    //Command line example: GeometricProgressions.exe -2 <GeometricProgressions.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int b1;
        int q1;
        int n1;
        int b2;
        int q2;
        int n2;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>b1; std::cin.ignore(10, '\n');
            std::cin>>q1; std::cin.ignore(10, '\n');
            std::cin>>n1; std::cin.ignore(10, '\n');
            std::cin>>b2; std::cin.ignore(10, '\n');
            std::cin>>q2; std::cin.ignore(10, '\n');
            std::cin>>n2; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = GeometricProgressions().count(b1, q1, n1, b2, q2, n2);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("GeometricProgressions.st", std::ios_base::app);
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
