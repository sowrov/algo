#include "map"
#include "iostream"
#include "cstring"
#include "numeric"
#include "cassert"
#include "deque"
#include "sstream"
#include "functional"
#include "fstream"
#include "ctime"
#include "list"
#include "algorithm"
#include "bitset"
#include "string"
#include "queue"
#include "cstdlib"
#include "cctype"
#include "cmath"
#include "cstdio"
#include "iomanip"
#include "vector"
#include "utility"
#include "set"
#include "stack"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )
class TheJackpotDivOne {
    vector<long long> hip;
public:
    void insert(long long n) {
        hip.push_back(n);
        int c=hip.size()-1;
        long long v;
        while(c>0) {
            int p=(c-1)/2;
            if (hip[p]>hip[c]) {
                v=hip[c];
                hip[c]=hip[p];
                hip[p]=v;
            }
            c=p;
        }
    }
    void delMin() {
        int n=hip.size()-1;
        long long v=hip[n];
        hip.pop_back();
        hip[0]=v;
        int p=0;
        while(p<n) {
            int c1=2*p+1;
            if (c1>=n) break;
            int c2=c1+1;
            if (c2<n && hip[c2]<hip[c1]) c1=c2;

            if (hip[c1]<hip[p]) {
                v=hip[c1];
                hip[c1]=hip[p];
                hip[p]=v;
                p=c1;
            } else {
                break;
            }
        }
    }

    void show() {
        Rep(i, hip.size()) {
            cout<<hip[i]<<", ";
        }
        cout<<endl;
    }
    vector<long long> find(vector<long long> money, long long jackpot) {
        long long sum=0;
        Rep(i, money.size()) {
            sum += money[i];
            insert(money[i]);
        }
        //show();
        int n=money.size();
        long long x, ia, v;

        while(jackpot>0) {
            ia=sum/n;
            ia++;
            x=min(ia-hip[0], jackpot);
            //cout<<"sum: "<<sum<<" av:"<<ia<<" x:"<<x<<" hip0:"<<hip[0]<<" nh:"<<hip[0]+x<<endl;
            
            sum+=x;
            jackpot-=x;
            v=hip[0];
            delMin();
            //show();
            insert(v+x);
            //show();
            //cout<<"--------------\n";
        }
        sort(hip.begin(), hip.end());
        return hip;
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

    template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }


    int verify_case(int casenum, const vector<long long> &expected, const vector<long long> &received, clock_t elapsed) { 
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
            long long money[] = {1LL, 2LL, 3LL, 4LL};
            long long jackpot = 2LL;
            long long expected_[] = {2LL, 3LL, 3LL, 4LL};

            clock_t start_           = clock();
            vector<long long> received_ = TheJackpotDivOne().find(vector<long long>(money, money + (sizeof money / sizeof money[0])), jackpot);
            return verify_case(casenum, vector<long long>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 1: {
            long long money[] = {4LL};
            long long jackpot = 7LL;
            long long expected_[] = {11LL};

            clock_t start_           = clock();
            vector<long long> received_ = TheJackpotDivOne().find(vector<long long>(money, money + (sizeof money / sizeof money[0])), jackpot);
            return verify_case(casenum, vector<long long>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 2: {
            long long money[] = {4LL, 44LL, 7LL, 77LL};
            long long jackpot = 47LL;
            long long expected_[] = {24LL, 34LL, 44LL, 77LL};

            clock_t start_           = clock();
            vector<long long> received_ = TheJackpotDivOne().find(vector<long long>(money, money + (sizeof money / sizeof money[0])), jackpot);
            return verify_case(casenum, vector<long long>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 3: {
            long long money[] = {4LL, 10LL, 8LL, 3LL, 6LL, 5LL, 8LL, 3LL, 7LL, 5LL};
            long long jackpot = 1000LL;
            long long expected_[] = {105LL, 106LL, 106LL, 106LL, 106LL, 106LL, 106LL, 106LL, 106LL, 106LL};

            clock_t start_           = clock();
            vector<long long> received_ = TheJackpotDivOne().find(vector<long long>(money, money + (sizeof money / sizeof money[0])), jackpot);
            return verify_case(casenum, vector<long long>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
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
    //Command line example: TheJackpotDivOne.exe -2 <TheJackpotDivOne.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<long long> money;
        long long money_sin;
        long long jackpot;
        vector<long long> expected_;
        long long expected__sin;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            money.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>money_sin; std::cin.ignore(10, '\n');
                money.push_back(money_sin);
            }
            std::cin>>jackpot; std::cin.ignore(10, '\n');
            expected_.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>expected__sin; std::cin.ignore(10, '\n');
                expected_.push_back(expected__sin);
            }
            clock_t start_           = clock();
            vector<long long> received_ = TheJackpotDivOne().find(money, jackpot);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("TheJackpotDivOne.st", std::ios_base::app);
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
