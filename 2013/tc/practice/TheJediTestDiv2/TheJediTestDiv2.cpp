#include "vector"
#include "list"
#include "cassert"
#include "algorithm"
#include "map"
#include "bitset"
#include "ctime"
#include "cstdio"
#include "functional"
#include "sstream"
#include "queue"
#include "iostream"
#include "utility"
#include "stack"
#include "set"
#include "string"
#include "cctype"
#include "cmath"
#include "cstdlib"
#include "numeric"
#include "deque"
#include "iomanip"
#include "cstring"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class TheJediTestDiv2 {
public:
    int countSupervisors(vector<int> students, int Y, int J) {
        int minCount=1000000, t;
        for (int i=0; i<students.size(); i++) {
            t = students[i];
            students[i] -= Y;
            if (students[i]<0) students[i] = 0;
            int count=0;
            for (int j=0; j<students.size(); j++) {
                count += students[j]/J + (students[j]%J!=0 ? 1:0);
            }

            students[i] = t;

            if (count<minCount) minCount=count;
        }
        return minCount;
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
            int students[] = {10, 15};
            int Y = 12;
            int J = 5;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = TheJediTestDiv2().countSupervisors(vector<int>(students, students + (sizeof students / sizeof students[0])), Y, J);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int students[] = {11, 13, 15};
            int Y = 9;
            int J = 5;
            int expected_ = 7;

            clock_t start_           = clock();
            int received_ = TheJediTestDiv2().countSupervisors(vector<int>(students, students + (sizeof students / sizeof students[0])), Y, J);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int students[] = {10};
            int Y = 100;
            int J = 2;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = TheJediTestDiv2().countSupervisors(vector<int>(students, students + (sizeof students / sizeof students[0])), Y, J);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int students[] = {0, 0, 0, 0, 0};
            int Y = 145;
            int J = 21;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = TheJediTestDiv2().countSupervisors(vector<int>(students, students + (sizeof students / sizeof students[0])), Y, J);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int students[] = {4, 7, 10, 5, 6, 55, 2};
            int Y = 20;
            int J = 3;
            int expected_ = 26;

            clock_t start_           = clock();
            int received_ = TheJediTestDiv2().countSupervisors(vector<int>(students, students + (sizeof students / sizeof students[0])), Y, J);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: TheJediTestDiv2.exe -2 <TheJediTestDiv2IO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> students;
        int students_sin;
        int Y;
        int J;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            students.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>students_sin; std::cin.ignore(10, '\n');
                students.push_back(students_sin);
            }
            std::cin>>Y; std::cin.ignore(10, '\n');
            std::cin>>J; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = TheJediTestDiv2().countSupervisors(students, Y, J);
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
