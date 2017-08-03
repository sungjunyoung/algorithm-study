#include <iostream>
#include <vector>
using namespace std;
vector<int> histograms;

long long recursiveHistogram(int left, int right)
{
    if(left == right)   return histograms[left];

    int mid = (right + left) / 2;
    int leftPoint = mid;
    int rightPoint = mid + 1;
    long long height = min(histograms[leftPoint], histograms[rightPoint]);
    long long ret = max(recursiveHistogram(left, mid), recursiveHistogram(mid + 1, right));
    ret = max(ret, height * 2);
    while (left < leftPoint || rightPoint < right) {
        if(left < leftPoint && (histograms[leftPoint - 1] > histograms[rightPoint+1] || rightPoint == right)) {
            leftPoint--;
            height = min(histograms[leftPoint], (const int &) height);
        }
        else {
            rightPoint++;
            height = min( (const int &) height,histograms[rightPoint]);
        }
        ret = max(ret, height * (rightPoint - leftPoint + 1));
    }
    return ret;
}

int main() {

    int input;
    int num;
    while (true)
    {
        cin >> input;
        if(input == 0)  break;
        for (int i = 0; i < input; ++i) {
            cin >> num;
            histograms.push_back(num);
        }
        cout << recursiveHistogram(0, (int) (histograms.size() - 1)) << endl;
        histograms.clear();
    }

    return 0;
}