#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int mat[3001][3001];
int dist[3001];

void bfs(int s, int n) {
	queue<int> qu;
	qu.push(s);
	dist[s] = 0;
	while (!qu.empty()) {
		int v = qu.front();
		//vis[v] = true;
		qu.pop();
		for (int i = 0; i < n; i++) {
			if (mat[v][i] != -1 && (dist[v] + mat[v][i]<dist[i] || dist[i] == -1)) {
				dist[i] = dist[v] + mat[v][i];
				qu.push(i);
			}
		}
	}
}
int main() {
	int n, m, t, x, y, s,v;
	cin >> t;
	while (t-->0) {
		memset(mat, -1, sizeof(mat));
		memset(dist, -1, sizeof(dist));
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> v;
			if (mat[x - 1][y - 1] == -1 || mat[x - 1][y - 1]>v) {
				mat[x - 1][y - 1] = v;
				mat[y - 1][x - 1] = v;
			}
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
