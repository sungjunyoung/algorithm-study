//
// Created by MAC on 2017. 7. 12..
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int N;
    int arr[100100];
    int resultArr[100100];
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    resultArr[0] = arr[0];
    for (int i = 1; i < N; i++) {
        if (resultArr[i - 1] + arr[i] > arr[i])
            resultArr[i] = resultArr[i - 1] + arr[i];
        else
            resultArr[i] = arr[i];
    }
    int max = -2147483647;
    for (int i = 0; i < N; i++) {
        //cout << resultArr[i] << " ";
        if(max <resultArr[i])
            max =resultArr[i];
    }
    cout<<max<<endl;
    return 0;
}