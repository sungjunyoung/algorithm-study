//
// Created by 성준영 on 2017. 7. 18..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums;
    nums.resize(9);
    int overSum = 0;
    for (int i = 1; i <= 9; i++) {
        cin >> nums[i];
        overSum += nums[i];
    }

    overSum -= 100;
    sort(nums.begin(), nums.end());
    vector<int> overs;
    for (int i = 1; i <= 8; i++) {
        for (int j = i + 1; j <= 9; j++) {
            int tempSum = nums[i] + nums[j];
            if (tempSum == overSum) {
                overs.push_back(i);
                overs.push_back(j);
            }
        }
    }

    vector<int> results;
    for (int i = 1; i <= 9; i++) {
        int isOver = false;
        for (int j = 0; j < 2; j++) {
            if(nums[overs[j]] == nums[i]){
                isOver = true;
            }
        }
        if(!isOver){
            results.push_back(nums[i]);
        }
    }

    sort(results.begin(), results.end());
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
}
