#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct node{
    int num;
    int index;
};

bool compare(const node &first, const node &second)
{
    return first.num < second.num;
}

int main() {
    int n;
    int testCase;
    int startPoint;
    int endPoint;
    int outputPoint;

    cin >> n >> testCase;
    vector<node> numArray;
    node input;

    for (int i = 0; i < n ; i++) {
        cin>>input.num;
        input.index = i;
        numArray.push_back(input);
    }

    sort(numArray.begin(), numArray.end(), compare);

    int count;
    while(testCase--) {
        cin>>startPoint >> endPoint >> outputPoint;
        count = 0;

        for (int i = 0; i < numArray.size(); ++i) {
            if(startPoint - 1 <= numArray[i].index && numArray[i].index <= endPoint - 1)
                count++;
            if(count == outputPoint)
            {
                cout<<numArray[i].num<<endl;
                break;
            }
        }

    }
}