#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void cut(vector<vector<int> > paper, int *result) {
    if (paper[1].size() == 2) {
        result[paper[1][1] + 1]++;
        return;
    }

    int flag = true;
    int init = paper[1][1];
    for (int i = 1; i < paper[1].size(); i++) {
        for (int j = 1; j < paper[1].size(); j++) {
            if (init != paper[i][j]) {
                flag = false;
                break;
            }
        }
        if (flag == false) {
            break;
        }
    }

    if (flag == false) {
        // 나눠서 재호출
        vector<vector<int> > cutPaper;
        cutPaper.resize((paper.size() - 1) / 3 + 1);
        for (int i = 1; i < cutPaper.size(); i++) {
            cutPaper[i].resize((paper.size() - 1) / 3 + 1);
        }

        for (int i = 1; i <= (paper.size() - 1) / 3; i++) {
            for (int j = 1; j <= (paper.size() - 1) / 3; j++) {
                cutPaper[i][j] = paper[i][j];
            }
        }
        cut(cutPaper, result);
        for (int i = 1; i <= (paper.size() - 1) / 3; i++) {
            for (int j = 1; j <= (paper.size() - 1) / 3; j++) {
                cutPaper[i][j] = paper[i][j + (paper.size() - 1) / 3];
            }
        }
        cut(cutPaper, result);
        for (int i = 1; i <= (paper.size() - 1) / 3; i++) {
            for (int j = 1; j <= (paper.size() - 1) / 3; j++) {
                cutPaper[i][j] = paper[i][j + 2 * ((paper.size() - 1) / 3)];
            }
        }
        cut(cutPaper, result);
        for (int i = 1; i <= (paper.size() - 1) / 3; i++) {
            for (int j = 1; j <= (paper.size() - 1) / 3; j++) {
                cutPaper[i][j] = paper[i + (paper.size() - 1) / 3][j];
            }
        }
        cut(cutPaper, result);
        for (int i = 1; i <= (paper.size() - 1) / 3; i++) {
            for (int j = 1; j <= (paper.size() - 1) / 3; j++) {
                cutPaper[i][j] = paper[i + (paper.size() - 1) / 3][j + (paper.size() - 1) / 3];
            }
        }

        cut(cutPaper, result);
        for (int i = 1; i <= (paper.size() - 1) / 3; i++) {
            for (int j = 1; j <= (paper.size() - 1) / 3; j++) {
                cutPaper[i][j] = paper[i + (paper.size() - 1) / 3][j + 2 * ((paper.size() - 1) / 3)];
            }
        }

        cut(cutPaper, result);
        for (int i = 1; i <= (paper.size() - 1) / 3; i++) {
            for (int j = 1; j <= (paper.size() - 1) / 3; j++) {
                cutPaper[i][j] = paper[i + 2 * ((paper.size() - 1) / 3)][j];
            }
        }

        cut(cutPaper, result);
        for (int i = 1; i <= (paper.size() - 1) / 3; i++) {
            for (int j = 1; j <= (paper.size() - 1) / 3; j++) {
                cutPaper[i][j] = paper[i + 2 * ((paper.size() - 1) / 3)][j + (paper.size() - 1) / 3];
            }
        }

        cut(cutPaper, result);
        for (int i = 1; i <= (paper.size() - 1) / 3; i++) {
            for (int j = 1; j <= (paper.size() - 1) / 3; j++) {
                cutPaper[i][j] = paper[i + 2 * ((paper.size() - 1) / 3)][j + 2 * ((paper.size() - 1) / 3)];
            }
        }
        cut(cutPaper, result);
    } else {
        result[init + 1]++;
        return;
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int> > paper;
    paper.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        paper[i].resize(n + 1);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> paper[i][j];
        }
    }

    int result[] = {0, 0, 0};
    cut(paper, result);

    for (int i = 0; i < 3; i++) {
        cout << result[i] << endl;
    }

}

