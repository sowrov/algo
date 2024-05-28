#include "iostream"
#include "cstdlib"
#include "cstdio"
#include "iomanip"
#include "cctype"
#include "deque"
#include "queue"
#include "map"
#include "algorithm"
#include "bitset"
#include "numeric"
#include "cmath"
#include "fstream"
#include "cassert"
#include "cstring"
#include "functional"
#include "list"
#include "ctime"
#include "utility"
#include "vector"
#include "stack"
#include "sstream"
#include "set"
#include "string"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class SlimeXSlimesCity {
public:
    int merge(vector<int> pop) {
        int out=0;
        sort(pop.begin(), pop.end());
        bool yea=true;
        for (int i=1; i<pop.size(); i++) {
            if (pop[i-1]!=pop[i]) {
                yea=false;
                break;
            }
        }
        if (yea) return pop.size();
        
        for (int i=pop.size()-1; i>=0; i--) {
            yea=true; 
            long long n=pop[i];
            for (int j=0; j<pop.size() && yea; j++) {
               if (i==j) continue;
               if(n<pop[j]) {
                  yea=false;
               }
               n+=pop[j];
            }
            if (yea) {
                //printf("%d\n", pop[i]);
                out++;
            }
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
            int population[] = {2, 3, 4};
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = SlimeXSlimesCity().merge(vector<int>(population, population + (sizeof population / sizeof population[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int population[] = {1, 2, 3};
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = SlimeXSlimesCity().merge(vector<int>(population, population + (sizeof population / sizeof population[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int population[] = {8, 2, 3, 8};
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = SlimeXSlimesCity().merge(vector<int>(population, population + (sizeof population / sizeof population[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int population[] = {1000000000, 999999999, 999999998, 999999997};
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = SlimeXSlimesCity().merge(vector<int>(population, population + (sizeof population / sizeof population[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int population[] = {1, 1, 1};
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = SlimeXSlimesCity().merge(vector<int>(population, population + (sizeof population / sizeof population[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int population[] = {1, 2, 4, 6, 14, 16, 20};
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = SlimeXSlimesCity().merge(vector<int>(population, population + (sizeof population / sizeof population[0])));
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
    //Command line example: SlimeXSlimesCity.exe -2 <SlimeXSlimesCityIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> population;
        int population_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            population.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>population_sin; std::cin.ignore(10, '\n');
                population.push_back(population_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = SlimeXSlimesCity().merge(population);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("SlimeXSlimesCity.st", std::ios_base::app);
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
