#include "map"
#include "numeric"
#include "deque"
#include "vector"
#include "stack"
#include "ctime"
#include "cctype"
#include "iomanip"
#include "utility"
#include "algorithm"
#include "bitset"
#include "sstream"
#include "iostream"
#include "cstring"
#include "cstdlib"
#include "cassert"
#include "functional"
#include "queue"
#include "string"
#include "list"
#include "set"
#include "cmath"
#include "cstdio"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class SurroundingGameEasy {
public:
    int score(vector<string> cost, vector<string> benefit, vector<string> stone) {
        int bnf=0, cst=0;
        int R = stone.size(), C = stone[0].size();
        int adj[] = {-1, 0, 0, -1, 0, 1, 1, 0};
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (stone[i][j]=='o') {
                    bnf += benefit[i][j] - '0';
                    cst += cost[i][j] - '0';
                }
                else {
                    bool dom=true;
                    for (int k=0; k<8; k+=2) {
                        int x = i+adj[k];
                        int y = j+adj[k+1];
                        if (x>=0 && y>=0 && x<R && y<C) {
                            if (stone[x][y]=='.') {
                                dom=false;
                                break;
                            }
                        }
                    }

                    if (dom) {
                        printf("domi: %d %d\n", i, j);
                        bnf += benefit[i][j] - '0';
                    }
                }
            }
        }

        printf("%d %d\n",bnf, cst);
        return bnf-cst;
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
            string cost[] = {"21", "12"};
            string benefit[] = {"21", "12"};
            string stone[] = {".o", "o."};
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = SurroundingGameEasy().score(vector<string>(cost, cost + (sizeof cost / sizeof cost[0])), vector<string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector<string>(stone, stone + (sizeof stone / sizeof stone[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string cost[] = {"99", "99"};
            string benefit[] = {"11", "11"};
            string stone[] = {".o", "o."};
            int expected_ = -14;

            clock_t start_           = clock();
            int received_ = SurroundingGameEasy().score(vector<string>(cost, cost + (sizeof cost / sizeof cost[0])), vector<string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector<string>(stone, stone + (sizeof stone / sizeof stone[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string cost[] = {"888", "888", "888"};
            string benefit[] = {"000", "090", "000"};
            string stone[] = {"...", ".o.", "..."};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = SurroundingGameEasy().score(vector<string>(cost, cost + (sizeof cost / sizeof cost[0])), vector<string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector<string>(stone, stone + (sizeof stone / sizeof stone[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string cost[] = {"4362", "4321"};
            string benefit[] = {"5329", "5489"};
            string stone[] = {"...o", "..o."};
            int expected_ = 22;

            clock_t start_           = clock();
            int received_ = SurroundingGameEasy().score(vector<string>(cost, cost + (sizeof cost / sizeof cost[0])), vector<string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector<string>(stone, stone + (sizeof stone / sizeof stone[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string cost[] = {"5413", "4323", "8321", "5490"};
            string benefit[] = {"0432", "7291", "3901", "2310"};
            string stone[] = {"ooo.", "o..o", "...o", "oooo"};
            int expected_ = -12;

            clock_t start_           = clock();
            int received_ = SurroundingGameEasy().score(vector<string>(cost, cost + (sizeof cost / sizeof cost[0])), vector<string>(benefit, benefit + (sizeof benefit / sizeof benefit[0])), vector<string>(stone, stone + (sizeof stone / sizeof stone[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: SurroundingGameEasy.exe -2 <SurroundingGameEasy.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<string> cost;
        string cost_sin;
        vector<string> benefit;
        string benefit_sin;
        vector<string> stone;
        string stone_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            cost.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,cost_sin );
                cost.push_back(cost_sin);
            }
            benefit.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,benefit_sin );
                benefit.push_back(benefit_sin);
            }
            stone.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,stone_sin );
                stone.push_back(stone_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = SurroundingGameEasy().score(cost, benefit, stone);
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
