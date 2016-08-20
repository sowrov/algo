/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HR_ShortestReach.cpp
 * Author: home
 *
 * Created on March 21, 2016, 10:22 AM
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

int mat[1001][1001];
int dist[1001];

void bfs(int s, int n) {
    queue<int> qu;
    qu.push(s);
    dist[s] = 0;
    while (!qu.empty()) {
        int v = qu.front();
        qu.pop();
        for (int i = 0; i < n; i++) {
            if (mat[v][i] != -1 && (dist[v] + mat[v][i] < dist[i] || dist[i] == -1)) {
                dist[i] = dist[v] + mat[v][i];
                qu.push(i);
            }
        }
    }
}

int main() {
    int n, m, t, x, y, s;
    cin >> t;
    while (t-- > 0) {
        memset(mat, -1, sizeof (mat));
        memset(dist, -1, sizeof (dist));
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            mat[x - 1][y - 1] = 6;
            mat[y - 1][x - 1] = 6;
        }
        cin >> s;

        bfs(s - 1, n);
        bool ws = false;
        for (int i = 0; i < n; i++) {
            if (i == s - 1) continue;
            if (ws) cout << " ";
            cout << dist[i];
            ws = true;
        }
        cout << endl;
    }
    return 0;
}