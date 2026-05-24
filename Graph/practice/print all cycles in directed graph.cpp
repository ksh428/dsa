#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

vector<int>adj[100001];

void dfs(int u, int p, int color[], int parent[], int &cycleno, map<int, vector<int>>&m) {
	color[u] = 1;
	for (int j : adj[u]) {
		if (j == p) continue;
		if (color[j] == 2) continue;
		if (color[j] == 1) {
			int curr = u;
			cycleno++;
			while (curr != j) {
				m[cycleno].push_back(curr);
				curr = parent[curr];
			}
			m[cycleno].push_back(j);
			continue;
		}
		parent[j] = u;
		dfs(j, u, color, parent, cycleno, m);

	}
	color[u] = 2;
}

void solve() {
	int n = 7;
	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[1].push_back(4);
	adj[4].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(2);
	adj[4].push_back(3);
	adj[3].push_back(4);
	adj[4].push_back(5);
	adj[5].push_back(4);
	adj[5].push_back(2);
	adj[2].push_back(5);
	int color[n + 1];
	memset(color, 0, sizeof(color));
	int parent[n + 1];
	parent[1] = 0;
	map<int, vector<int>>m;
	int cno = 0;
	dfs(1, 0, color, parent, cno, m);
	for (auto it : m) {
		cout << it.first << " ->";
		for (auto x : it.second) cout << x << " ";
		cout << endl;
	}

}


int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
