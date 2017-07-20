#include <iostream>
#include <vector>
using namespace std;

#define MAX_NUM 500
int table[MAX_NUM + 1][MAX_NUM + 1];

int main() {

    int testCase;
    cin >> testCase;

    int num;
    int inputData;

    while (testCase--) {
        cin >> num;
        vector<int> array;
        vector<int> sum;

        array.push_back(0);
        sum.push_back(0);

        for (int i = 1; i <= num; ++i) {
            cin >> inputData;
            array.push_back(inputData);
            if (i > 1) sum.push_back(sum[i - 1] + inputData);
            else sum.push_back(inputData);
        }

        int ret;
        for (int i = 1; i < num; ++i) {
            for (int j = i + 1; j <= num; ++j) {
                ret = 2100000000;

                for (int k = j - i; k < j; ++k)
                    ret = min(ret, table[j - i][k] + table[k + 1][j] + sum[j] - sum[j - i - 1]);

                table[j - i][j] = ret;
            }
        }
        cout << table[1][num] << endl;
    }

    return 0;
}