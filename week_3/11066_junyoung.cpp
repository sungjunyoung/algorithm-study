#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> chapters, int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += chapters[i];
    }
    return sum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        vector<int> chapters;

        chapters.resize((unsigned long) (k + 1));
        for (int i = 1; i <= k; i++) {
            cin >> chapters[i];
        }

        vector<vector<int> > D;
        D.resize((unsigned long) (k + 1));
        for (int i = 0; i <= k; i++) {
            D[i].resize((unsigned long) (k + 1));
        }

        // 기저값
        for (int i = 1; i <= k; i++) {
            D[i][i] = 0;
        }

        for (int i = 2; i <= k; i++) {
            for (int j = 1; j <= k - i + 1; j++) {
                // D[j][j+i-1] 를 구해야

                D[j][j + i - 1] = D[j][j] + D[j + 1][j + i - 1];
                for (int x = j; x < j + i - 1; x++) {
                    D[j][j + i - 1] = min(D[j][j + i - 1], D[j][x] + D[x + 1][j + i - 1]);
                }
                D[j][j + i - 1] += sum(chapters, j, j + i - 1);
            }
        }

        cout << D[1][k] << endl;
    }
}
