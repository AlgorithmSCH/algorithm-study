# 문제-2178 미로 탐색

- queue를 이용한 bfs 알고리즘 문제
- 미로의 최소 경로를 찾기 위해 bfs 알고리즘을 사용한다.

- 미로의 최소의 경로를 찾는 것이기 때문에, 모든 경로를 하나씩 탐색하며 출구가 탐색되면 그 즉시 bfs를 종료하며, 그 때의 count가 답이 된다.

- 우선 queue를 이용하여 bfs를 구현해준다.
  - 여기서 미로는 2중 배열로 이루어져있기 때문에 상하좌우 (최대 4곳)을 탐색하여 갈 수 있다면 queue에 push하는 형식으로 구현해준다.  

```C
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
```

- 위와 같이 bfs를 구현해준다.
  - 미로의 시작점은 항상 (1,1)이기 떄문에, 1,1을 queue에 push 해주고, arr에 1,1은 2로 바꿔준 뒤 실행한다.
  - 배열의 상하좌우가 0 또는 2일 경우 이미 방문했거나 벽이기 때문에, 못가게 한다.

- 위 규칙을 따라서 bfs 함수를 구현해준다.
- 아래는 main 함수이다.

```C
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
```
