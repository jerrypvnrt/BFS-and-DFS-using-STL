#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[6];
bool dfs_used[6] = { 0 };
void dfs(int id) {
	cout << id << " ";
	for (int i = 0; i < a[id].size(); ++i) {
		if (!dfs_used[a[id][i]]) {
			dfs_used[a[id][i]] = 1;
			dfs(a[id][i]);
		}
	}
}

int main() {
	for (int i = 0; i < 7; ++i) {
		int x, y; cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i < 6; ++i) {
		cout << i << ": ";
		for (int j = 0; j < a[i].size(); ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	dfs_used[1] = 1;
	dfs(1); cout << endl;
	bool used[6] = { 0 };
	queue<int> bfs;
	bfs.push(1);
	used[1] = 1;
	while (!bfs.empty()) {
		int x = bfs.front();
		cout << x << " ";
		for (int i = 0; i < a[x].size(); ++i) {
			if (used[a[x][i]]) continue;
			bfs.push(a[x][i]);
			used[a[x][i]] = 1;
		}
		bfs.pop();
	}
	cout << endl;
}
