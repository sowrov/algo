#include "map"
#include "set"
#include "list"
#include "vector"
#include "queue"
#include "cassert"
#include "utility"
#include "stack"
#include "iostream"
#include "cstdio"
#include "deque"
#include "string"
#include "functional"
#include "iomanip"
#include "ctime"
#include "cctype"
#include "cstdlib"
#include "cmath"
#include "bitset"
#include "numeric"
#include "algorithm"
#include "sstream"
#include "cstring"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class FlowerGarden {
public:
    vector<int> getOrdering(vector<int> height, vector<int> bloom, vector<int> wilt) {
        int count=height.size();
        vector <bool>flag(count, false);
        vector <int>out(count);

        for(int i=0; i<count; i++) {
            int cb=-1;
            for(int j=0; j<count; j++) {
                if(!flag[j]) {
                    bool yes=true;
                    for(int k=0; k<count; k++) {
                        if(j!=k && !flag[k] && height[k]<height[j] && bloom[k] <= wilt[j] && wilt[k]>=bloom[j]) {
                            yes=false;
                            break;
                        }
                    }
                    if (yes && (cb==-1 || height[j]>height[cb])) cb=j;
                }
            }

            out[i]=height[cb];
            flag[cb]=true;
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
            //printf("Going to run %d\n",i);
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


    int verify_case(int casenum, const vector<int> &expected, const vector<int> &received, clock_t elapsed) { 
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
            int height[] = {5, 4, 3, 2, 1};
            int bloom[] = {1, 1, 1, 1, 1};
            int wilt[] = {365, 365, 365, 365, 365};
            int expected_[] = {1, 2, 3, 4, 5};

            clock_t start_           = clock();
            vector<int> received_ = FlowerGarden().getOrdering(vector<int>(height, height + (sizeof height / sizeof height[0])), vector<int>(bloom, bloom + (sizeof bloom / sizeof bloom[0])), vector<int>(wilt, wilt + (sizeof wilt / sizeof wilt[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 1: {
            int height[] = {5, 4, 3, 2, 1};
            int bloom[] = {1, 5, 10, 15, 20};
            int wilt[] = {4, 9, 14, 19, 24};
            int expected_[] = {5, 4, 3, 2, 1};

            clock_t start_           = clock();
            vector<int> received_ = FlowerGarden().getOrdering(vector<int>(height, height + (sizeof height / sizeof height[0])), vector<int>(bloom, bloom + (sizeof bloom / sizeof bloom[0])), vector<int>(wilt, wilt + (sizeof wilt / sizeof wilt[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 2: {
            int height[] = {5, 4, 3, 2, 1};
            int bloom[] = {1, 5, 10, 15, 20};
            int wilt[] = {5, 10, 15, 20, 25};
            int expected_[] = {1, 2, 3, 4, 5};

            clock_t start_           = clock();
            vector<int> received_ = FlowerGarden().getOrdering(vector<int>(height, height + (sizeof height / sizeof height[0])), vector<int>(bloom, bloom + (sizeof bloom / sizeof bloom[0])), vector<int>(wilt, wilt + (sizeof wilt / sizeof wilt[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 3: {
            int height[] = {5, 4, 3, 2, 1};
            int bloom[] = {1, 5, 10, 15, 20};
            int wilt[] = {5, 10, 14, 20, 25};
            int expected_[] = {3, 4, 5, 1, 2};

            clock_t start_           = clock();
            vector<int> received_ = FlowerGarden().getOrdering(vector<int>(height, height + (sizeof height / sizeof height[0])), vector<int>(bloom, bloom + (sizeof bloom / sizeof bloom[0])), vector<int>(wilt, wilt + (sizeof wilt / sizeof wilt[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 4: {
            int height[] = {1, 2, 3, 4, 5, 6};
            int bloom[] = {1, 3, 1, 3, 1, 3};
            int wilt[] = {2, 4, 2, 4, 2, 4};
            int expected_[] = {2, 4, 6, 1, 3, 5};

            clock_t start_           = clock();
            vector<int> received_ = FlowerGarden().getOrdering(vector<int>(height, height + (sizeof height / sizeof height[0])), vector<int>(bloom, bloom + (sizeof bloom / sizeof bloom[0])), vector<int>(wilt, wilt + (sizeof wilt / sizeof wilt[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 5: {
            int height[] = {3, 2, 5, 4};
            int bloom[] = {1, 2, 11, 10};
            int wilt[] = {4, 3, 12, 13};
            int expected_[] = {4, 5, 2, 3};

            clock_t start_           = clock();
            vector<int> received_ = FlowerGarden().getOrdering(vector<int>(height, height + (sizeof height / sizeof height[0])), vector<int>(bloom, bloom + (sizeof bloom / sizeof bloom[0])), vector<int>(wilt, wilt + (sizeof wilt / sizeof wilt[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: FlowerGarden.exe -2 <FlowerGardenIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> height;
        int height_sin;
        vector<int> bloom;
        int bloom_sin;
        vector<int> wilt;
        int wilt_sin;
        vector<int> expected_;
        int expected__sin;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            height.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>height_sin; std::cin.ignore(10, '\n');
                height.push_back(height_sin);
            }
            bloom.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>bloom_sin; std::cin.ignore(10, '\n');
                bloom.push_back(bloom_sin);
            }
            wilt.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>wilt_sin; std::cin.ignore(10, '\n');
                wilt.push_back(wilt_sin);
            }
            expected_.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>expected__sin; std::cin.ignore(10, '\n');
                expected_.push_back(expected__sin);
            }
            clock_t start_           = clock();
            vector<int> received_ = FlowerGarden().getOrdering(height, bloom, wilt);
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
