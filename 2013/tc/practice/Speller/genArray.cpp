#include <stdio.h>
#include <string>
using namespace std;


int main() {
    string ones[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string teen[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    for (int i=0; i<8; i++) {
        for(int j=0; j<9; j++) {
            printf("%s-%s\", \"", tens[i].c_str(), ones[j].c_str());
        }
    }
    return 0;
}
