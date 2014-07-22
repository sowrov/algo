#include "iomanip"
#include "utility"
#include "ctime"
#include "numeric"
#include "map"
#include "set"
#include "cctype"
#include "cmath"
#include "cstdlib"
#include "functional"
#include "cstring"
#include "stack"
#include "cassert"
#include "list"
#include "sstream"
#include "cstdio"
#include "bitset"
#include "deque"
#include "iostream"
#include "queue"
#include "string"
#include "algorithm"
#include "vector"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class MessageMess {
public:
    string restore(vector<string> dictionary, string message) {
        string out[52], str;
        int flag[52];
        Zclr(flag);
        map<string, bool> dmap;

        for (int i=0; i<dictionary.size(); i++) {
            dmap[dictionary[i]]=true;
        }

        out[0]="";
        flag[0]=1;

        for (int i=0; i<message.length(); i++) {
            if(flag[i]>0) {
                for (int j=i+1; j<=message.length(); j++) {
                    str = message.substr(i, j-i);

                    if (dmap.find(str)!=dmap.end()) {
                        flag[j] = flag[j]==0 ? flag[i] : flag[j]+1;

                        if (flag[j]==1) {
                            out[j] = out[i];
                            if(!out[j].empty()) out[j]+= " ";
                            out[j] += str;
                        }
                    }
                }
            }
        }
        
        if (flag[message.length()]==0) {
            return "IMPOSSIBLE!";
        } else if (flag[message.length()]>1) {
            return "AMBIGUOUS!";
        }
        return out[message.length()];
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
            string dictionary[] = {"HI", "YOU", "SAY"};
            string message = "HIYOUSAYHI";
            string expected_ = "HI YOU SAY HI";

            clock_t start_           = clock();
            string received_ = MessageMess().restore(vector <string>(dictionary, dictionary + (sizeof dictionary / sizeof dictionary[0])), message);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string dictionary[] = {"ABC", "BCD", "CD", "ABCB"};
            string message = "ABCBCD";
            string expected_ = "AMBIGUOUS!";

            clock_t start_           = clock();
            string received_ = MessageMess().restore(vector <string>(dictionary, dictionary + (sizeof dictionary / sizeof dictionary[0])), message);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string dictionary[] = {"IMPOSS", "SIBLE", "S"};
            string message = "IMPOSSIBLE";
            string expected_ = "IMPOSSIBLE!";

            clock_t start_           = clock();
            string received_ = MessageMess().restore(vector <string>(dictionary, dictionary + (sizeof dictionary / sizeof dictionary[0])), message);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string dictionary[] = {"IMPOSS", "SIBLE", "S", "IMPOSSIBLE"};
            string message = "IMPOSSIBLE";
            string expected_ = "IMPOSSIBLE";

            clock_t start_           = clock();
            string received_ = MessageMess().restore(vector <string>(dictionary, dictionary + (sizeof dictionary / sizeof dictionary[0])), message);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: MessageMess.exe -2 <MessageMess.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector <string> dictionary;
        string dictionary_sin;
        string message;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            dictionary.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,dictionary_sin );
                dictionary.push_back(dictionary_sin);
            }
            std::getline(std::cin,message);
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = MessageMess().restore(dictionary, message);
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
