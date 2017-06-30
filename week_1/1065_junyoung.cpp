#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    // 개수 새는 카운터
    int count = 0;

    for (int i = 1; i <= n; i++) {
        int tempI = i;
        // 각각 자리수를 저장
        vector<int> numbers;
        while (tempI > 0) {
            numbers.push_back(tempI % 10);
            tempI = tempI / 10;
        }

        bool check = true;
        // 초기 자리수 차이 저장
        int sub = numbers[1]-numbers[0];
        for (int j = 1; j < numbers.size(); j++) {
            int tempSub = numbers[j] - numbers[j-1];
            // 비교 후 체크
            if(sub != tempSub){
                check = false;
                continue;
            }
        }

        if(check){
            count++;
        }
    }

    cout << count << endl;
}