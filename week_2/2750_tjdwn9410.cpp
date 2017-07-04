//
// Created by MAC on 2017. 7. 4..
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int N;
    int *arr;
    cin >> N;
    arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < N; i++)
        cout << arr[i] << endl;
    delete arr;
    return 0;
}