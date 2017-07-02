//
// Created by 성준영 on 2017. 7. 02..
//

#include <iostream>

using namespace std;

void makeShape(int width, int height, char **preShape,int n) {
    // 모양을 보면 이전 모양을 아래 왼쪽 아래 오른쪽에 붙이는 것을 알 수 있음

    if (height == n) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << preShape[i][j];
            }
            cout << endl;
        }
        return;
    }

    int nextWidth = width * 2 + 1;
    int nextHeight = height * 2;

    char **shape;
    //다음 만들어질 모양 선언 및 초기화
    shape = new char *[nextHeight];
    for (int i = 0; i < nextHeight; i++) {
        shape[i] = new char[nextWidth];
    }
    for (int i = 0; i < nextHeight; i++) {
        for (int j = 0; j < nextWidth; j++) {
            shape[i][j] = ' ';
        }
    }

    // 가운데 넣기
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            shape[i][nextHeight / 2 + j] = preShape[i][j];
        }
    }

    // 아래 왼쪽에 넣기
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            shape[height + i][j] = preShape[i][j];
        }
    }

    // 아래 오른쪽에 넣기
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            shape[height + i][nextHeight + j] = preShape[i][j];
        }
    }

    makeShape(nextWidth, nextHeight, shape, n);

}

int main() {
    int n;
    cin >> n;

    // 초기 모양 (n=3 일때) 를 만들어줌
    char **initShape;
    initShape = new char *[3];
    for (int i = 0; i < 3; i++) {
        initShape[i] = new char[5];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            initShape[i][j] = ' ';
        }
    }
    initShape[0][2] = '*';
    initShape[1][1] = '*';
    initShape[1][3] = '*';
    for (int i = 0; i < 5; i++) {
        initShape[2][i] = '*';
    }

    makeShape(5, 3, initShape, n);
}