#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int mat[1001][1001];
int dist[1001];
bool vis[1001];

void bfs(int s, int n) {
	queue<int> qu;
	qu.push(s);
	dist[s] = 0;
	while (!qu.empty()) {
		int v = qu.front();
		//vis[v] = true;
		qu.pop();
		for (int i = 0; i < n; i++) {
			if (mat[v][i] != -1 && (dist[v]+mat[v][i]<dist[i] || dist[i]==-1 )  ) {
				dist[i] = dist[v] + mat[v][i];
				qu.push(i);
			}
		}
	}
}
int main() {
	int n, m, t, x, y, s;
	cin >> t;
	while (t-->0) {
		memset(mat, -1, sizeof(mat));
		memset(dist, -1, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			mat[x-1][y-1] = 6;
			mat[y-1][x-1] = 6;
		}
		cin >> s;
		
		bfs(s-1, n);
		bool ws = false;
		for (int i = 0; i < n; i++) {
			if (i == s-1) continue;
			if (ws) cout << " ";
			cout << dist[i];
			ws = true;
		}
		cout << endl;
	}
	return 0;
}
