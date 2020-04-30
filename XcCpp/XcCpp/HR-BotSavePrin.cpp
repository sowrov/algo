//
//  HR-BotSavePrin.cpp
//  XcCpp
//
//  Created by Mahbub Mozadded on 27/04/2020.
//  Copyright © 2020 Mahbub Mozadded. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void printPath(string s, int n) {
    for(int i=0; i<n; i++) {
        cout<<s<<endl;
    }
}

void displayPathtoPrincess(int n, vector <string> grid){
    int px=-1, py=-1;
    int mx=-1, my=-1;
    //your logic here
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].length(); j++) {
            if(grid[i][j]=='m') {
                mx=j; my=i;
            } else if(grid[i][j] == 'p') {
                px=j; py=i;
            }
        }
    }
    
//    cout<<px<<" "<<py<<endl;
//    cout<<mx<<" "<<my<<endl;
    
    if(px<mx) {//left
        printPath("LEFT", mx);
        if(py<my) {//top
            printPath("UP", my);
        } else if(py>my) { //down
            printPath("DOWN", py-my);
        }
    } else if(px>mx) {
        printPath("RIGHT", n-mx-1);
        if(py<my) {//top
            printPath("UP", my);
        } else if(py>my) { //down
            printPath("DOWN", py-my);
        }
    } else {
        if(py<my) {//top
            printPath("UP", my);
        } else if(py>my) { //down
            printPath("DOWN", n-my-1);
        }
    }
}

int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }
    
//    for(string s:grid) {
//        cout<<s<<endl;
//    }

    displayPathtoPrincess(m,grid);

    return 0;
}
