#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &array, int start, int end) {
    if (start > end) return;

    int pivot = start;
    int left = start + 1;
    int right = end;

    while (left <= right) {
        while (array[pivot] < array[right])
            right--;

        while (array[left] < array[pivot])
            left++;

        if (left < right)
            swap(array[left], array[right]);
        else
            break;
    }
    swap(array[pivot], array[right]);

    quickSort(array, start, right - 1);
    quickSort(array, right + 1, end);

}


int main()
{
    int N;
    cin>>N;
    vector<int> array;
    int input;
    for (int i = 0; i < N; ++i) {
        cin>>input;
        array.push_back(input);
    }

    quickSort(array, 0, array.size() - 1);

    for (int i = 0; i < N; ++i)
        cout<<array[i]<<endl;

    return 0;
}