#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n, m;
int maze[101][101];
queue<tuple<int, int, int>> q;

int bfs() {
	int x = 1, y = 1, cnt = 1;
	while ((x != n && y != m) || !q.empty()) {
		q.pop();
		if (maze[x][y + 1] == 1) { q.push(make_tuple(x, y + 1, cnt + 1)); maze[x][y + 1] = 2; }
		if (maze[x + 1][y] == 1) { q.push(make_tuple(x + 1, y, cnt + 1)); maze[x + 1][y] = 2; }
		if (maze[x][y - 1] == 1) { q.push(make_tuple(x, y - 1, cnt + 1)); maze[x][y - 1] = 2; }
		if (maze[x - 1][y] == 1) { q.push(make_tuple(x - 1, y, cnt + 1)); maze[x - 1][y] = 2; }
		if (get<0>(q.front()) == n && get<1>(q.front()) == m) { return get<2>(q.front()); }
		x = get<0>(q.front()), y = get<1>(q.front()), cnt = get<2>(q.front());
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
			maze[i][j] = s[j - 1] - 48;
	}

	q.push(make_tuple(1, 1, 1));
	maze[1][1] = 2;

	cout << bfs();
}