#include <iostream>
using namespace std;

int main() {
	//최대 10000까지~
	bool check[10001] = { false };
	int num;
	int temp;

	//체크된거는 continue
	//체크 안된거는 확인
	for (int n = 1; n < 10001; n++) {
		num = n;
		temp = n;
		if (check[n] == true) {
			continue;
		}

		while (1) {
			//n의 셀프넘버를 확인
			//10000을 넘으면 break
			//넘지않으면 체크
			while (1) {
				num += (temp % 10);
				temp /= 10;
				if (temp == 0)
					break;
			}
			if (num > 10000)
				break;
			check[num] = true;
			temp = num;
		}
	}
	//출력
	for (int i = 1; i <= 10000; i++) {
		if (check[i] == false)
			cout << i << endl;
	}


	return 0;
}