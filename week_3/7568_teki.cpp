#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	pair<int, int> arr[50];
	int rank[50][2] = {0};
	pair<int, int> temp;
	for (int i = 0; i < N; i++) {
		cin >> temp.first >> temp.second;
		arr[i] = temp;
	}
	//자기보다 작은 덩치의 명수를 센다
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i].first > arr[j].first && arr[i].second > arr[j].second)
				rank[j][0]++;
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
				rank[i][0]++;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << rank[i][0]+1 << " ";
	}
	cout << endl;
	return 0;
}