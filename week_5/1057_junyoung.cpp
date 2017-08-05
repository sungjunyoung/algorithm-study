//
// Created by 성준영 on 2017. 8. 1..
//

#include <iostream>

using namespace std;

void fight(int *arr, int size, int a, int b, int &count) {
//    //TEST
//    for (int i = 1; i <= size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;

    count++;

    bool isOdd = false;
    if (size % 2 == 1) { // 대결자가 홀수이면
        size -= 1;
        isOdd = true;
    }

    int k = 1;
    for (int i = 1; i <= size; i += 2) {
        if (arr[i] == a && arr[i + 1] == b || arr[i] == b && arr[i + 1] == a) {
            cout << count;
            return;
        } else if (arr[i] == a || arr[i + 1] == a) {
            arr[k] = a;
        } else if (arr[i] == b || arr[i + 1] == b) {
            arr[k] = b;
        } else {
            arr[k] = arr[i];
        }
        k++;
    }

    size /= 2;
    if (isOdd) {
        arr[size + 1] = arr[size * 2 + 1];
        size += 1;
    }

    fight(arr, size, a, b, count);
}

int main() {
    int arr[100001];
    for (int i = 1; i <= 100000; i++) {
        arr[i] = i;
    }

    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;

    int count = 0;
    fight(arr, n, a, b, count);
}