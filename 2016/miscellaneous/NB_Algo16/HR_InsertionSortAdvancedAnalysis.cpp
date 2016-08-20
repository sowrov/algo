/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HR_InsertionSortAdvancedAnalysis.cpp
 * Author: home
 *
 * Created on March 19, 2016, 10:07 PM
 */

#include "iomanip"
#include "vector"
#include "utility"
#include "cstring"
#include "numeric"
#include "set"
#include "ctime"
#include "fstream"
#include "cstdlib"
#include "bitset"
#include "cctype"
#include "map"
#include "algorithm"
#include "cassert"
#include "cstdio"
#include "string"
#include "list"
#include "sstream"
#include "iostream"
#include "deque"
#include "stack"
#include "cmath"
#include "queue"
#include "functional"
#include "climits"

using namespace std;

#define clr0(_arr) memset(_arr, 0, sizeof(_arr))
#define clr1(_arr) memset(_arr, -1, sizeof(_arr))
//INT_MAX, LONG_MAX, ULONG_MAX
#define BIG INT_MAX
#define PI (2.0*acos(0.0))
#define Eps (1e-9)
vector<int> arr;

long long merge_sort_insertionCount(int low, int hig) {
    if (low==hig) {
        return 0;
    }
    int mid = (low+hig)/2;
    long long c;
    vector<int> mrg;
    c = merge_sort_insertionCount(low, mid);
    c +=merge_sort_insertionCount(mid+1, hig);
    int i=low, j=mid+1;
    while(i<=mid && j<=hig) {
        if (arr[i]<=arr[j]) {
            mrg.push_back(arr[i]);
            i++;
        } else {
            c += mid-i+1;
            mrg.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid) {
        mrg.push_back(arr[i++]);
    }
    while(j<=hig) {
        mrg.push_back(arr[j++]);
    }
    for (int k=0; k<mrg.size(); k++) {
        arr[low+k] = mrg[k];
    }
    return c;
}

int main() {
    int t;
    int n, v;
    long long out;
    
    cin>>t;
    while (t-- > 0) {
        cin>>n;
        out = 0;
        arr.clear();
        for (int i = 0; i < n; i++) {
            cin>>v;
            arr.push_back(v);
        }
        out = merge_sort_insertionCount(0, arr.size()-1);
        cout << out << endl;
    }
    return 0;
}
