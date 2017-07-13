//
// Created by MAC on 2017. 7. 13..
//

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

int arr[3000010];
int main() {
    int N;
    cin>>N;
    for(int i = 1 ; i <=N ;i++)
    {
        if(arr[i+1] == 0 || arr[i+1] > arr[i]+1)
            arr[i+1]=arr[i]+1;
        if(arr[i*2] == 0 || arr[i*2] > arr[i]+1)
            arr[i*2]=arr[i]+1;
        if(arr[i*3] == 0 || arr[i*3] > arr[i]+1)
            arr[i*3]=arr[i]+1;
    }
    cout<<arr[N]<<endl;
    return 0;
}