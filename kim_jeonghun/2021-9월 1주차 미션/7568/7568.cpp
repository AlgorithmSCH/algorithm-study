#include<iostream>
#include<vector>
using namespace std;

vector <pair<int, int>> v;
int arr[50];

int main() {
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
}