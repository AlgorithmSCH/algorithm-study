# 문제-7568 덩치

- 단순 구현 문제이다.

- 사람들의 몸무게와 키를 읽어온 후, 비교하여 순서대로 순위를 출력해주는 문제이다.
- vector<pair<int,int>>를 이용해 풀어낸 문제이다.

- 벡터에 저장을 해준 뒤, bf 알고리즘을 이용하여 순위를 매겨주었다.
```C
int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		arr[i] = 1;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i].first > v[j].first && v[i].second > v[j].second) {
				arr[j]++;
			}
			else if (v[i].first < v[j].first && v[i].second < v[j].second) {
				arr[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
```
