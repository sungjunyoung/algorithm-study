#include <iostream>
#include <algorithm>
using namespace std;
struct _a {
	int num;
	int index;
};

bool com(_a A, _a B) {
	return A.num < B.num;
}

_a a[100000];
int temp[100000];
int main() {
	int size;
	int caseNum;
	cin >> size >> caseNum;
	//num,index 설정
	for (int i = 0; i < size; i++) {
		cin>>a[i].num;
		a[i].index = i + 1;
	}
	//struct의  num을 기준으로 정렬
	sort(a, a + size, com);
	int i, j, k;
	int cnt;
	while (caseNum--) {
		cnt = 0;
		cin >> i >> j >> k;
		//a[l]의 index가 i<= index <=j 이면 cnt++
		//cnt==k이면 출력
		for (int l = 0; l < size; l++) {
			if (a[l].index >= i &&a[l].index <= j) {
				cnt++;
				if (cnt == k) {
					cout << a[l].num<<endl;
					break;
				}
			}
		}
	}
	return 0;
}