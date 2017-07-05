#include <iostream>
#include <string>
using namespace std;

int main() {
	int caseNum;												//test case 개수
	cin >> caseNum;										
	string input;												//input string 			
	int cnt;													//연속된 O개수 
	int score;													//점수
	while (caseNum--) {
		cin >> input;											
		
		cnt = 1;												//cnt,score 초기화
		score = 0;

		for (int i = 0; i < input.size(); i++) {				//input string의 끝까지 반복
			if (input[i] == 'O') {								//input[i]가  'O'이면 score에 cnt만큼 추가하고 cnt++
				score += cnt;					
				cnt++;
			}

			else {												//X이면 cnt = 1
				cnt = 1;
			}

		}
		cout << score << endl;
	}

	return 0;
}