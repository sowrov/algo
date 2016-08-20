/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QuickSort.cpp
 * Author: home
 *
 * Created on March 20, 2016, 8:23 PM
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
void quick_sort(int s, int e) {
    if (s>=e) return;
    
    int p=arr[s];
    int i=s+1;
    while(i<=e && arr[i]<p) i++;
    if (i>e) {
        arr[s] = arr[e];
        arr[e] = p;
        quick_sort(s, e-1);
        return;
    }
    for (int j=i+1; j<=e; j++) {
        if (arr[j]<=p) {
            int tmp = arr[j];
            arr[j] = arr[i];
            arr[i] = tmp;
            i++;
        }
    }
    int tmp=arr[s];
    arr[s] = arr[i-1];
    arr[i-1] = tmp;
    quick_sort(s, i-2);
    quick_sort(i, e);
}
int main() {
    int t;
    int n,v;
    cin>>t;
    while(t-->0) {
        cin>>n;
        arr.clear();
        for (int i=0; i<n; i++) {
            cin>>v;
            arr.push_back(v);
        }
        quick_sort(0, arr.size()-1);
        for (int i=0; i<arr.size(); i++) {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
