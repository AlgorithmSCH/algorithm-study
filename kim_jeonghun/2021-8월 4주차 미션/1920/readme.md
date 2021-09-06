# 문제-1920 수 찾기
- 이분 탐색 알고리즘 응용의 기본적인 문제이다.

- left, right, mid를 구현해주어 이분 탐색 알고리즘을 활용한다.

- 우선 비교할 수가 저장할 vector와, 주어진 수를 저장할 vector 총 두개를 선언하여 넣고 첫번째 vector만 정렬해준다.

- 이후 이분탐색을 통해 두번째 vector에 있는 인수를 첫번째의 수와 비교하며 없으면 0을 있으면 1을 출력해준다. 
	- left=공간의 최소값, right=공간의 최대값, mid= (left+right)/2
	- value>mid => left=mid+1
	- value<mid => right=mid-1
	- 다음 규칙을 구현해준다.
```C
	int n, tmp;
	vector<int> v1, v2;
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> tmp; v1.push_back(tmp); }
	sort(v1.begin(), v1.end());
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> tmp; v2.push_back(tmp); }

	for (int i = 0; i < v2.size(); i++) {
		int left=0, right=v1.size()-1, mid, answer = 0;
		while (left <= right) {
			mid = (right + left) / 2;
			if (v2[i] > v1[mid])
				left = mid + 1;
			else if (v2[i] < v1[mid])
				right = mid - 1;
			else
			{
				answer = 1; break;
			}
		}
		cout << answer << '\n';
	}
```
