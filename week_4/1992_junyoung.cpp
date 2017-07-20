#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int checkImage(vector<vector<int> > &image, int x, int y, int size) {
    int checkNum = image[x][y];
    for (int i = x; i < size + x; i++) {
        for (int j = y; j < size + y; j++) {
            if (checkNum != image[i][j]) {
                checkNum = -1;
                break;
            }
        }
        if (checkNum == -1) break;
    }

    return checkNum;

}


void quadTree(vector<vector<int> > &image, int x, int y, int size) {

    int check = checkImage(image, x, y, size);
    if (check != -1) {
        printf("%d", check);
        return;
    } else {
        printf("(");
        quadTree(image, x, y, size/2);
        quadTree(image, x, y + size/2 , size/2);

        quadTree(image, x + size/2, y, size/2);
        quadTree(image, x + size/2, y + size/2, size/2);
    }

    printf(")");
    return;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int> > image(n+1);
    for (int i = 1; i <= n; i++) {
        image[i].resize(n);
    }
    // 이미지 입력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &image[i][j]);
        }

    }

    quadTree(image,1, 1, n);


}

