//
// Created by 성준영 on 2017. 7. 02..
//


#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int start, end;
        cin >> start >> end;
        int term = end - start;

        // 간격 차이가 1이면 그냥 1 출력
        if (term == 1) {
            cout << 1 << endl;
            continue;
        }

        unsigned int iter; // 배수만큼 계속 증가
        int result;
        int count = 2;
        // 돌면서 제곱수 찾기
        while (1) {
            iter = (unsigned int) (count * count);
            count++;
            if (iter >= term) {
                break;
            }
        }
        // 한번 더 돈거 복구
        count -= 1;
        iter = (unsigned int) (count * count);

        // 사이 간격에서의 중간
        int mid = iter - count;
        // 결과 이전 (그대로이거나 -1 이 될 수 있음)
        int preResult = count + (count -1);

        if(term <= mid){
            result = preResult -1;
        } else {
            result = preResult;
        }

        cout << result << endl;
    }
}