#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int> &numList, int start, int end) {
    int pivot = start;

    int i = start;
    int j = end;

    if(start < end){

        do {
            while (numList[i] < numList[pivot]) {
                i++;
            }
            while (numList[j] > numList[pivot]) {
                j--;
            }

            int temp = numList[i];
            numList[i] = numList[j];
            numList[j] = temp;

        } while (i < j);

        int temp = numList[j];
        numList[j] = numList[pivot];
        numList[pivot] = temp;

        quicksort(numList, start, j - 1);
        quicksort(numList, j + 1, end);
    } else {
        return;
    }
}


int main() {
    int n;
    cin >> n;

    vector<int> numList;
    for (int i = 1; i <= n; i++) {
        int tempNum;
        cin >> tempNum;
        numList.push_back(tempNum);
    }

    quicksort(numList, 0, numList.size() - 1);

    for (int i = 0; i < n; i++) {
        cout << numList[i] << endl;
    }
}